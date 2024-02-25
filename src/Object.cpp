#include "Object.h"

Object::Object(int32_t x, int32_t y)
{
    this->x = x;
    this->y = y;

    this->width = this->height = 0;
}

int Object::getX() const
{
    return this->x;
}

int Object::getY() const
{
    return this->y;
}

uint32_t Object::getWidth() const
{
    return this->width;
}

uint32_t Object::getHeight() const
{
    return this->height;
}

char** Object::getModel() const
{
    return this->model;
}

