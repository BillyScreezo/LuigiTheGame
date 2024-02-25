#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include "Object.h"

class Map {
private:
	uint32_t width;
	uint32_t height;
    std::vector<Object> obj_list;
public:
    char **field;
	Map();
	Map(uint32_t width, uint32_t height);
	void fillSpace();
    void makePicture();
	void printMap();
	int getWidth();
	int getHeight();
    void putObjectOnMap(Object &obj);
	~Map();
};
