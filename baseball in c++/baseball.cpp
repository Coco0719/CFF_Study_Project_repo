#include "baseball hearder.h"

int main(void)
{
	srand((unsigned)time(NULL));
	int exit;

	while (true)
	{
		do {
			cout << " 1. 게임시작\n" << endl;
			cout << " 2. 게임종료\n" << endl;
			cout << " 선택 >> ";
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
		cout << " AI 선택완료!!\n\n Player는 10번의 기회가 주어집니다!!\n\n" << endl;

		int count = 1;
		while (count <= 10)
		{
			cout << "-----------------\n Player [" << count << "] 선택시작!!\n" << endl;
			setPlayerArr(player);

			printArr(player);
			cheakResult(&strike, &ball, ai, player);

			cout << " strike >> " << strike << endl;
			cout << " ball   >> " << ball << endl;

			if (strike == 3)
			{
				cout << "고생하셨습니다!!\n" << endl;
				
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

				cout << " 당신의 점수 >> " << (10 - (count - 1)) * 10 << endl;
				cout << "\n\n" << endl;
				break;
			}

			if (count == 11)
			{
				cout << " 당신의 점수 >> 0\n\n" << endl;
			}
			count++;
		}
		
	}


	cout << "고생하셨습니다!!\n\n" << endl;

	return 0;
}	