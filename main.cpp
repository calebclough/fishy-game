/* CSCI 261 Final Project: Fishy
 *
 * This program is a game in which a user controls a blue fish with the directional keys. The goal is to eat
 * opponent red fish that are smaller than you, making you grow in the process. However, if you touch a fish 
 * that is larger than you, then you lose. The goal is to grow as large as possible, the size of the screen.
 *
 * Authors: Caleb Clough
 *          Chris Pumford
 */

//Includes all of the classes and therefore constants needed in this program.
#include "OtherFish.h"
#include "YourFish.h"

using namespace std;

int main()
{
  //Seeds the random number generator, for the randomBetween function.
  srand( ( int ) time( NULL ) ); 

  int page = 0; // 
  
  //Code to open the game window.
  initwindow( WIDTH, HEIGHT, "Fishy", MARGIN, MARGIN, true, true ); 
  settextjustify( CENTER_TEXT, TOP_TEXT ); 
  settextstyle( BOLD_FONT, HORIZ_DIR, 2 );

  //Declares objects and variables.
  OtherFish opponents;
  YourFish fishy;
  bool eaten = 0;
  int caught = 0;

  //Main while loop, exits if the fish gets eaten, or the width of the fish is equal to the width of the screen.
  while( eaten == 0 && fishy.getYourFishSize() * 3 <= WIDTH )
  {
    //Code needed to run the double buffer.
    page = page * -1 + 1;   
    setactivepage( page );  
    setbkcolor( WHITE );    
    cleardevice();         

    //Checks if a directional key is hit. If so, it assigns either a position or negative fish speed value to 
    //the respective x or y speed variable of your fish. If any other key is pressed, it stops your fish.
    if( kbhit() )
    {
      int key = getch();
      if( key == 0 )
      {
        key = getch();
        if( key == KEY_LEFT )
        {
          fishy.setYourFishSpeedX( -FISH_SPEED );
        }
        else if( key == KEY_RIGHT )
        {
          fishy.setYourFishSpeedX( FISH_SPEED );
        }
        else if( key == KEY_UP )
        {
          fishy.setYourFishSpeedY( -FISH_SPEED );
        }
        else if( key == KEY_DOWN )
        {
          fishy.setYourFishSpeedY( FISH_SPEED );
        }
        else
        {
          fishy.setYourFishSpeedX( 0 );
          fishy.setYourFishSpeedY( 0 );
        }
      }
      else
      {
        fishy.setYourFishSpeedX( 0 );
        fishy.setYourFishSpeedY( 0 );
      }
    }

    //Moves your fish.
    fishy.moveYourFish();
    
    //The following 4 if loops check if the fish is touching the edge and if so stops it and locks its
    //position to keep it from going off the edge.
    if( fishy.getYourFishX() <= 0 )
    {
      fishy.setYourFishX( 0 );
      fishy.setYourFishSpeedX( 0 );
    }
    
    if( fishy.getYourFishX() + 3 * fishy.getYourFishSize() >= WIDTH )
    {
      fishy.setYourFishX( WIDTH - 3 * fishy.getYourFishSize() );
      fishy.setYourFishSpeedX( 0 );
    }

    if( fishy.getYourFishY() <= 0 )
    {
      fishy.setYourFishY( 0 );
      fishy.setYourFishSpeedY( 0 );
    }

    if( fishy.getYourFishY() >= HEIGHT )
    {
      fishy.setYourFishY( HEIGHT );
      fishy.setYourFishSpeedY( 0 );
    }
    
    //Moves all of the opponent fish within the object.
    opponents.moveOtherFish();
    
    //Collision algorithm. If a your fish touches an opponent fish, it checks the size. If you are smaller than the enemy fish
    //then the while loop exits and the game is over. If you are equal or greater in size, then the fish is turned invisible for
    //the rest of its way across the screen, your caught count increases, and you grow accordingly to the growth factor.
    for( int index = 0; index < FISH_NUMBER; index++ )
    {
      if( fishy.isTouching( opponents, index ) == true )
      {
        if( fishy.getYourFishSize() >= opponents.getOtherFishSize( index ) )
        { 
          opponents.setOtherFishVisibility( 0, index );
          fishy.setYourFishSize( ( fishy.getYourFishSize() * GROWTH_FACTOR + opponents.getOtherFishSize( index ) ) / GROWTH_FACTOR );
          caught++;
        }
        else
        {
          eaten = 1;
        }
      }
    }
    
    //Draws both your fish and all of the opponent fish.
    fishy.drawYourFish();
    opponents.drawOtherFish();

    //Code for the double buffering.
    setvisualpage( page );

    //Delay that controls the frame rate at which the game runs.
    delay( DELAY ); 
  }

  //Tells the computer how to write text in the graphics window.
  settextjustify( CENTER_TEXT, BOTTOM_TEXT );
  
  //The following two if loops check if you were eaten and display the appropriate win/lose message.
  if ( eaten == 0 )
  {
  outtextxy( WIDTH / 2, HEIGHT, "You've eaten the whole ocean! Click to close window..." );
  cout << "Congrats! You Won!" << endl << "Here are your stats: " << endl;
  }
  if (eaten == 1)
  {
  outtextxy( WIDTH / 2, HEIGHT, "GUUULLPP! You were eaten! Click to close window..." );
  cout << "Bummer! You Lost!" << endl << "Here are your stats: " << endl;
  }
  
  //Prints statistics on the previous game in the console window.
  cout << endl << "Fish eaten: " << caught << endl << "Max fish size: " << fishy.getYourFishSize() << endl << endl;

  //Keeps the computer from checking to see if the mouse have been clicked too often.
  while( !ismouseclick( WM_LBUTTONDOWN ) )
  {
    delay( DELAY * 25 );  
  }

  //Closes the BGI window.
  closegraph();

  //This tells the operating system that the program ran successfully.
  return EXIT_SUCCESS;
}