#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <math.h>
#include <ctime> 
#include <climits>
#include <cmath>
#include <algorithm> // for std::find
#include <iterator> // for std::begin, std::end
#include <fstream>

//Compile using "g++ -O3 main.cpp"
//Run using "./a.out"

using namespace std;

int indexofSmallestElement(double array[], int size)
{
    int index = 0;

    for(int i = 1; i < size; i++)
    {
        if(array[i] < array[index])
            index = i;              
    }

    return index;
}

void plotPoints(double yCoordinates[], double xCoordinates[], int number, double minX, double minX2, double minY, double minY2){
  int pointNumbers[number];
  int imageArr[10000];
  for(int x = 0; x < number; x++){
    int yCoor = (int)100*yCoordinates[x];
    int xCoor = (int)100*xCoordinates[x];
    pointNumbers[x] =100*yCoor + xCoor;
  }
  //cout << (int)10000*minY + (int)100*minX << " " << (int)10000*minY2+(int)100*minX2;
  for(int i = 0; i < 10000; i++){
    imageArr[i] = 0;
    for(int a = 0; a < number; a++){
      if(pointNumbers[a] == i){
        imageArr[i] = 1;
      }
    }
  }

  //Bresenham Algorithm
  int x1 = (int)(100*minX);
  int x2 = (int)(100*minX2);
  int y1 = (int)(100*minY);
  int y2 = (int)(100*minY2);

   const bool steep = (fabs(y2 - y1) > fabs(x2 - x1));
    if(steep)
    {
      std::swap(x1, y1);
      std::swap(x2, y2);
    }
   
    if(x1 > x2)
    {
      std::swap(x1, x2);
      std::swap(y1, y2);
    }
   
    const float dx = x2 - x1;
    const float dy = fabs(y2 - y1);
   
    float error = dx / 2.0f;
    const int ystep = (y1 < y2) ? 1 : -1;
    int y = (int)y1;
   
    const int maxX = (int)x2;
   
    for(int x=(int)x1; x<maxX; x++)
    {
      if(steep)
      {
          imageArr[(100*x)+y] = 1;
      }
      else
      {
          imageArr[(100*y)+x] = 1;
      }
   
      error -= dy;
      if(error < 0)
      {
          y += ystep;
          error += dx;
      }
    }

  //Finding extremes and drawing a square
  int radius = 3;
  //Bottommost
  int indexOfBottomMost = indexofSmallestElement(yCoordinates, number);
  int yBottom = (int)100*yCoordinates[indexOfBottomMost];
  int xBottom = (int)100*xCoordinates[indexOfBottomMost];
  imageArr[100*yBottom + xBottom] = 2;
  for(int i = xBottom-radius; i <= xBottom+radius; i++){
      imageArr[100*(yBottom+radius) + i] = 1;
      imageArr[100*(yBottom-radius) + i] = 1;

  }
  for(int i = yBottom-radius; i <= yBottom+radius; i++){
      imageArr[100*(i) + xBottom+radius] = 1;
      imageArr[100*(i) + xBottom-radius] = 1;
  }

  //Leftmost
  int indexOfLeftMost = indexofSmallestElement(xCoordinates, number);
  int yLeft = (int)100*yCoordinates[indexOfLeftMost];
  int xLeft = (int)100*xCoordinates[indexOfLeftMost];
  imageArr[100*yLeft + xLeft] = 2;
  for(int i = xLeft-radius; i <= xLeft+radius; i++){
      imageArr[100*(yLeft+radius) + i] = 1;
      imageArr[100*(yLeft-radius) + i] = 1;

  }
  for(int i = yLeft-radius; i <= yLeft+radius; i++){
      imageArr[100*(i) + xLeft+radius] = 1;
      imageArr[100*(i) + xLeft-radius] = 1;
  }

  ofstream output;
  output.open("squarePoints.ppm");
  output << "P3 100 100 1";
  for(int i = 0; i < 10000; i++){
    if(i%100 == 0){
      output << '\n';
    }
    if(imageArr[i] == 1){
      cout << "point at: " << i << "\n";
      output << "0 0 0 ";
    }
    else if(imageArr[i] == 2) {
      output << "0 0 1 ";
    }
    else{
      output << "1 1 1 ";
    }
  }
}

int main(void){
  int number;
  cout << "Input number: ";
  std::cin >> number;
  
  std::clock_t start;
  start = std::clock(); 
  
  // cout << number << "\n";
  double xCoords [number];
  double yCoords [number];
  
  double minDist = 2;
  double minX = -1;
  double minY = -1;
  double minX2 = -1;
  double minY2 = -1;
  
  for(int i = 0; i < number; i++){
    double y = (double)rand() / RAND_MAX;
    double x = (double)rand() / RAND_MAX;
    //cout << y << ", " << x << "\n";
    yCoords[i] = y;
    xCoords[i] = x;
  }
  
  for(int j = 0; j < number; j++){
    double yCoord1 = yCoords[j];
    double xCoord1 = xCoords[j];
    for(int k = 0; k < number; k++){
      double yCoord2 = yCoords[k];
      double xCoord2 = xCoords[k];
      double distSqr = (yCoord2-yCoord1)*(yCoord2-yCoord1) + (xCoord2-xCoord1)*(xCoord2-xCoord1);
      //cout << "Distance: " << distSqr << "\n";
      if(distSqr != 0 && distSqr<minDist){
      	minDist = distSqr;
      	minX = xCoord1;
      	minY = yCoord1;
      	minX2 = xCoord2;
      	minY2 = yCoord2;
      }
    }
  }
  cout << "Smallest Distance: " << sqrt(minDist) << "\n";
  cout << "Coords: (" << minX << ", " << minY << ") (" << minX2 << ", " << minY2 << ")\n";
  cout << "Time: " << ( std::clock() - start ) / (double) CLOCKS_PER_SEC << " seconds \n";

  /*
  for(int i = 0; i < number; i++){
    cout << yCoords[i] << ", " << xCoords[i] << "\n";
  }
  */

  plotPoints(yCoords, xCoords, number, minX, minX2, minY, minY2);
}
