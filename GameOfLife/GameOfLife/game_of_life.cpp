#include <ctime>
#include "game_of_life.h"


bool game_of_life::Random()
{
	
	if (RandomNumber(0, 3) == 0)
	{
		return true;
	}
	return false;
}

int game_of_life::RandomNumber(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

bool game_of_life::CellTaken(int i, int j)
{
	if (i < 0 || j < 0 || i>ROWS || j>COLUMNS)
	{
		return false;
	}
	else if (_gen[i][j])
	{
		return true;
	}
	return false;
}

bool game_of_life::aliveNext(int i, int j)
{
	alive = 0;

	for (int g = -1; g < 2; g++)
	{
		for (int h = -1; h < 2; h++)
		{
			if (g == 0 && h == 0)
			{
				continue;
			}
			else if (CellTaken(i + g, j + h))
			{
				alive++;
			}
		}
	}


	if (!CellTaken(i, j))
	{
		if (alive == 3)
		{
			return true;
		}
	}

	else if (alive == 2 || alive == 3)
	{
		return true;
	}

	return false;
}

game_of_life::game_of_life()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			_gen[i][j] = Random();
		}
	}
}

void game_of_life::next_gen()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			if (aliveNext(i, j))
			{
				_next_gen[i][j] = true;
			}
			else
			{
				_next_gen[i][j] = false;
			}
		}
	}
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			_gen[i][j] = _next_gen[i][j];
		}
	}
}

void game_of_life::draw()
{

	cout << endl;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			if (_gen[i][j])
			{
				cout << "*";
			}
			else
			{
				cout << "-";
			}

		}
		cout << endl;
	}
}
