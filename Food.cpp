#include "Food.h"
#include <time.h>
#include <stdlib.h>

Food::Food()
{
    srand(time(NULL));
    foodPos.pos->x = (rand()%8)+1;
    foodPos.pos->y = (rand()%18)+1;
    foodPos.symbol = '*';
}
Food::~Food()
{

}
Food::Food(const Food &other)
{
    foodPos.pos->x = other.foodPos.pos->x;
    foodPos.pos->y = other.foodPos.pos->y;
    foodPos.symbol = other.foodPos.symbol;
}
Food& Food::operator=(const Food &other)
{
    this->foodPos.pos->x = other.foodPos.pos->x;
    this->foodPos.pos->y = other.foodPos.pos->y;
    this->foodPos.symbol = other.foodPos.symbol;
}
void Food::generateFood(objPos blockOff)
{
    
    foodPos.pos->x = (rand()%8)+1;
    foodPos.pos->y = (rand()%18)+1;
    
    while(blockOff.getSymbolIfPosEqual(&foodPos))
    {
        foodPos.pos->x = (rand()%18)+1;
        foodPos.pos->y = (rand()%8)+1;
    }
    

}
objPos Food::getFoodPos() const
{
    return foodPos;
}