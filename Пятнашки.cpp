#include "pch.h"
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <iomanip>
#include <stdlib.h>
using namespace std;

void InitGamePlace();
void ShowGamePlace();
void MixGamePlace();
bool GameWin();
void GamePlay();

const int N = 4;

int game_place[N][N];

int main()
{
	setlocale(LC_ALL, "rus");

	InitGamePlace();

	ShowGamePlace();
	system("pause");

	MixGamePlace();

	ShowGamePlace();
	system("pause");
	cout << "Нажмите любую клавишу" << endl;

	GamePlay();
}

void InitGamePlace()
{
	int k = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			game_place[i][j] = k;
			k++;
		}
	}
}

void MixGamePlace()
{
	int x1, y1, x2, y2, temp;
	srand(time(0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			x1 = rand() % 3;
			y1 = rand() % 3;
			x2 = rand() % 3;
			y2 = rand() % 3;
			temp = game_place[x1][y1];
			game_place[x1][y1] = game_place[x2][y2];
			game_place[x2][y2] = temp;
		}
	}
}

void ShowGamePlace()
{
	system("cls");
	cout << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (game_place[i][j] != 0)
			{
				cout << setw(3) << game_place[i][j] << " | ";
			}
			else if (game_place[i][j] == 0)
			{
				cout << setw(3) << " " << " | ";
			}
		}
		cout << endl;
	}
}

bool GameWin()
{
	int k = 0;
	int game_win[N][N]{ {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 0} };
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (game_place[i][j] == game_win[i][j]) 
			{
				k++;
			}
		}
	}

	if (k == 16)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void GamePlay()
{
	char move; 
	do
	{
		cin >> move;
		switch (move)
		{
		case 'w':
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					if (game_place[i][j] == 0)
					{
						if (i != 0)
						{
							swap(game_place[i][j], game_place[i - 1][j]);
							ShowGamePlace();
							i = N;
							j = N;
							break;
						}
					}
				}
			}
			break;
		case 's':
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					if (game_place[i][j] == 0)
					{
						if (i != 3)
						{
							swap(game_place[i][j], game_place[i + 1][j]);
							ShowGamePlace();
							i = N;
							j = N;
							break;
						}
					}
				}
			}
			break;
		case 'a':
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					if (game_place[i][j] == 0)
					{
						if (j != 0)
						{
							swap(game_place[i][j], game_place[i][j - 1]);
							ShowGamePlace();
							i = N;
							j = N;
							break;
						}
					}
				}
			}
			break;
		case 'd':
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					if (game_place[i][j] == 0)
					{
						if (j != 3)
						{
							swap(game_place[i][j], game_place[i][j + 1]);
							ShowGamePlace();
							i = N;
							j = N;
							break;
						}
					}
				}
			}
			break;
		default:
			cout << "Неправильный ввод" << endl;
		}
	} while (GameWin() == false);
}