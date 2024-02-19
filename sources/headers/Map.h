#pragma once
#include <iostream>
#include <cstring>
class Map
{
private:
	int width;
	int height;
public:
	char** field;
	Map();
	Map(int width, int height);
	void fillSpace();
	void printMap();
	int getWidth();
	int getHeight();
	~Map();
};