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

	printf("================= [러시안 룰렛] =================\n\n");


	printf("플레이어 수를 입력해주세요 [2 ~ 5] >> ");
	playNum = playerNumber();
	putchar('\n');

	printf("\n>> Next >>\n\n");

	printf("총알의 수를 입력해주세요 [1 ~ 5] >> ");
	bullet = bulletNumber();
	putchar('\n');

	printf("\n>> Next >>\n\n");

	printf("시작 플레이어를 설정해주세요 [1 ~ 5] >> ");
	NowPlayer = setStartPlayer(playNum);

	printf("\n>> Next >>\n\n");

	printf("=================== [게임 시작] ===================\n\n");

	while (true)
	{
		aimedPlayer = playerAimed(NowPlayer, playNum);

		printf("%d 플레이어 조준중 >> %d 플레이어 조준됨!! \n", NowPlayer, aimedPlayer);
		delayThreeSec();

		if (shotedPlayer(bullet) == 1)
		{
			printf("플레이어가 죽었습니다.\n\n");
			printf("=================== [게임 종료] ===================\n\n");

			printf("GameResult >> \n");
			printf("생존 플레이어 >> ");
			for (int i = 1; i <= playNum; i++)
			{
				if (i == NowPlayer)
				{
					continue;
				}
				printf("%d\t", i);
			}
			putchar('\n');
			printf("사망 플레이어 >> %d\n\n", aimedPlayer);

			break;
		}

		bullet--;
		NowPlayer++;
		if (NowPlayer > playNum)
		{
			NowPlayer = 1;
		}

		printf("%d 플레이어 생존!!!\n", aimedPlayer);
		printf("남은 총알 수  >> %d\n\n", bullet);
		if (bullet == 0)
		{
			printf("전원 생존!!\n\n");
			break;
		}
		printf("다음 플레이어 >> %d\n\n", NowPlayer);

		printf("아무 키나 입력 >> ");
		next = _getch();

		printf("\n\n");
	}

	return 0;
}