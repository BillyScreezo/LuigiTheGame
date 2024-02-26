#include <Windows.h>
#include <cmath>
#include <ctime>
#include <iostream>

#include "Player.h"
#include "Foo.h"

void Player::die(bool type) { 
	if (type) {
		sym = 'z';
	}
	else {
		sym = 'n';
	}
	std::cout << '\a'; 
	isStand = true;
    --pLives;
	health = 0;
	width = pwidth;
	height = pheight;
	level = 1;
	prevlevel = 1;
}

void Player::takeStar(int score) {
	star = true;
	this->score += score;
	timeS = clock();
}

bool Player::useStar() {
	if (star && ((clock() - timeS) >= 10000)) {
		star = false;
	}
	return star;
}

Player::Player(float x, float y, int width, int height, float wspeed, float fspeed, char sym, Map& map, std::vector<Ground*>& ground_list) {
	this->x = x;
	this->y = y;
	this->health = 1;
	this->width = width;
	this->height = height;
	this->wspeed = wspeed;
	this->stdspeed = wspeed;
	this->fspeed = fspeed;
	this->sym = sym;
	this->map = &map;
	this->ground_list = ground_list;
	this->timeS = 0;
	roundCoords();
}

void Player::physic(std::vector<Enemy*>& enemy_list, bool mode) {
	roundCoords();
	if (ix < 0) {
		x = 0.0f;
	}
	if (health != 0 && iy + height < map->getHeight()) {
		if (!onground && mode) {
			y += fspeed;
		}
		roundCoords();
		if (iy >= 0) {
			if (map->field[iy + height][ix] == '#' ||
				map->field[iy + height][ix] == '?' ||
				map->field[iy + height][ix] == 'o' ||
				map->field[iy + height][ix] == '=' ||
				map->field[iy + height][ix] == '-' ||
				map->field[iy + height][ix + width - 1] == '#' ||
				map->field[iy + height][ix + width - 1] == '?' ||
				map->field[iy + height][ix + width - 1] == 'o' ||
				map->field[iy + height][ix + width - 1] == '=' ||
				map->field[iy + height][ix + width - 1] == '-' ||
				map->field[iy + height][ix + width - 1] == 'm') {
				if (onground == false) {
					timeonground = clock();
				}
				onground = true;
			}
			else {
				onground = false;
			}
			for (auto i = iy; i < iy + height; i++) {
				if (map->field[i][ix + width] == '#' ||
					map->field[i][ix + width] == '?' ||
					map->field[i][ix + width] == 'o' ||
					map->field[i][ix + width] == '=' ||
					map->field[i][ix + width] == '-' ||
					map->field[i][ix + width] == 'm') {
					ismove_r = false;
					break;
				}
				else {
					ismove_r = true;
				}
				if (map->field[i][ix - 1] == '#' ||
					map->field[i][ix - 1] == '?' ||
					map->field[i][ix - 1] == 'o' ||
					map->field[i][ix - 1] == '=' ||
					map->field[i][ix - 1] == '-' ||
					map->field[i][ix - 1] == 'm') {
					ismove_l = false;
					break;
				}
				else {
					ismove_l = true;
				}
			}
		}
	}
	if (y + height >= gDown && !isStand) {
		die();
	}
	if (health == 0) {
		if (y <= gDown) {
			y += fspeed / 2;
		}
		iy = static_cast<int>(round(y));
		return;
	}
}

void Player::jump(std::vector<Ground*>& ground_list) {
	auto isbreak{ false };
	if (onground && !underground) {
		isjump = true;
		for (auto i = 0; i < 63; i++) {
			roundCoords();
			for (const auto& g:ground_list) {
				if (g->y2 == iy && (ix >= g->x1 && ix < g->x2 || ix+width - 1 >= g->x1 && ix + width - 1 < g->x2)) {
					isbreak = true;
					break;
				}
			}
			if (isbreak) {
				break;
			}
			y -= 0.1f;
		}
	}
	isjump = false;
}

void Player::jump(std::vector<Ground*>& ground_list, std::vector<Enemy*>& enemy_list) {

	roundCoords();
	physic(enemy_list, 0);

	for (auto j{ 0 }; j < ground_list.size(); j++) {
		if (ground_list[j]->y2 == iy && (ix >= ground_list[j]->x1 && ix < ground_list[j]->x2 || ix + width - 1 >= ground_list[j]->x1 && ix + width - 1 < ground_list[j]->x2)) {
			if (ground_list[j]->getType() == 1 || ground_list[j]->getType() == 3) {
				if (ground_list[j]->mode) {
					spawnMushroom(*this, ground_list, j, enemy_list, *map);
					ground_list[j]->setSum('o');
					ground_list[j]->mode = false;
				}
			}
			if (ground_list[j]->getType() == 2 || ground_list[j]->getType() == 4) {
				if (ground_list[j]->mode) {
					spawnCoin(*this, ground_list, j, enemy_list, *map);
					ground_list[j]->setSum('o');
					ground_list[j]->mode = false;
				}
			}
			isjump = false;
			break;
		}
	}

	enemyModule(enemy_list, *this, ground_list, *map, WorkType::INTERACTION);
	if (isjump && (startJump - y < maxblocks)) {
		y -= jumpforce;
	}
	else {
		isjump = false;
	}

	if (isjump && onground) {
		onground = false;
	}
}

void Player::levelUp() {
	score += 1000;
	if (level != 3) {
		level++;
	}
	if (prevlevel == 1) {
		y -= 1.0f;
		height += 1;
	}
	prevlevel = level;
}

void Player::levelDown() {
	if (level > 0) {
		level--;
	}
	else {
		die();
	}
	if (prevlevel == 2) {
		height--;
	}
	prevlevel = level;
}

bool Player::isEndLevel(std::vector<Ground*>& space, unsigned t1) {
	for (const auto&g:space) {
		if ((g->getType() == 11) && iy + height >= g->y1 && iy + height <= g->y2 && (ix == g->x1 || ix + width - 1 == g->x1) && onground == true) {
			if (t1 == 0) {
				t1 = clock();
				addScore(5000);
			}
			return true;
		}
	}
	return false;
}

void Player::resetPlayer() {
	sym = '@';
	isStand = false;
	health = 1;
	level = 1;
	prevlevel = 1;
}