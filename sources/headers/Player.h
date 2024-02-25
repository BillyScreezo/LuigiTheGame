#pragma once

#include <vector>

#include "Prototype.h"
#include "Ground.h"
#include "Map.h"
#include "Enemy.h"

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
	bool status();
	bool isjump = false, ctrl = true;
	bool ismove_r = true, ismove_l = true, onground = false, underground = false;
	bool side{ 0 };
	std::vector<Ground*> ground_list;
	Player(float, float, int, int, float, float, char, Map&, std::vector<Ground*>&);

	void physic(std::vector<Enemy*>&, bool);
	virtual void die(bool type = true) override;
	void resetPlayer();
	void resetScore();

	bool useStar();
	void takeLiveMushroom();
	void takeStar(int);
	void addScore(int);

	virtual bool isDead() override;
	void jump(std::vector<Ground*>&);
	void jump(std::vector<Ground*>&, std::vector<Enemy*>&);

	bool checkDown();

	size_t getLevel();
	void levelUp();
	void levelDown();

	bool isEndLevel(std::vector<Ground*>&, unsigned);
};
