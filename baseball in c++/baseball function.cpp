#include "baseball hearder.h"

extern void setAiArr(int ai[])
{
	int inputNum;
	int index = 0;
	int flag = 0;

	while (index != 3)
	{
		inputNum = (rand() % 9) + 1;

		for (int i = 0; i < index; i++)
		{
			if (inputNum == ai[i])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
		{
			flag = 0;
			continue;
		}

		ai[index] = inputNum;
		
		index++;
	}

}

void setPlayerArr(int player[])
{
	int inputNum;
	int index = 0;
	int flag;

	while(index < 3)
	{
		do {
			flag = 0;
			cout << (index + 1) << "번째 숫자 선택 >> ";
			cin >> inputNum;

			for (int i = 0; i < index; i++)
			{
				if (player[i] == inputNum)
				{
					flag = 1;
					break;
				}
			}
		} while (inputNum > 9 || inputNum < 1 || flag == 1);
		
		player[index] = inputNum;
		index++;
	}
}

void printArr(int player[])
{
	cout << " C >>\t*\t*\t*" << endl;

	cout << " P >>";
	for (int i = 0; i < 3; i++)
	{
		cout << "\t" << player[i];
	}
	cout << "\n\n" << endl;
}

void cheakResult(int *strike, int *ball, int ai[], int player[])
{
	*strike = 0;
	*ball = 0;

	for (int i = 0; i < 3; i++)
	{
		if (ai[i] == player[i])
		{
			(*strike)++;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (ai[i] == player[j])
			{
				(*ball)++;
			}
		}
	}
	*ball -= *strike;
}


