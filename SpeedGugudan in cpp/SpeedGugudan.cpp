#include "SpeedGugudan.h"

int main(void)
{
	srand((unsigned)time(NULL));

	clock_t t1; // 시작 시간
	clock_t t2; // 끝난 시간
	double diffClock;
	int count = 1; // 게임 횟수
	int correctAn; // 컴퓨터가 낸 문제를 저장한다
	int playerAn;
	bool correct;

	Intro();

	
	printf("\n\t[게임 시작]\n\n");
	t1 = clock();
	while (count <= 10)
	{

		correctAn = setQuestion(count);
		playerAn = playerAnswer();

		correct = evaluate(correctAn, playerAn);

		if (correct == false)
		{
			printf("\t고생하셨습니다.\n\n");
			return 0;
		}

		++count;
	}
	t2 = clock();

	diffClock = (double)(t2 - t1) / CLOCKS_PER_SEC;

	gameResult(diffClock);

	return 0;
}