#pragma once

#include <vector>

#include "Prototype.h"
#include "Ground.h"
#include "Map.h"
#include "Enemy.h"
#include "Const.h"

class Enemy;

extern int pLives;

class Player final : public Prototype {
private:
	bool isStand{ false };
	bool star{ false };
	unsigned timeS;
	size_t level{ 1 };
	size_t prevlevel{ level };
public:
	unsigned timeonground{ 0 };
	float startJump{ 0.0f };
	float stdspeed;
	bool isjump{ false }, ctrl{ true };
	bool ismove_r{ true }, ismove_l{ true }, onground{ false }, underground{ false };
	bool side{ false };
	std::vector<Ground*> ground_list;

	Player(float, float, int, int, float, float, char, Map&, std::vector<Ground*>&);

	inline bool status() { return isStand; }
	inline bool checkDown() { return y >= gDown; }
	inline void resetScore() { score = 0; }
	inline void takeLiveMushroom() { ++pLives; }
	inline void addScore(int score) { this->score += score; }
	inline size_t getLevel() { return this->level; }

	virtual void die(bool type = true) override;

	bool useStar();
	bool isEndLevel(std::vector<Ground*>&, unsigned);

	void physic(std::vector<Enemy*>&, bool);
	void resetPlayer();
	void takeStar(int);
	void jump(std::vector<Ground*>&);
	void jump(std::vector<Ground*>&, std::vector<Enemy*>&);
	void levelUp();
	void levelDown();
	

	


	
};
