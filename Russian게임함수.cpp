#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>

// 플레이어 수를 반환하는 함수이다!
int playerNumber(void)
{
	char playerNum;
	
	while (true)
	{
		playerNum = _getche();
		playerNum -= 48;
		if (playerNum < 2 || playerNum > 5)
		{
			putchar('\b');
			putchar(' ');
			putchar('\b');
		}
		else
		{
			return playerNum;
		}
	}
}

// 총알 수를 반환하는 함수이다
int bulletNumber(void)
{
	char bulletNum;

	while (true)
	{
		bulletNum = _getche();
		bulletNum -= 48;
		if (bulletNum < 1 || bulletNum > 5)
		{
			putchar('\b');
			putchar(' ');
			putchar('\b');
		}
		else
		{
			return bulletNum;
		}
	}
}

// 시작 플레이어 설정
int setStartPlayer(int playNum)
{
	int now;

	while (true)
	{
		now = _getche();
		now -= 48;
		if (now < 1 || now > playNum)
		{
			putchar('\b');
			putchar(' ');
			putchar('\b');
		}
		else
		{
			return now;
		}
	}
}

// 조준 당하고 있는 플레이어 번호!
int playerAimed(int NowPlayer, int playNum)
{
	int aimedP;

	do {
		aimedP = 1 + (rand() % playNum);
	} while (aimedP == NowPlayer);
	
	return aimedP;
}

// 3초 기다리는 함수
void delayThreeSec(void)
{
	for (int i = 3; i > 0; i--)
	{
		printf("%d\t", i);
		Sleep(1000);
	}
	putchar('\a');
	putchar('\a');
	putchar('\a');
	putchar('\n');
}

// 조준 당하는 플레이어가 총 맞았는지 확인하는 함수
short shotedPlayer(int bullet) 
{
	int cmpNum = 1 + (rand() % 6);

	if (cmpNum >= 1 && cmpNum <= bullet)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}