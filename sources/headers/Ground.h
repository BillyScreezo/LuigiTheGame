#pragma once

#include "Map.h"

class Ground final { // класс типа "поверхность"
private:
	char sym{ 0 };
	size_t type;
	float startx{ 0.f }, endx{ 0.f };
	float starty{ 0.f }, endy{ 0.f };
public:
	Map* map{ nullptr };
	int x1{ 0 }, x2{ 0 };
	int y1{ 0 }, y2{ 0 };
	float fx1{ 0.f }, fx2{ 0.f };
	float fy1{ 0.f }, fy2{ 0.f };
	size_t moneycount{ 0 };
	bool mode{ false };
	bool side{ false };

	Ground();
	Ground(int, int, int, int, size_t, Map&);
	Ground(int, int, int, int, size_t, Map&, size_t);

	void setCoord(float, float, float, float);
	void setSum(char);
	void putOnMap();
	void setDiapasoneX(int, int);
	void setDiapasoneY(int, int);
	void roundCoords();
	void changeWalkCoords(float);

	size_t getType();

	int getSX();
	int getEX();
	int getSY();
	int getEY();
	
};