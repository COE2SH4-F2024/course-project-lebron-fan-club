#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"
#include <iostream>

class Player
{   
public:
    // Enum for direction states
    enum Direction { UP, DOWN, LEFT, RIGHT, STOP }; 

    // Constructors and Destructor
    Player(); 
    Player(GameMechs* gameMechanics, Food* food);
    ~Player(); 
    Player(const Player& other);             // Copy constructor
    Player& operator=(const Player& other);  // Copy assignment operator

    // Player Movement and Behavior
    objPosArrayList* getPlayerPos() const;   // Get snake's current positions
    void updatePlayerDir();                  // Update direction based on input
    void movePlayer();                       // Move the player (snake)
    bool checkFoodConsumption();             // Check if food is consumed
    void increasePlayerLength();             // Increase snake length
    bool checkselfcollision();               // Check for collision with itself

    // Speed Control
    int getSpeed() const; 
    void setSpeed(int speed);        

    // Food Management
    Food* getFoodlist() const;               // Get reference to the food object

private:
    // Snake body and attributes
    objPosArrayList* player;   // List of snake body positions
    char headsymbol;           // Symbol representing the snake's head
    char bodysymbol;           // Symbol representing the snake's body
    Direction myDir;           // Current movement direction

    // References to other game components
    Food* foodlist;            // Pointer to the food object
    GameMechs* mainGameMechsRef; // Pointer to game mechanics

    // Board dimensions and speed
    int rowNums;               // Number of rows (board height)
    int colNums;               // Number of columns (board width)
    int speed;                 // Speed of the snake
};

#endif