#include "Map.h"
#include <iostream>
#include <cstring>

Map::Map()
{
	this->width = 100;
	this->height = 25;
	field = new char* [height];
	for (int i = 0; i < height; i++)
		field[i] = new char[width];
}
Map::Map(int width, int height)
{
	this->width = width;
	this->height = height;
	field = new char* [height];
	for (int i = 0; i < height; i++)
		field[i] = new char[width];
}
void Map::fillSpace()
{
	for (int i = 0; i < width - 1; i++)
		field[0][i] = ' ';
	field[0][width - 1] = '\0';
	for (int i = 1; i < height; i++)
		strcpy_s(field[i], width, field[0]);
}
void Map::printMap()
{
	for (int i = 0; i < height; i++)
		std::cout << field[i] << std::endl;
}
int Map::getWidth()
{
	return width;
}
int Map::getHeight()
{
	return height;
}
Map::~Map()
{
	for (int i = 0; i < height; i++)
		delete[] field[i];
	delete[] field;
}