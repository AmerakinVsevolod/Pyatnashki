﻿#include "pch.h"
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
using namespace std;

void InitGamePlace();
void ShowGamePlace();
void MixGamePlace();
bool GameWin();
void GamePlay();
int steps;

const int N = 4;

int game_place[N][N];

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Пятнашки V1.0" << endl << endl;
	cout << "Меню: " << endl << "1. Играть" << endl << "2. Правила игры" << endl << "3. Выход" << endl;
	Retry:
	char change = _getch();
	switch (change)
	{
	case '1':
	{
		break;
	}
	case '2':
	{
		cout << "Пятнашки представляют из себя набор, в который входит квадратная коробка, сторона которой равна 4 сторонам костяшек, то есть 4х4." << endl << "Внутри этой коробки 15 квадратных костяшек. В коробке остается 1 свободное место под одну костяшку." << endl << "Цель игры – упорядочивание костяшек по порядку. Концом игры считается, когда все костяшки от 1 до 15 стоят друг за другом." << endl;
		system("pause");
		break;
	}
	case '3':
	{
		return 0;
	}
	default: 
	{
		cout << "Некорректный выбор в меню! Попробуйте снова!" << endl;
		goto Retry;
	}
	}

	InitGamePlace();

	ShowGamePlace();
	system("pause");

	MixGamePlace();

	ShowGamePlace();

	steps = 1;
	GamePlay();

	if (GameWin() == true)
	{
		cout << "Поздравляем! Вы выиграли!" << endl;
	}
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
	cout << endl << endl << "Шаги: " << steps << endl;
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
		move = _getch();
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
		steps++;
	} while (GameWin() == false);
}
