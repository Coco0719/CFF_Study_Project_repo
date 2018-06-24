#include "SpeedGugudan.h"

int main(void)
{
	srand((unsigned)time(NULL));

	clock_t t1; // ���� �ð�
	clock_t t2; // ���� �ð�
	double diffClock;
	int count = 1; // ���� Ƚ��
	int correctAn; // ��ǻ�Ͱ� �� ������ �����Ѵ�
	int playerAn;
	bool correct;

	Intro();

	
	printf("\n\t[���� ����]\n\n");
	t1 = clock();
	while (count <= 10)
	{

		correctAn = setQuestion(count);
		playerAn = playerAnswer();

		correct = evaluate(correctAn, playerAn);

		if (correct == false)
		{
			printf("\t����ϼ̽��ϴ�.\n\n");
			return 0;
		}

		++count;
	}
	t2 = clock();

	diffClock = (double)(t2 - t1) / CLOCKS_PER_SEC;

	gameResult(diffClock);

	return 0;
}