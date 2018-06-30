#include "lotto header.h"

int main(void)
{
	srand((unsigned)time(NULL));

	int winNums[6];
	int playerNums[6];
	int equalNumber = 0;
	int resultMoney = 0;

	winNumber(winNums);
	playerNumber(playerNums);

	equalNumber = cheakLottoNumber(playerNums, winNums);
	resultMoney = lottoResultMoney(equalNumber);

	printNumber(winNums, "lotto");
	printNumber(playerNums, "player");

	cout << " equal Number >> " << equalNumber << endl; 
	cout << " ´çÃ·±Ý >> " << resultMoney << "\n\n";

	return 0;
}