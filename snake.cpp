#include<stddef.h>
#include "snake.h"

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

Point::Point()
{
    this->x = 0;
    this->y = 0;
}

bool Point::operator==(const Point &other)
{
    return this->x == other.x && this->y == other.y;
}

Node::Node(int x, int y, Node *prev)
{
    this->position = new Point(x, y);
    this->prev = prev;
}

Node::Node(int x, int y)
{
    this->position = new Point(x, y);
    this->prev = NULL;
}


Snake::Snake(int x, int y, Direction direction)
{
    this->direction = direction;
    this->head = new Node(x, y);
}

void Snake::Move()
{
    // add node on the beginning of snake
    this->Grow();

    // remove last node
    Node *tmp;
    tmp = this->head;
    while(tmp->prev->prev != NULL )
    {
        tmp = tmp->prev;
    }
    delete tmp->prev;
    tmp->prev = NULL;
}

void Snake::Grow() {
    int x, y;
    switch(this->direction)
    {
        case EAST: x = this->head->position->x+1;
                   y = this->head->position->y;
                   break;
        case WEST: x = this->head->position->x-1;
                   y = this->head->position->y;
                   break;
        case NORTH: x = this->head->position->x;
                    y = this->head->position->y-1;
                    break;
        case SOUTH: x = this->head->position->x;
                    y = this->head->position->y+1;
                    break;
    }
    Node *newNode = new Node(x, y, this->head);
    this->head = newNode;
}
