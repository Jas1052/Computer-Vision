#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <math.h>
#include <ctime> 
#include <climits>

//Compile using "g++ -O3 main.cpp"
//Run using "./a.out"

using namespace std;

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

/*
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
  
}
*/

/* OUTPUT WITH LOOP 
  Number: 2
  Smallest Distance: 0.40807
  Coords: (0.394383, 0.840188) (0.79844, 0.783099)
  Time: 0 seconds 

  Number: 4
  Smallest Distance: 0.199084
  Coords: (0.76823, 0.335223) (0.628871, 0.477397)
  Time: 0 seconds 

  Number: 8
  Smallest Distance: 0.175661
  Coords: (0.242887, 0.0163006) (0.108809, 0.12979)
  Time: 0 seconds 

  Number: 16
  Smallest Distance: 0.0705635
  Coords: (0.839112, 0.512932) (0.769914, 0.526745)
  Time: 0 seconds 

  Number: 32
  Smallest Distance: 0.00809677
  Coords: (0.931835, 0.437638) (0.92397, 0.43956)
  Time: 0 seconds 

  Number: 64
  Smallest Distance: 0.0166916
  Coords: (0.497259, 0.66688) (0.48295, 0.675476)
  Time: 0 seconds 

  Number: 128
  Smallest Distance: 0.0122764
  Coords: (0.612442, 0.198021) (0.618958, 0.187616)
  Time: 0 seconds 

  Number: 256
  Smallest Distance: 0.00205939
  Coords: (0.0501679, 0.341482) (0.0504663, 0.34352)
  Time: 0 seconds 

  Number: 512
  Smallest Distance: 0.00126601
  Coords: (0.0488258, 0.178952) (0.0475882, 0.179218)
  Time: 0 seconds 

  Number: 1024
  Smallest Distance: 9.49249e-05
  Coords: (0.750337, 0.138667) (0.750374, 0.13858)
  Time: 0 seconds 

  Number: 2048
  Smallest Distance: 0.000462375
  Coords: (0.608781, 0.312183) (0.609239, 0.31212)
  Time: 0 seconds 

  Number: 4096
  Smallest Distance: 7.05566e-05
  Coords: (0.441622, 0.238825) (0.441687, 0.238854)
  Time: 0.03 seconds 

  Number: 8192
  Smallest Distance: 7.24481e-05
  Coords: (0.328106, 0.213619) (0.328071, 0.213683)
  Time: 0.09 seconds 

  Number: 16384
  Smallest Distance: 6.89651e-05
  Coords: (0.776561, 0.347426) (0.77657, 0.347494)
  Time: 0.37 seconds 

  Number: 32768
  Smallest Distance: 3.255e-05
  Coords: (0.424395, 0.258061) (0.424427, 0.258066)
  Time: 1.49 seconds 

  Number: 65536
  Smallest Distance: 9.28726e-06
  Coords: (0.370572, 0.456232) (0.370564, 0.456229)
  Time: 5.93 seconds 

  Number: 131072
  Smallest Distance: 4.48543e-06
  Coords: (0.449907, 0.657396) (0.449904, 0.657393)
  Time: 23.8 seconds 

  Number: 262144
  Smallest Distance: 3.49893e-06
  Coords: (0.622058, 0.31559) (0.622062, 0.315591)
  Time: 95.62 seconds 

  Number: 524288
  Segmentation fault (core dumped)
*/