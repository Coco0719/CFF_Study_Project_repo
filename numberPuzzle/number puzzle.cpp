#include "number puzzle header.h"

int main(void)
{
	srand((unsigned)time(NULL));

	int puzzle[25] = {};
	int puzzleIndex = 24;
	char dir;

	setPuzzle(puzzle);
	shufflePuzzle(puzzle);

	while (true)
	{
		system("cls");

		printPuzzle(puzzle);
		
		cout << " 방향키 \n w : 위\n s : 아래\n a : 왼쪽\n d : 오른쪽\n q : 종료\n\n\n" << endl;
		cout << " 입력 >> ";
		
		dir = _getch();
		puzzleIndex = moveToDir(puzzle, dir, puzzleIndex);
		if(puzzleIndex == -1) // 종료 검출
		{
			break;
		}
	}	

	cout << " 게임을 종료했습니다!!\n\n" << endl;

	return 0;
}