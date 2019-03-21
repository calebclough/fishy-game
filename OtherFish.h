#pragma once                       // Makes sure every file included is only included once.

#include <iostream>                // Allows user to use cout.
#include <ctime>                   // Used to manipulate time information, especially in seeding the random number generator.
#include "../lib/graphics.h"       // Included to allow for the GUI to be constructed. 

const int WIDTH = 800;             // The width of the graphic window.
const int HEIGHT = WIDTH * 3 / 4;  // The height of the graphic window.
const int MARGIN = WIDTH / 20;     // A margin value used to construct the screen.
const int DELAY = 10;              // Slows down the rate at which the computer runs the code.
const int FISH_NUMBER = 8;         // The number of opponent fish at any time.
const int FISH_SPEED = 3;          // How many pixels your fish moves per frame.
const int START_SIZE = 20;         // The beginning size of your fish.
const int GROWTH_FACTOR = 5;       // The factor in which your fish grows. Smaller is faster.  
const int MAX_ENEMY_SPEED = 6;     // The maximum speed of the opponent fish.
const int MAX_FISH_SIZE = 40;      // The maximum size of the opponent fish. 

//Declares class for the opponent fish. This class contains all of the information, access to information, and other methods
//for the opponent fish.
class OtherFish
{
public:
  
  //Default constructor.
  OtherFish();

  //Complex methods.
  void drawOtherFish();
  void moveOtherFish();

  //Mutator and accessor methods.
  int getOtherFishX( int index );
  int getOtherFishY( int index );
  int getOtherFishSize( int index );
  int getOtherFishSpeed( int index );
  int getOtherFishVisibility( int index );
  void setOtherFishX( int x,int index );
  void setOtherFishY( int y,int index );
  void setOtherFishSize( int size,int index );
  void setOtherFishSpeed( int speed, int index );
  void setOtherFishVisibility( int visibility, int index );

private:
  
  //Arrays of length FISH_NUMBER to carry information for each opponent fish.
  int otherPositionX[ FISH_NUMBER ];
  int otherPositionY[ FISH_NUMBER ];
  int otherSize[ FISH_NUMBER ];
  int otherSpeed[ FISH_NUMBER ];
  int otherVisibility[ FISH_NUMBER ];
};