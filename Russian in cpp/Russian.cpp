#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include "RussianGame.h"

int main(void)
{
	srand((unsigned)time(NULL));

	int playNum;
	int bullet;
	int NowPlayer;
	int aimedPlayer;
	char next;

	printf("================= [���þ� �귿] =================\n\n");


	printf("�÷��̾� ���� �Է����ּ��� [2 ~ 5] >> ");
	playNum = playerNumber();
	putchar('\n');

	printf("\n>> Next >>\n\n");

	printf("�Ѿ��� ���� �Է����ּ��� [1 ~ 5] >> ");
	bullet = bulletNumber();
	putchar('\n');

	printf("\n>> Next >>\n\n");

	printf("���� �÷��̾ �������ּ��� [1 ~ 5] >> ");
	NowPlayer = setStartPlayer(playNum);

	printf("\n>> Next >>\n\n");

	printf("=================== [���� ����] ===================\n\n");

	while (true)
	{
		aimedPlayer = playerAimed(NowPlayer, playNum);

		printf("%d �÷��̾� ������ >> %d �÷��̾� ���ص�!! \n", NowPlayer, aimedPlayer);
		delayThreeSec();

		if (shotedPlayer(bullet) == 1)
		{
			printf("�÷��̾ �׾����ϴ�.\n\n");
			printf("=================== [���� ����] ===================\n\n");

			printf("GameResult >> \n");
			printf("���� �÷��̾� >> ");
			for (int i = 1; i <= playNum; i++)
			{
				if (i == NowPlayer)
				{
					continue;
				}
				printf("%d\t", i);
			}
			putchar('\n');
			printf("��� �÷��̾� >> %d\n\n", aimedPlayer);

			break;
		}

		bullet--;
		NowPlayer++;
		if (NowPlayer > playNum)
		{
			NowPlayer = 1;
		}

		printf("%d �÷��̾� ����!!!\n", aimedPlayer);
		printf("���� �Ѿ� ��  >> %d\n\n", bullet);
		if (bullet == 0)
		{
			printf("���� ����!!\n\n");
			break;
		}
		printf("���� �÷��̾� >> %d\n\n", NowPlayer);

		printf("�ƹ� Ű�� �Է� >> ");
		next = _getch();

		printf("\n\n");
	}

	return 0;
}