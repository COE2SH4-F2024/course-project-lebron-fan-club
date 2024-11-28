#include "Player.h"
#include <iostream>


Player::Player(GameMechs* thisGMRef)
{
    playerPos.pos->x = 5;
    playerPos.pos->y = 10;
    playerPos.symbol = '*';
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    

    // more actions to be included
}


Player::~Player()
{
    

}

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos array list
    return playerPos;
}

void Player::updatePlayerDir()
{
    
        char input = mainGameMechsRef->getInput();
        if(input != '\0')
        {
            switch(input)
            {                      
                case 'w':
                    if(myDir != DOWN)
                    {

                        myDir = UP;
                    }
                    break;
                case 'a':
                    if(myDir != RIGHT)
                    {
                        myDir = LEFT;
                    }
                    break;
                case 's':
                    if(myDir != UP)
                    {
                        myDir = DOWN;
                    }
                    break;
                case 'd':
                    if(myDir != LEFT)
                    {
                        myDir = RIGHT;
                    }
                    break;
            }
            mainGameMechsRef->clearInput();
        }    
              
    
}

void Player::movePlayer()
{
    
    switch(myDir)
    {
        case UP:
            playerPos.pos->x--;
            break;
        case DOWN:
            playerPos.pos->x++;
            
            break;
        case LEFT:
            playerPos.pos->y--;
            
            break;
        case RIGHT:
            playerPos.pos->y++;
            
            break;
        default:
            break;
    }
    
    if(playerPos.pos->y < 1) playerPos.pos->y = mainGameMechsRef->getBoardSizeY()-2;
    else if(playerPos.pos->y > mainGameMechsRef->getBoardSizeY()-2) playerPos.pos->y = 1;
    else if(playerPos.pos->x < 1) playerPos.pos->x = mainGameMechsRef->getBoardSizeX()-2;
    else if(playerPos.pos->x > mainGameMechsRef->getBoardSizeX()-2) playerPos.pos->x= 1;
    
    
    
}
Player::Player(const Player &other)
{
    playerPos=other.playerPos;
    myDir = other.myDir;
    mainGameMechsRef = other.mainGameMechsRef;
}

Player& Player::operator=(const Player &other)
{
    if(this!=&other)
    {
        this->playerPos=other.playerPos;
        this->myDir=other.myDir;
        this->mainGameMechsRef = other.mainGameMechsRef;
    }
    return *this;
}
// More methods to be added