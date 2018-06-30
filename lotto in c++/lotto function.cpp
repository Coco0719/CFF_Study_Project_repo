#include "lotto header.h"

void winNumber(int num[])
{
	int index = 0;
	int inputNum;
	int flag = 0;

	while (index < 6)
	{
		inputNum = (rand() % 99) + 1; 

		// 같은 수를 판별하는 코드
		for (int i = 0; i < index; i++)
		{
			if (inputNum == num[i])
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

		num[index] = inputNum;

		index++;
	}

	cout << " LOTTO 숫자 선택을 완료!!\n" << endl;
}

void playerNumber(int num[])
{
	int index = 0;
	int inputNum;
	int flag = 0;

	while (index < 6)
	{
		cout << " [" << index + 1 << "] 번째 숫자를 선택해주세요 >> ";
		cin >> inputNum;

		// 같은 수를 판별하는 코드 && 1~99내의 숫자를 뽑았는저 검사
		if (inputNum > 99 || inputNum < 1)
		{
			continue;
		}
		for (int i = 0; i < index; i++)
		{
			if (inputNum == num[i])
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

		num[index] = inputNum;

		index++;
	}

	cout << " Player가 숫자 선택을 완료!!\n" << endl;
}

extern int cheakLottoNumber(int player[], int lotto[])
{
	int count = 0;

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (player[i] == lotto[j])
			{
				count++;
				break;
			}
		}
	}

	return count;
}

int lottoResultMoney(int equalNum)
{
	switch (equalNum)
	{
	case 0:
		return 0;
	case 1:
		return 5000;
	case 2:
		return 20000;
	case 3:
		return 50000;
	case 4:
		return 800000;
	case 5:
		return 5000000;
	case 6:
		return 200000000;
	}
}

void printNumber(int arr[], const char *string)
{
	cout << "   " << string;

	for (int i = 0; i < 6; i++)
	{
		cout << "\t" << arr[i];
	}
	cout << "\n" << endl;
}