#include "가위바위보 게임 헤더.h"

int main(void)
{
	srand((unsigned int)time(NULL));
	
	int count = 0;
	int playerPic;
	int aiPic;
	int cmp;

	while (true)
	{
		count++;

		cout << count << "번째 게임\n" << endl;

		playerSel(&playerPic);
		AiSel(&aiPic);

		if (playerPic == 4)
		{
			break;
		}

		cmp = cmpSrp(playerPic, aiPic);
		if (cmp == 0)
		{
			cout << " 비겼습니다!\n" << endl;
		}
		else if (cmp == 1)
		{
			cout << " 이겼습니다!\n" << endl;
		}
		else if (cmp == -1)
		{
			cout << " 졌습니다!\n" << endl;
		}
		
		cout << "---------------------------\n" << endl;
	}

	cout << "\n 게임을 종료했습니다!\n" << endl;

	return 0;
}