#include "spaceShootingGame.h"

int main(void)
{
	// Game Attribute Init
	system("mode con cols=100 lines=41");
	staticFunc::cursorHide();

	// Game Intro
	IntroMap map;//map.
	bool select = IntroMap::printStars();
	if (select == false) // ���� select�� false�� ���� ����
	{
		system("cls");
		return 0;
	}

	// Game Init Before Start
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	Enemy Ene[3]; // �� ����
	for (int i = 0; i < 3; i++) // �� ��ġ �ʱ�ȭ
	{
		Ene[i].setEnemyPos((i + 1) * 25, 0);
	}

	Player User; // ���� ����
	// Game Loop(STRAT)
	bool enemyAttack = false;
	while (true)
	{
		if (_kbhit() == 1)
		{
			char key = _getch();
			User.moveToDir(User, key);
		}
		User.printPlayer(User);
		User.updateBullet(User);
		User.printBullet(User);
		//	User.printDebug(User);

		// enemy loop
		for (int i = 0; i < 3; i++)
		{
			Ene[i].moveEnemy(Ene[i], (i % 2));
			Ene[i].printEnemy(Ene[i]);
			Ene[i].updateBulletEnemy(Ene[i]);
			Ene[i].printBulletEnemy(Ene[i]);
		}
		enemyAttack = Enemy::increaseCoolTime();
		if (enemyAttack == true)
		{
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					Ene[i].updateBulletEnemy(Ene[i]);
					Ene[i].createBulletEnemy(Ene[i]);
				}
			}
		}

		staticFunc::delay(50);
		system("cls");
	}

	return 0;
}