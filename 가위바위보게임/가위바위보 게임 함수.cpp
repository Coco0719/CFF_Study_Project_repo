#include "���������� ���� ���.h"

void playerSel(int *playerPic)
{
	do {
		cout << "1. ����" << endl;
		cout << "2. ����" << endl;
		cout << "3. ��" << endl;
		cout << "4. ����" << endl;

		cout << "���� >> ";
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