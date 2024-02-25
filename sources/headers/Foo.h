#pragma once

#include <string>
#include <vector>

#include "Ground.h"
#include "Map.h"
#include "Timer.h"

class Player;
class Enemy;

void SetCur(int x, int y);
void HideCursor();
time_t getTime();
void control(Map&, Player&, vector<Ground*>&, vector<Enemy*>&, bool&, bool&);
void playMenu();
void playLevel(vector<Ground*>&, vector<Enemy*>&, Map&, const unsigned int, Player&, bool&);
void printStat(Player&, Timer&, const int);
void spawnMushroom(Player&, vector<Ground*>&, size_t, vector<Enemy*>&, Map&);
void groundCheck(vector<Ground*>&, Player&);
void storyMode();
void openOrWrite(int, ifstream& file);
void spawnCoin(Player&, vector<Ground*>&, size_t, vector<Enemy*>&, Map&);
void pauseMenu(bool&, bool&);
void setStdCoords(Player&);