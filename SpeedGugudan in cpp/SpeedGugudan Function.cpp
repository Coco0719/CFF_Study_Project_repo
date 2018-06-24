#include "SpeedGugudan.h"

extern void Intro(void)
{
	putchar('\n');
	putchar('\n');

	printf("\t\t[Speed Gugudan Game]\n\n");
	printf("\t1. ������ ������ �������� 2 ~ 9�� �Դϴ�.\n\n");
	printf("\t2. ������ �� 10���� �Դϴ�.\n\n");
	printf("\t3. �� ������ Ʋ���� Ż���Դϴ�.\n\n");
	printf("\t4. 10���� ��� ���� ��, ������ Ǫ�µ� ������ �ð��� �������� ����� ����մϴ�.\n\n");
	printf("\t�ƹ� Ű�� ������ ���� ȭ������ �̵��մϴ�.");

	_getch();

	system("cls");
}

extern int setQuestion(int count)
{
	int front = 2 + (rand() % 8);
	int back = 1 + (rand() % 9);

	printf("\t[%d] %d X %d = ", count, front, back);

	return front * back;
}

extern int playerAnswer(void)
{
	int answer;

	scanf_s("%d", &answer);
	printf("\n\n");

	return answer;
}

extern int evaluate(int correctAnswer, int userAnswer)
{
	if (correctAnswer == userAnswer)
	{
		return true;
	}
	else
	{
		return false;
	}
}

extern void gameResult(double clock)
{
	int score = 100;

	printf("\t[1] Total SEC : %.2f\n", clock);
	
	if (clock > 8)
	{
		score -= ((int)clock - 7) * 10;
	}
	else if(clock > 18)
	{
		score = 0;
	}
	printf("\t[2] Final Score : %d\n\n", score);
}