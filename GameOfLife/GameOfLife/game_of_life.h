#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class game_of_life {
private:
	static const unsigned int COLUMNS = 40;
	static const unsigned int ROWS = 20;
	bool _gen[ROWS][COLUMNS];
	bool _next_gen[ROWS][COLUMNS];
	bool Random();
	int RandomNumber(int min, int max);
	bool CellTaken(int i, int j);
	int alive = 0;
	bool aliveNext(int i, int j);
public:
	game_of_life();
	void next_gen();
	void draw();
};

#endif
