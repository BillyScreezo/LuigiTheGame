#pragma once

#include <iostream>

class Object {
protected:
    int32_t x;
    int32_t y;

    uint32_t width;
    uint32_t height;

    char **model;
public:
    Object(int32_t x, int32_t y);
    void loadObjectModelFromFile(std::istream& file);
    int32_t getX() const;
    int32_t getY() const;
    uint32_t getWidth() const;
    uint32_t getHeight() const;
    char **getModel() const;
};

