#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

// time for random generation
#include <time.h>

// border size
#define X_length 20
#define Y_length 10

using namespace std;

#define DELAY_CONST 100000

bool exitFlag;

/* snakkkeee
struct objPos{
    int x;          //x-coordinate of an object
    int y;          //y-coordinate of an object
    char symbol;    //The ASCII symbol of the object to be drawn on the screen
};
*/

// initially putting the snake down
struct objPos player = {10,5,'@'};

struct objPos *itemBin = NULL;

int input; // variable for key pressed

// how to move in correct directions
enum{
    STOP,
    LEFT,
    RIGHT,
    UP,
    DOWN
}dir;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    exitFlag = false;
}

void GetInput(void) {

   if (MacUILib_hasChar() !=0){     // If char is typed
        input = MacUILib_getChar();  // last typed value stored

    }
}

void RunLogic(void)
{
    
    player.getObjPos();

    if (input == 27){   // escape key to exit program
        exitFlag = 1;
    }


}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    int k, i, j;

   
    for(i=0; i<Y_length; i++){  // loops through all the blocks in the map

        for(j=0; j<X_length; j++){

            
            if(i==0 || i== Y_length-1||j==0 || j== X_length-1){    //making the # border
                MacUILib_printf("%c",'#');
            } 
            else {
                MacUILib_printf("%c",' ');
            }
        
            player.getObjPos();

        }

        MacUILib_printf("\n");
    
    }


}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    MacUILib_uninit();
}
