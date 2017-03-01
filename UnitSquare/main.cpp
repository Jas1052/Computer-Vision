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

  int deltax = x2 - x1;
  int deltay = y2 - y1;
  int deltae == std::abs(deltay / deltax)    // Assume deltax != 0 (line is not vertical),
       // note that this division needs to be done in a way that preserves the fractional part
  real error := deltaerr - 0.5
  int y := y0
  for x from x0 to x1 
     plot(x,y)
     error := error + deltaerr
     if error ≥ 0.5 then
         y := y + 1
         error := error - 1.0

  //cout << x1 << " " <<  y1  << " " << x2 << " " << y2 << "\n";
  /*
  int deltaX = x2-x1;
  int deltaY = y2-y1;

  if(deltaX >= deltaY){
    cout << "x>y\n";
    int j = y1;
    int e = deltaY - deltaX;
    for(int i = x1; i < x2; i++){
      //cout << 100*j+i << "\n";
      //illuminate
      imageArr[100*j + i] = 1;
      if(e >= 0){
        j++;
        e = e - deltaX;
      }
      e = e + deltaY;
    }
  }
  if(deltaY > deltaX){
    cout << "y>x\n";
    int j = x1;
    int e = deltaX - deltaY;
    for(int i = y1; i < y2; i++){
      //cout << 100*j+i << "\n";
      //illuminate
      cout << i << " " << j << "\n";
      imageArr[100*i + j] = 1;
      if(e >= 0){
        j++;
        e = e - deltaY;
      }
      e = e + deltaX;
    }
  }
  */

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
