#include "spaceShootingGame.h"

// for print stars on background
int IntroMap::star1[23][2] = { { 7, 3 },{ 12, 5 },{ 23, 7 },{ 35, 7 },{ 38, 3 },{ 50, 9 },{ 65, 2 },{ 74, 7 },{ 80, 5 },{ 73, 13 },{ 87, 16 },{ 75, 26 },{ 80, 28 },{ 95, 21 },{ 33, 29 },{ 35, 22 },{ 36, 26 },{ 68, 27 },{ 10, 23 },{ 15, 27 },{ 20, 28 },{ 6, 18 },{ 15, 15 } };
int IntroMap::star2[23][2] = { { 8 , 2 },{ 15, 4 },{ 19, 9 },{ 52, 5 },{ 68, 8 },{ 72, 2 },{ 85, 5 },{ 93, 8 },{ 75, 18 },{ 97, 14 },{ 74, 23 },{ 77, 28 },{ 79, 25 },{ 86, 26 },{ 33, 24 },{ 37, 27 },{ 45, 22 },{ 48, 26 },{ 67, 23 },{ 8, 23 },{ 26, 5 },{ 7, 13 },{ 23, 18 } };
int IntroMap::colorArr1[4] = { 0, 8, 7, 15 };
int IntroMap::colorArr2[4] = { 15, 7, 8, 0 };
int IntroMap::XY[4][2] = { { 30, 10 },{ 70, 10 }, { 30, 20 },{ 70, 20 } };

// 총알 쿨타임을 모든 enemy 객체들이 공유한다!!!
int Enemy::enemyAttackCoolTime = 0;

// method
void Player::printPlayer(Player& obj) const
{
	staticFunc::gotoxy(obj.userX, obj.userY);
	cout << obj.user;
}

void Player::moveToDir(Player& user, char& key)
{
	switch (key)
	{
	case static_cast<char>(Dir::UP):
		user.userY -= 2;
		break;
	case static_cast<char>(Dir::DOWN):
		user.userY += 2;
		break;
	case static_cast<char>(Dir::LEFT):
		user.userX -= 2;
		break;
	case static_cast<char>(Dir::RIGHT):
		user.userX += 2;
		break;
	case static_cast<char>(Dir::ATTACK): 
		user.createBullet(user);
		break;
	default:
		break;
	}
}

void Player::updateBullet(Player& obj)
{
	for (int i = 0; i < 40; i++)
	{
		if (obj.bullet[i] == 1)
		{
			--obj.posY_Bullet[i];
			if (obj.posY_Bullet[i] == 0)
			{
				obj.bullet[i] = 0;
				obj.posX_Bullet[i] = 0;
				obj.posY_Bullet[i] = 0;
			}
		}
	}
}

void Player::createBullet(Player& obj) 
{
	++obj.indexBullet;
	if (obj.indexBullet == 40)
	{
		obj.indexBullet = 0;
	}

	obj.bullet[obj.indexBullet] = 1;
	obj.posX_Bullet[obj.indexBullet] = obj.userX;
	obj.posY_Bullet[obj.indexBullet] = obj.userY;
}

void Player::printBullet(Player& obj)
{
	for (int i = 0; i < 40; i++)
	{
		if (obj.bullet[i] == 1)
		{
			staticFunc::gotoxy(obj.posX_Bullet[i] + 2, obj.posY_Bullet[i]);
			cout << 'l';
		}
	}
}

// 디버깅 메서드
void Player::printDebug(Player& obj)
{
	staticFunc::gotoxy(0, 0);
	cout << "Bullet 정보 : ";
	for (int i = 0; i < 40; i++)
	{
		cout << bullet[i] << ' ';
	}
	
	staticFunc::gotoxy(0, 1);
	cout << "Bullet X좌표 : ";
	for (int i = 0; i < 40; i++)
	{
		cout << posX_Bullet[i] << ' ';
	}
	
	staticFunc::gotoxy(0, 2);
	cout << "Bullet Y좌표 : ";
	for (int i = 0; i < 40; i++)
	{
		cout << posY_Bullet[i] << ' ';
	}
}

// Enemy---------------------------------;

void Enemy::setEnemyPos(int x, int y)
{
	enemyX = x;
	enemyY = y;
}

void Enemy::printEnemy(Enemy& obj) const
{
	staticFunc::gotoxy(obj.enemyX, obj.enemyY);
	cout << obj.enemy;
}

void Enemy::moveEnemy(Enemy& obj, int&& leftOrRight)
{
	static bool dirMove = true;
	
	if (dirMove == true)
	{
		obj.enemyX--;
	}
	else
	{
		obj.enemyX++;
	}
	
	obj.moveCount++;
	if (obj.moveCount == 15)
	{	
		dirMove = !dirMove;
		moveCount = 0;
	}
}

void Enemy::updateBulletEnemy(Enemy& obj) // 총알 위치 초기화
{
	for (int i = 0; i < 5; i++)
	{
		if (enemyBullet[i] == 1)
		{
			++enemyBulletPosY[i]; // 위치 초기화
			
			// 만약, 총알 y축이 40을 벗어난다면 총알 사라짐
			if (enemyBulletPosY[i] > 40)
			{
				enemyBullet[i] = 0;
			}
		}
	}
}

void Enemy::createBulletEnemy(Enemy& obj) 
{
	// 총알을 생성하고, 총알 위치도 초기화
	obj.enemyBullet[enemyBulletIndex] = 1;
	obj.enemyBulletPosX[enemyBulletIndex] = obj.enemyX;
	obj.enemyBulletPosY[enemyBulletIndex] = obj.enemyY;

	// 그리고 인덱스를 올리고 만약 인덱스가 5라면 인덱스를 다시 0으로 만듭니다.
	obj.enemyBulletIndex++;
	if (obj.enemyBulletIndex == 5)
	{
		obj.enemyBulletIndex = 0;
	}
}

void Enemy::printBulletEnemy(Enemy& obj) // 총알 출력
{
	for (int i = 0; i < 5; i++)
	{
		if (enemyBullet[i] == 1)
		{
			staticFunc::gotoxy(obj.enemyBulletPosX[i] + 1, obj.enemyBulletPosY[i]);
			cout << 'v';
		}
	}
}