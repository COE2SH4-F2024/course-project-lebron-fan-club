#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"

using namespace std;

#define DELAY_CONST 100000

//bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

GameMechs *Game;
Player *p;
Food *f;

int main(void)
{

    Initialize();

    while(!Game->getExitFlagStatus())  
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
    Game = new GameMechs(10,20);
    p = new Player(Game);
    f = new Food();
    
    
}

void GetInput(void)
{
    
    if(MacUILib_hasChar() && MacUILib_hasChar() != 9)
        {
            Game->setInput(MacUILib_getChar());  
        }
   
}

void RunLogic(void)
{
    if(Game->getInput() == 8)
    {
        Game->setExitTrue();
    }
    if(Game->getInput() == 32)
    {
        Game->setLoseFlag();
    }
    if(Game->getInput()==109)
    {
        Game->incrementScore();

    }
    if(Game->getInput() == 102)
    {
        f->generateFood(p->getPlayerPos());
    }
    
    if(!Game->getExitFlagStatus() && !Game->getLoseFlagStatus())
    {
        p->updatePlayerDir();
        p->movePlayer();
    }
    
    
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen(); 
    
    char gameboard[Game->getBoardSizeX()][Game->getBoardSizeY()];
    
    
    for(int i = 0; i < Game->getBoardSizeX();i++)
    {
        for(int j = 0;j<Game->getBoardSizeY();j++)
        {
            
            if(i==p->getPlayerPos().pos->x && j ==p->getPlayerPos().pos->y)
            {
                
                gameboard[i][j] = p->getPlayerPos().symbol;
            }
            else if(i == f->getFoodPos().pos->x && j == f->getFoodPos().pos->y)
            {
                gameboard[i][j] = f->getFoodPos().symbol;
            }
           
            else if(i == 0 || i == 9)
            {
                gameboard[i][j] = '#';
            }
            else
            {
                if(j == 0 || j == 19)
                {
                    gameboard[i][j] = '#';
                }
                else
                {
                    gameboard[i][j] = ' ';
                }
            }
        }
        

    }
    
    
    
    
    
    for(int i = 0; i < Game->getBoardSizeX();i++)
    {
        for(int j = 0;j<Game->getBoardSizeY();j++)
        {           
            MacUILib_printf("%c",gameboard[i][j]);
            
        }
        MacUILib_printf("\n");
    }
    MacUILib_printf("Score: %d",Game->getScore());
    if(Game->getLoseFlagStatus()==true)
    {
        MacUILib_printf("\nYou Lose!");
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
    delete[] Game;
    delete[] p;
    delete[] f;
}
