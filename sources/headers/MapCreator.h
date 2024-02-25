#pragma once

#include <fstream>
#include <vector>

#include "Map.h"
#include "Ground.h"
#include "Enemy.h"

Ground* addNewObject_g(int, int, int, int, size_t, Map&);
void loadMap(ifstream&, vector<Ground*>&, vector<Enemy*>&, Map&);
void deleteObject_g(vector<Ground*>&, int);
bool visualWorkSpace(vector<Ground*>&, vector<Enemy*>&, int&, Map&);
void mapCreator();