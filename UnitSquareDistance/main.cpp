#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <math.h>
#include <time.h> 

using namespace std;

int main(void){
  int number;
  cout << "Input number: ";
  std::cin >> number;
  
  
  
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
  
}