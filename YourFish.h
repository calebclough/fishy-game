#pragma once                // Makes sure every file included is only included once.

#include "OtherFish.h"      // Includes OtherFish.h to gain access to constants and methods.

//Declares class for the your fish. This class contains all of the information, access to information, and other methods
//for your fish.
class YourFish
{
public:

  //Default constructor.
  YourFish();

  //Complex methods.
  void drawYourFish();
  void moveYourFish();
  bool isTouching( OtherFish enemies, int index );

  //Mutator and accessor methods.
  int getYourFishX(); 
  int getYourFishY();
  int getYourFishSpeedX();
  int getYourFishSpeedY();
  int getYourFishSize();
  void setYourFishX( int x );
  void setYourFishY( int y );
  void setYourFishSpeedX( int speed );
  void setYourFishSpeedY( int speed );
  void setYourFishSize( int size );

private:

  //Variables to contain all information about your fish.
  int yourFishX;
  int yourFishY;
  int yourSize;
  int yourSpeedX;
  int yourSpeedY;
};