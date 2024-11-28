#include "GameMechs.h"
#include "MacUILib.h"
GameMechs::GameMechs()
{
    boardSizeX = 10;
    boardSizeY = 20;
    exitFlag = false;
    loseFlag = false;
    score = 0;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    boardSizeX = boardX;
    boardSizeY = boardY;
    exitFlag = false;
    loseFlag = false;
    score = 0;
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    
}
GameMechs::GameMechs(const GameMechs &other)
{
    boardSizeX = other.boardSizeX;
    boardSizeY = other.boardSizeY;
    exitFlag = other.exitFlag;
    loseFlag = other.exitFlag;
    score = other.score;
}

GameMechs& GameMechs::operator=(const GameMechs &other)
{
    this->boardSizeX = other.boardSizeX;
    this->boardSizeY = other.boardSizeY;
    this->exitFlag = other.exitFlag;
    this->loseFlag = other.exitFlag;
    this->score = other.score;
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
    

char GameMechs::getInput() const
{
    
    
    return input;
}

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore()
{
    score++;
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = '\0';
}

// More methods should be added here