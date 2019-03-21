#include "OtherFish.h"  //Includes header to gain access to all variables.

using namespace std;

//Function prototype. This function returns a random number between the upper and lower bounds.
int randomBetween( int lowerBound, int upperBound );

//Default constructor. Assigns a random x value (all off screen), y value, speed, and size for each opponnent
//fish. It also makes all fish initially visible.
OtherFish::OtherFish()
{
  for(int index=0; index < FISH_NUMBER; index++)
  {
    otherPositionX[ index ] = randomBetween( 0, WIDTH ) - WIDTH;
    otherPositionY[ index ] = randomBetween( 0, HEIGHT );
    otherSpeed[ index ] = randomBetween( 1, MAX_ENEMY_SPEED );
    otherSize[ index ] = randomBetween( 1, MAX_FISH_SIZE );
    otherVisibility[ index ] = 1;
  }
}

//Builds other fish out of an ellipse and a triangle. Starting point is the front of the ellipse (head).
void OtherFish::drawOtherFish()
{
  setcolor( RED );
  setfillstyle( SOLID_FILL, RED );

  //Runs a loops to draw each individual opponent fish.
  for( int index=0; index < FISH_NUMBER; index++ )
  {
    //Only draws fish if it is visible.
    if( otherVisibility[ index ]==1 )
    {
      fillellipse( otherPositionX[ index ] - otherSize[ index ], otherPositionY[ index ], otherSize[ index ], otherSize[ index ] / 2 );
      int points [] = { otherPositionX[ index ] - otherSize[ index ] * 2, otherPositionY[ index ], otherPositionX[ index ] - otherSize[ index ] * 3, 
                        otherPositionY[ index ] + otherSize[ index ] / 2, otherPositionX[ index ] - otherSize[ index ] * 3, otherPositionY[ index ] - otherSize[index] / 2 };
      fillpoly( 3, points );
    }
  }
}

//Adds the speed of each opponent fish to its respective x-coordinate. Also checks if it is going off the screen.
void OtherFish::moveOtherFish()
{
  for( int index=0; index < FISH_NUMBER; index++ )
  {
    otherPositionX[ index ] = otherPositionX[ index ] + otherSpeed[ index ];
    
    //If the fish is going off the screen, visible or not, redraw it as a "new", visible fish on the other end of the screen.
    if( otherPositionX[ index ] > WIDTH + 3 * otherSize[ index ] )
    {
      otherPositionX[ index ] = 0;
      otherPositionY[ index ] = randomBetween( 0, HEIGHT );
      otherSpeed[ index ] = randomBetween( 1, MAX_ENEMY_SPEED );
      otherSize[ index ] = randomBetween( 1, MAX_FISH_SIZE );
      otherVisibility[ index ] = 1;
    }
  }
}

//Accessor methods.
int OtherFish::getOtherFishX( int index )
{
  return otherPositionX[ index ];
}

int OtherFish::getOtherFishY( int index )
{
  return otherPositionY[ index ];
}

int OtherFish::getOtherFishSize( int index )
{
  return otherSize[ index ];
}

int OtherFish::getOtherFishSpeed( int index )
{
  return otherSpeed[ index ];
}

int OtherFish::getOtherFishVisibility( int index )
{
  return otherVisibility[ index ];
}

//Mutator methods.
void OtherFish::setOtherFishX( int x, int index )
{
  otherPositionX[ index ] = x;
  return;
}
void OtherFish::setOtherFishY( int y, int index )
{
  otherPositionY[ index ] = y;
  return;
}

void OtherFish::setOtherFishSize( int size, int index ) 
{
  otherSize[ index ] = size;
  return;
}

void OtherFish::setOtherFishSpeed( int speed, int index )
{
  otherSpeed[ index ] = speed;
  return;
}

void OtherFish::setOtherFishVisibility( int visibility, int index )
{
  otherVisibility[ index ] = visibility;
  return;
}

//Function that returns a random number betwen the passed upper and lower bounds.
int randomBetween( int lowerBound, int upperBound )
{
  //If the input doesn't make sense, display and error message.
  if( upperBound < lowerBound )
  {
    cerr << "ERROR: Parameters to randomBetween do not satisfy condition lowerBound <= upperBound." << endl;
    return 0;
  }
  //It not, return the random number.
  else
  {
    return rand() % ( upperBound - lowerBound + 1 ) + lowerBound;
  }
}

