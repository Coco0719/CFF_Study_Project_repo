#include "가위바위보 게임 헤더.h"

void playerSel(int *playerPic)
{
	do {
		cout << "1. 가위" << endl;
		cout << "2. 바위" << endl;
		cout << "3. 보" << endl;
		cout << "4. 종료" << endl;

		cout << "선택 >> ";
		cin >> *playerPic;
	} while (*playerPic > 4 || *playerPic < 1);
}



void AiSel(int *aiPic)
{
	*aiPic = (rand() % 4) + 1;
}

int cmpSrp(int playerPic, int aiPic)
{
	int diff = playerPic - aiPic;

	if (diff == 0)
	{
		return 0;
	}
	else if (diff == 1 || diff == -2)
	{
		return 1;
	}
	else if (diff == -1 || diff == 2)
	{
		return -1;
	}
}