#pragma once
#include "Map.h"
#include "Ground.h"
#include "Foo.h"
#include "Player.h"
#include <vector>
#include <ctime>
#include "Enemy.h"
void playLevel(vector<Ground*>& ground_list, vector<Enemy*>& enemy_list, Map& map, const unsigned int, Player &, bool& isstoryend);