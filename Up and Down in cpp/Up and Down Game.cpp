#include <stdio.h>
#include <conio.h>
#include <Windows.h>

int userInput(char *num10, char *num1);
int comChoice(int from, int to);

int main(void)
{
	// �Է¹��� ���� �ΰ�, �Է°� ���ÿ� *�� ����ؾ� �ϱ� ������ getch �Լ��� num1/10�� ������ ����
	char num10;
	char num1;
	
	int number;
	
	int count = 1;
	int comOutput;
	int from = 1;
	int to = 99;
	int score = 100;

	printf("������ >> ���� ���ڸ� �Է��ϼ��� (0 ~ 100) : ");
	number = userInput(&num10, &num1);

	putchar('\n'); putchar('\n');


	while (count <= 10)
	{
		comOutput = comChoice(from, to);
		printf("[%dȸ] ��ǻ�Ͱ� %d ~ %d ���� ���� ����!! >> %d\n\n", count, from, to, comOutput);
		putchar('\n');

		if (number > comOutput)
		{
			printf("�� ū �����Դϴ�!!\n\n");
			from = comOutput;	
		}
		else if (number < comOutput)
		{
			printf("�� ���� �����Դϴ�!!\n\n");
			to = comOutput;
		}
		else
		{
			printf("����!!! ������ %d\n", number);
			printf("���� ���� >> %d\n\n", score);
			break;
		}
		
		if (score == 0)
		{
			printf("����!!! ������ %d\n", number);
			printf("���� ���� >> 0\n\n");
		}
		printf("-------------------------------------------------------------\n");
		count++;
		score -= 10;
		Sleep(1000);
	}
	
	if(score == 0)
	{
		printf("����!!! ������ %d\n", number);
		printf("���� ���� >> 0\n\n");
	}

	return 0;
}


int comChoice(int from, int to)
{
	int difference = to - from;
	int comCho = (difference / 2);

	return (comCho + from); // from ~ to ���� ���� ����
}


int userInput(char *num10, char *num1)
{
	int userNum;

	do {
		*num10 = _getch();
		*num10 -= 48;
	} while ((*num10 > 9) || (*num10 < 0));
	printf("*");

	do {
		*num1 = _getch();
		*num1 -= 48;
	} while ((*num1 > 9) || (*num1 < 0));
	printf("*");

	userNum = (*num10 * 10) + *num1;

	return userNum;
}