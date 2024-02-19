#pragma once
#include "Map.h"
#include <ctime>
class Prototype
{
protected:
	bool isStand = true;
	char sym = 0;
	Map* map = nullptr;
	int health = 0;
	int score{ 0 };
	unsigned int m_time{ 0 };
	void roundCoords();
public:
	
	int ix = 0, iy = 0, width = 0, height = 0;
	float x = 0, y = 0, wspeed = 0, fspeed = 0;
	virtual void putOnMap();
	virtual void die();
	virtual bool isDead();
	char getMarker();
	void jump();
	int getScore();
	unsigned int getTime();
	void setTime();
};


