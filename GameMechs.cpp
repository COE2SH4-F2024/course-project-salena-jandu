#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs() {
    
    exitFlag = false;
    loseFlag = false;           
    boardSizeX = 20;    
    boardSizeY = 10;

    score = 0; 
    input = 0; 

}

GameMechs::GameMechs(int boardX, int boardY) {
    
    exitFlag = false;
    loseFlag = false;           
    boardSizeX = boardX; 
    boardSizeY = boardY;

    score = 0;
    input = 0;

}

// do you need a destructor? no?
GameMechs::~GameMechs() {

   
}

bool GameMechs::getExitFlagStatus() const
{

    return exitFlag;

}

bool GameMechs::getLoseFlagStatus() const {

    return loseFlag;

}
    

char GameMechs::getInput() const {
    
    if (MacUILib_hasChar() !=0)
    {
        //input = MacUILib_getChar();  // gets the last typed char

    }
    return input;
}

int GameMechs::getScore() const {
    
    return score;

}

void GameMechs::incrementScore()
{
    score ++;
}

int GameMechs::getBoardSizeX() const {

    return boardSizeX;
}

int GameMechs::getBoardSizeY() const {
   
    return boardSizeY;
}


void GameMechs::setExitTrue() {

    exitFlag = true;

}

void GameMechs::setLoseFlag() {
    
    loseFlag = true;

}

void GameMechs::setInput(char this_input) {

    input = this_input;

}

void GameMechs::clearInput() {
    
    input = 0;

}

// More methods should be added here