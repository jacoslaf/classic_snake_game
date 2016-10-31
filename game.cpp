#include<stdlib.h>
#include<iostream>

#include "game.h"

Game::Game(int height, int width)
{
    this->height = height;
    this->width = width;
    this->snake = new Snake(width/2, height/2, NORTH);
    this->SetupApplePosition();
}

void Game::SetupApplePosition()
{
    Node *current;
    bool appleOnSnake;
    // generate apple collisions until correct is found
    while(true)
    {
        appleOnSnake = false;
        this->apple.x = rand() % this->width;
        this->apple.y = rand() % this->height;
        // prevent apple snake collision
        for(current=this->snake->head; current; current=current->prev)
        {
            appleOnSnake = appleOnSnake || (*current->position == apple);
        }
        if(!appleOnSnake)
        {
            break;
        }
    }
}

void Game::Move()
{
    this->snake->Move();
    if(*(this->snake->head->position) == this->apple)
    {
        this->snake->Grow();
        SetupApplePosition();
    };
}
