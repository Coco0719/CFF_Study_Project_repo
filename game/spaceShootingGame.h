#pragma once

#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include "staticFunc.h"

enum class Dir
{
	UP = 105,   // i
	LEFT = 106, // j
	DOWN = 107, // k
	RIGHT = 108, // l
	ATTACK = 97 // a
};

using namespace std;

class IntroMap;
class Player;
class Enemy;

class IntroMap
{
public:
	IntroMap()
	{
		staticFunc::gotoxy(XY[0][0], XY[0][1]); std::cout << static_cast<char>(1);
		staticFunc::gotoxy(XY[1][0], XY[1][1]); std::cout << static_cast<char>(2);
		staticFunc::gotoxy(XY[2][0], XY[2][1]); std::cout << static_cast<char>(3);
		staticFunc::gotoxy(XY[3][0], XY[3][1]); std::cout << static_cast<char>(4);

		staticFunc::gotoxy(33, 13);
		std::cout << "S P A C E  S H O O T I N G  G A M E";

		staticFunc::gotoxy(0, 40);
		for (int i = 0; i <= 100; i++)
		{
			std::cout << static_cast<char>(6);
		}
		std::cout << std::endl;
	}


	//SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), number); 0 -> 8 -> 7 -> 15
	static bool printStars(void)
	{
		while (true)
		{
			char c;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 23; j++)
				{
					if (_kbhit() == 1)
					{
						c = _getch();
						if (c == static_cast<char>(27)) // input key == esc
						{
							return false;
						}
						else // input key != esc
						{
							return true;
						}
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorArr1[i]);
					staticFunc::gotoxy(star1[j][0], star1[j][1]); std::cout << '*';
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorArr2[i]);
					staticFunc::gotoxy(star2[j][0], star2[j][1]); std::cout << '*';
				}
				staticFunc::delay(300);
			}
		}
	}

private:
	static int star1[23][2];
	static int star2[23][2];
	static int colorArr1[4];
	static int colorArr2[4];
	static int XY[4][2];
};

class Player
{
public:
	Player() : score(0), userX(50), userY(29), indexBullet(0), user("l-O-l")
	{
		staticFunc::gotoxy(userX, userY);
		for (int i = 0; i < 40; i++)
		{
			bullet[i] = 0;
			posX_Bullet[i] = 0;
			posY_Bullet[i] = 0;
		}
		cout << user << endl;
	}

	void printDebug(Player& obj);

	void printPlayer(Player& obj) const;
	void moveToDir(Player& obj, char& key);
	void updateBullet(Player& obj);
	void printBullet(Player& obj);
	void createBullet(Player& obj);
	// 총알 충돌

private:
	int userX;
	int userY;
	int score;
	const string user;

	int indexBullet;
	int bullet[40];
	int posX_Bullet[40];
	int posY_Bullet[40];
};

// 적 체력 넣기
class Enemy
{
public:
	Enemy() : enemy("*-*"), moveCount(0), enemyBulletIndex(0)
	{
		for (int i = 0; i < 40; i++)
		{
			enemyBullet[i] = 0;
			enemyBulletPosX[i] = 0;
			enemyBulletPosY[i] = 0;
		}
	}

	void setEnemyPos(int x, int y); // 적 위치 초기화
	void printEnemy(Enemy& obj) const; // 적 출력
	void moveEnemy(Enemy& obj, int&& leftOrRight); // 좌우로 움직이고
	// 총알 체크 -> 만약 모든 총알이 없으면 총알 모두 1로 초기화 시킴
	void updateBulletEnemy(Enemy& obj); // 총알 초기화
	void createBulletEnemy(Enemy& obj); // 총알 생성
	void printBulletEnemy(Enemy& obj); // 총알 출력
	
	// static 함수로 짜야할지 고민...
//	void collider(void); // 총알 충돌
	
	static bool increaseCoolTime(void)
	{
		++enemyAttackCoolTime;
		if (enemyAttackCoolTime == 20)
		{
			enemyAttackCoolTime = 0;
			return true;
		}
		else
		{
			return false;
		}
	}

private:
	int enemyX;
	int enemyY;
	int moveCount;
	const string enemy;

	int enemyHp;
	int enemyBullet[5];
	int enemyBulletPosX[5];
	int enemyBulletPosY[5];
	int enemyBulletIndex;
	
	static int enemyAttackCoolTime;
};

/*
필독 !!! 3주 동안 못할거임

다음에 할 일 적이 공격하는거 디버깅하기!!!

*/