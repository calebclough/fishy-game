#include "YourFish.h"  //Includes header to gain access to all variables.

using namespace std;

//Default constructor. Starts your fish in the middle of screen at rest and makes it the starting size.
YourFish::YourFish()
{
  yourFishX = WIDTH / 2;
  yourFishY = HEIGHT / 2;
  yourSize = START_SIZE;
  yourSpeedX = 0;
  yourSpeedY = 0;
}

//Builds your fish out of an ellipse and a triangle. Starting point is the front of the ellipse (head).
void YourFish::drawYourFish()
{
  setcolor( BLUE );
  setfillstyle( SOLID_FILL, BLUE );

  fillellipse( yourFishX + yourSize, yourFishY, yourSize, yourSize / 2 );

  int points [] = { yourFishX + ( yourSize * 2), yourFishY, yourFishX + ( yourSize * 3 ), yourFishY + ( yourSize / 2), yourFishX + ( yourSize * ( 3 ) ), yourFishY - ( yourSize / 2) };
  fillpoly( 3, points );
}

//Adds the your speed in each direction to your position to find your new position.
void YourFish::moveYourFish()
{
  yourFishX = yourFishX + yourSpeedX;
  yourFishY = yourFishY + yourSpeedY;
}

//This code checks if any corner of a rectangle around your fish is within the rectangle of the passed enemy fish and vice versa. Returns true if any corner is within another rectangle.
bool YourFish::isTouching( OtherFish enemies, int index )
{
  //Checks if upper left corner of your fish is in opponents fish.
  if( enemies.getOtherFishX( index ) - enemies.getOtherFishSize( index ) * 3 <= yourFishX && yourFishX <= enemies.getOtherFishX( index ) &&
      enemies.getOtherFishY( index ) - enemies.getOtherFishSize( index ) / 2 <= yourFishY - yourSize / 2 && yourFishY - yourSize / 2 <= enemies.getOtherFishY( index ) + enemies.getOtherFishSize( index ) / 2
      && enemies.getOtherFishVisibility( index ) == 1 ) 
  {
    return true;
  }
  //Checks if lower left corner of your fish is in opponents fish.
  else if( enemies.getOtherFishX( index ) - enemies.getOtherFishSize( index ) * 3 <= yourFishX && yourFishX <= enemies.getOtherFishX( index ) &&
           enemies.getOtherFishY( index ) - enemies.getOtherFishSize( index ) / 2 <= yourFishY + yourSize / 2 && yourFishY + yourSize / 2 <= enemies.getOtherFishY( index ) + enemies.getOtherFishSize( index ) / 2
           && enemies.getOtherFishVisibility( index ) == 1 )  
  {
    return true;
  }
  //Checks if upper right corner of your fish is in opponents fish.
  else if( enemies.getOtherFishX( index ) - enemies.getOtherFishSize( index ) * 3 <= yourFishX + yourSize * 3 && yourFishX + yourSize * 3 <= enemies.getOtherFishX( index ) &&
           enemies.getOtherFishY( index ) - enemies.getOtherFishSize( index ) / 2 <= yourFishY - yourSize && yourFishY - yourSize <= enemies.getOtherFishY( index ) + enemies.getOtherFishSize( index ) / 2
           && enemies.getOtherFishVisibility( index ) == 1 ) 
  {
    return true;
  }
  //Checks if upper right corner of your fish is in opponents fish.
  else if( enemies.getOtherFishX( index ) - enemies.getOtherFishSize( index ) * 3 <= yourFishX + yourSize * 3 && yourFishX + yourSize * 3 <= enemies.getOtherFishX( index ) &&
           enemies.getOtherFishY( index ) - enemies.getOtherFishSize( index ) / 2 <= yourFishY + yourSize / 2 && yourFishY + yourSize / 2 <= enemies.getOtherFishY( index ) + enemies.getOtherFishSize( index ) / 2
           && enemies.getOtherFishVisibility( index ) == 1 ) 
  {
    return true;
  }
  //Checks if upper right corner of opponents fish in your fish.
  else if( yourFishX <= enemies.getOtherFishX( index ) - enemies.getOtherFishSize( index ) * 3 && enemies.getOtherFishX( index ) - enemies.getOtherFishSize( index ) * 3 <= yourFishX + yourSize * 3 &&
           yourFishY - yourSize / 2 <= enemies.getOtherFishY( index ) - enemies.getOtherFishSize( index ) / 2 && enemies.getOtherFishY( index ) - enemies.getOtherFishSize( index ) / 2 <= yourFishY + yourSize / 2 
           && enemies.getOtherFishVisibility( index ) == 1 ) 
  {
    return true;
  }
  //Checks if upper left corner of opponents fish in your fish.
  else if( yourFishX <= enemies.getOtherFishX( index ) && enemies.getOtherFishX( index ) <= yourFishX + yourSize * 3 &&
           yourFishY - yourSize / 2 <= enemies.getOtherFishY( index ) - enemies.getOtherFishSize( index ) / 2 && enemies.getOtherFishY( index ) - enemies.getOtherFishSize( index ) / 2 <= yourFishY + yourSize / 2 
           && enemies.getOtherFishVisibility( index ) == 1 ) 
  {
    return true;
  }
  //Checks if lower right corner of opponents fish in your fish.
  else if( yourFishX <= enemies.getOtherFishX( index ) - enemies.getOtherFishSize( index ) * 3 && enemies.getOtherFishX( index ) - enemies.getOtherFishSize( index ) * 3 <= yourFishX + yourSize * 3 &&
           yourFishY - yourSize / 2 <= enemies.getOtherFishY( index ) + enemies.getOtherFishSize( index ) / 2 && enemies.getOtherFishY( index ) + enemies.getOtherFishSize( index ) / 2 <= yourFishY + yourSize / 2 
           && enemies.getOtherFishVisibility( index ) == 1 ) 
  {
    return true;
  }
  //Checks if lower left corner of opponents fish in your fish.
  else if( yourFishX <= enemies.getOtherFishX( index ) && enemies.getOtherFishX( index ) <= yourFishX + yourSize * 3 &&
           yourFishY - yourSize / 2 <= enemies.getOtherFishY( index ) + enemies.getOtherFishSize( index ) / 2 && enemies.getOtherFishY( index ) + enemies.getOtherFishSize( index ) / 2 <= yourFishY + yourSize / 2 
           && enemies.getOtherFishVisibility( index ) == 1 ) 
  {
    return true;
  }
  
  //If none of these 8 cases are true, the fish are not touching so this returns false.
  return false;
}

//Accessor methods.
int YourFish::getYourFishX()
{
  return yourFishX;
}

int YourFish::getYourFishY()
{
  return yourFishY;
}

int YourFish::getYourFishSize()
{
  return yourSize;
}

int YourFish::getYourFishSpeedX()
{
  return yourSpeedX;
}

int YourFish::getYourFishSpeedY()
{
  return yourSpeedY;
}

//Mutator methods.
void YourFish::setYourFishX( int x )
{
  yourFishX = x;
}

void YourFish::setYourFishY( int y )
{
  yourFishY = y;
}

void YourFish::setYourFishSpeedX( int speed )
{
  yourSpeedX = speed;
}

void YourFish::setYourFishSpeedY( int speed )
{
  yourSpeedY = speed;
}

void YourFish::setYourFishSize( int size )
{
  yourSize = size;
}