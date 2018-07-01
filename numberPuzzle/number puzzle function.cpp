#include "number puzzle header.h"

void setPuzzle(int puzzle[])
{
	for (int i = 0; i < 24; i++)
	{
		puzzle[i] = i + 1;
	}

	puzzle[24] = INT_MAX;
}

void shufflePuzzle(int puzzle[])
{
	int ranIndex1;
	int ranIndex2;
	int tmp;

	for (int i = 0; i < 50; i++)
	{
		ranIndex1 = (rand() % 24);
		ranIndex2 = (rand() % 24);

		tmp = puzzle[ranIndex1];
		puzzle[ranIndex1] = puzzle[ranIndex2];
		puzzle[ranIndex2] = tmp;
	}
}

void printPuzzle(int puzzle[])
{
	for (int i = 0; i < 25; i += 5)
	{
		for (int j = 0; j < 5; j++)
		{
			if (puzzle[j + i] != INT_MAX)
			{
				cout << "\t" << puzzle[j + i];
			}
			else if (puzzle[j + i] == INT_MAX)
			{
				cout << "\t *";
			}
		}
		putchar('\n');
	}
}

int moveToDir(int puzzle[], char dir, int index)
{
	int tmp;
	int toIndex = index;
	int fromIndex = index;

	switch (dir)
	{
	case 'q':
	case 'Q':
		return -1;

	case 'w':
	case 'W':
		if (fromIndex >= 0 && fromIndex <= 4)
		{
			return index;
		}

		toIndex -= 5;
		tmp = puzzle[fromIndex];
		puzzle[fromIndex] = puzzle[toIndex];
		puzzle[toIndex] = tmp;
		break;

	case 's':
	case 'S':
		if (fromIndex >= 20 && fromIndex <= 24)
		{
			return index;
		}
		toIndex += 5;
		tmp = puzzle[fromIndex];
		puzzle[fromIndex] = puzzle[toIndex];
		puzzle[toIndex] = tmp;
		break;

	case 'a':
	case 'A':
		if ((fromIndex % 5) == 0)
		{
			return index;
		}
		toIndex -= 1;
		tmp = puzzle[fromIndex];
		puzzle[fromIndex] = puzzle[toIndex];
		puzzle[toIndex] = tmp;
		break;

	case 'd':
	case 'D':
		if ((fromIndex % 5) == 4)
		{
			return index;
		}
		toIndex += 1;
		tmp = puzzle[fromIndex];
		puzzle[fromIndex] = puzzle[toIndex];
		puzzle[toIndex] = tmp;
		break;
	}

	return toIndex;
}