#include "���������� ���� ���.h"

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

		cout << count << "��° ����\n" << endl;

		playerSel(&playerPic);
		AiSel(&aiPic);

		if (playerPic == 4)
		{
			break;
		}

		cmp = cmpSrp(playerPic, aiPic);
		if (cmp == 0)
		{
			cout << " �����ϴ�!\n" << endl;
		}
		else if (cmp == 1)
		{
			cout << " �̰���ϴ�!\n" << endl;
		}
		else if (cmp == -1)
		{
			cout << " �����ϴ�!\n" << endl;
		}
		
		cout << "---------------------------\n" << endl;
	}

	cout << "\n ������ �����߽��ϴ�!\n" << endl;

	return 0;
}