#include <stdio.h>
#include <conio.h>
#include <Windows.h>

int userInput(char *num10, char *num1);
int comChoice(int from, int to);

int main(void)
{
	// 입력받을 숫자 두개, 입력과 동시에 *를 출력해야 하기 때문에 getch 함수로 num1/10에 저장할 예정
	char num10;
	char num1;
	
	int number;
	
	int count = 1;
	int comOutput;
	int from = 1;
	int to = 99;
	int score = 100;

	printf("출제자 >> 맞출 숫자를 입력하세요 (0 ~ 100) : ");
	number = userInput(&num10, &num1);

	putchar('\n'); putchar('\n');


	while (count <= 10)
	{
		comOutput = comChoice(from, to);
		printf("[%d회] 컴퓨터가 %d ~ %d 사이 숫자 예측!! >> %d\n\n", count, from, to, comOutput);
		putchar('\n');

		if (number > comOutput)
		{
			printf("더 큰 숫자입니다!!\n\n");
			from = comOutput;	
		}
		else if (number < comOutput)
		{
			printf("더 작은 숫자입니다!!\n\n");
			to = comOutput;
		}
		else
		{
			printf("성공!!! 정답은 %d\n", number);
			printf("최종 점수 >> %d\n\n", score);
			break;
		}
		
		if (score == 0)
		{
			printf("실패!!! 정답은 %d\n", number);
			printf("최종 점수 >> 0\n\n");
		}
		printf("-------------------------------------------------------------\n");
		count++;
		score -= 10;
		Sleep(1000);
	}
	
	if(score == 0)
	{
		printf("실패!!! 정답은 %d\n", number);
		printf("최종 점수 >> 0\n\n");
	}

	return 0;
}


int comChoice(int from, int to)
{
	int difference = to - from;
	int comCho = (difference / 2);

	return (comCho + from); // from ~ to 에서 숫자 고르기
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