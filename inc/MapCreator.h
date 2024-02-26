#pragma once

#include <fstream>
#include <vector>

#include "Map.h"
#include "Ground.h"
#include "Enemy.h"

Ground* addNewObject_g(int, int, int, int, size_t, Map&);
void loadMap(std::ifstream&, std::vector<Ground*>&, std::vector<Enemy*>&, Map&);
void deleteObject_g(std::vector<Ground*>&, int);
bool visualWorkSpace(std::vector<Ground*>&, std::vector<Enemy*>&, int&, Map&);
void mapCreator();