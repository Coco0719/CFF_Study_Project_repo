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
		
		cout << " ����Ű \n w : ��\n s : �Ʒ�\n a : ����\n d : ������\n q : ����\n\n\n" << endl;
		cout << " �Է� >> ";
		
		dir = _getch();
		puzzleIndex = moveToDir(puzzle, dir, puzzleIndex);
		if(puzzleIndex == -1) // ���� ����
		{
			break;
		}
	}	

	cout << " ������ �����߽��ϴ�!!\n\n" << endl;

	return 0;
}