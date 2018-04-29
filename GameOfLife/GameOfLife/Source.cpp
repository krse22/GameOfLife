#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "game_of_life.h"
using namespace std;

int main() {
	game_of_life the_game;
	srand(time(nullptr));
	bool dalje;
	do {
		the_game.draw();
		the_game.next_gen();

		cout << "Dalje (1/0): ";
		cin >> dalje;
		system("cls");
	} while (dalje);

	return 0;
}