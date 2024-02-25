#pragma once

#include "Map.h"

class Prototype {

protected:
	Map* map{ nullptr };
	char sym{ 0 };
	int health{ 0 };
	int score{ 0 };
	unsigned m_time{ 0 };
	bool isStand{ true };
	
	void roundCoords();

public:
	int ix {0}, iy { 0 }, width{ 0 }, height{ 0 };
	float x{ 0 }, y{ 0 }, wspeed{ 0 }, fspeed{ 0 };

	virtual void putOnMap();
	virtual void die(bool) = 0;
	inline virtual bool isDead() { return (health == 0); }

	inline char getMarker() { return sym; }
	inline void jump() { y -= 4; }
	inline int getScore() { return score; }
	inline unsigned int getTime() { return m_time; }

	void setTime();
};


