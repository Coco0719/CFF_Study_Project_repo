#include "SpeedGugudan.h"

extern void Intro(void)
{
	putchar('\n');
	putchar('\n');

	printf("\t\t[Speed Gugudan Game]\n\n");
	printf("\t1. 문제로 나오는 구구단은 2 ~ 9단 입니다.\n\n");
	printf("\t2. 문제는 총 10문제 입니다.\n\n");
	printf("\t3. 한 문제라도 틀리면 탈락입니다.\n\n");
	printf("\t4. 10문제 모두 맞힐 시, 문제를 푸는데 측정한 시간을 바탕으로 결과를 출력합니다.\n\n");
	printf("\t아무 키나 누르면 게임 화면으로 이동합니다.");

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