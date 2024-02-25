#pragma once

class Map final {
private:
	int width;
	int height;
public:
	char** field;

	Map();
	Map(int, int);

	void fillSpace();
	void printMap();

	int getWidth();
	int getHeight();

	~Map();
};