#include "lotto header.h"

void winNumber(int num[])
{
	int index = 0;
	int inputNum;
	int flag = 0;

	while (index < 6)
	{
		inputNum = (rand() % 99) + 1; 

		// ���� ���� �Ǻ��ϴ� �ڵ�
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

	cout << " LOTTO ���� ������ �Ϸ�!!\n" << endl;
}

void playerNumber(int num[])
{
	int index = 0;
	int inputNum;
	int flag = 0;

	while (index < 6)
	{
		cout << " [" << index + 1 << "] ��° ���ڸ� �������ּ��� >> ";
		cin >> inputNum;

		// ���� ���� �Ǻ��ϴ� �ڵ� && 1~99���� ���ڸ� �̾Ҵ��� �˻�
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

	cout << " Player�� ���� ������ �Ϸ�!!\n" << endl;
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