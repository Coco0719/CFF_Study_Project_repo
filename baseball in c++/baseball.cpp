#include "baseball hearder.h"

int main(void)
{
	srand((unsigned)time(NULL));
	int exit;

	while (true)
	{
		do {
			cout << " 1. ���ӽ���\n" << endl;
			cout << " 2. ��������\n" << endl;
			cout << " ���� >> ";
			cin >> exit;
		} while (exit > 2 || exit < 1);

		if (exit == 2)
		{
			break;
		}

		int strike = 0;
		int ball = 0;
		int player[3] = {};
		int ai[3] = {};
		
		setAiArr(ai);
		cout << " AI ���ÿϷ�!!\n\n Player�� 10���� ��ȸ�� �־����ϴ�!!\n\n" << endl;

		int count = 1;
		while (count <= 10)
		{
			cout << "-----------------\n Player [" << count << "] ���ý���!!\n" << endl;
			setPlayerArr(player);

			printArr(player);
			cheakResult(&strike, &ball, ai, player);

			cout << " strike >> " << strike << endl;
			cout << " ball   >> " << ball << endl;

			if (strike == 3)
			{
				cout << "����ϼ̽��ϴ�!!\n" << endl;
				
				cout << " P >>";
				for (int i = 0; i < 3; i++)
				{
					cout << "\t" << player[i];
				}
				
				cout << "\n C >>";
				for (int i = 0; i < 3; i++)
				{
					cout << "\t" << ai[i];
				}

				cout << " ����� ���� >> " << (10 - (count - 1)) * 10 << endl;
				cout << "\n\n" << endl;
				break;
			}

			if (count == 11)
			{
				cout << " ����� ���� >> 0\n\n" << endl;
			}
			count++;
		}
		
	}


	cout << "����ϼ̽��ϴ�!!\n\n" << endl;

	return 0;
}	