#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <math.h>
#include <ctime> 
#include <climits>
#include <algorithm> // for std::find
#include <iterator> // for std::begin, std::end
#include <fstream>

//Compile using "g++ -O3 main.cpp"
//Run using "./a.out"

using namespace std;

/*
int main(void){
  int number = 3;
  while(number<INT_MAX){
    cout << "\nNumber: " << number << "\n";
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

    number = number*2;
  }
}
*/

void plotPoints(double yCoordinates[], double xCoordinates[], int number){
  int pointNumber[number];
  for(int x = 0; x < number; x++){
    pointNumber[x] = (int)10000*yCoordinates[x] + (int)100*xCoordinates[x];
  }
  ofstream output;
  output.open("squarePoints.ppm");
  output << "P3 100 100 1";
  for(int i = 0; i < 10000; i++){
    if(i%100 == 0){
      output << '\n';
    }
    int counter = 0;
    for(int a=0; a<number; a++){
      if(pointNumber[a] == i){
        counter++;
      }
    }
    if(counter>0){
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

  plotPoints(yCoords, xCoords, number);
}

