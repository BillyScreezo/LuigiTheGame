#pragma once

#include <string>
#include <vector>

#include "Ground.h"
#include "Map.h"
#include "Timer.h"

class Player;
class Enemy;

void SetCur(int, int);
void HideCursor();
time_t getTime();
void control(Map&, Player&, std::vector<Ground*>&, std::vector<Enemy*>&, bool&, bool&);
void playMenu();
void playLevel(std::vector<Ground*>&, std::vector<Enemy*>&, Map&, const unsigned int, Player&, bool&);
void printStat(Player&, Timer&, const int);
void spawnMushroom(Player&, std::vector<Ground*>&, size_t, std::vector<Enemy*>&, Map&);
void groundCheck(std::vector<Ground*>&, Player&);
void storyMode();
void openOrWrite(int, std::ifstream&);
void spawnCoin(Player&, std::vector<Ground*>&, size_t, std::vector<Enemy*>&, Map&);
void pauseMenu(bool&, bool&);
void setStdCoords(Player&);