#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>

// �÷��̾� ���� ��ȯ�ϴ� �Լ��̴�!
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

// �Ѿ� ���� ��ȯ�ϴ� �Լ��̴�
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

// ���� �÷��̾� ����
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

// ���� ���ϰ� �ִ� �÷��̾� ��ȣ!
int playerAimed(int NowPlayer, int playNum)
{
	int aimedP;

	do {
		aimedP = 1 + (rand() % playNum);
	} while (aimedP == NowPlayer);
	
	return aimedP;
}

// 3�� ��ٸ��� �Լ�
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

// ���� ���ϴ� �÷��̾ �� �¾Ҵ��� Ȯ���ϴ� �Լ�
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