#include "Sokovan hearder.h"

void cursorHide(void)
{
	CONSOLE_CURSOR_INFO cur_info;
	cur_info.dwSize = 1;
	cur_info.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur_info);
}

void gotoxy(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void printMap(char mapArr[][20])
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			gotoxy(j * 2 + MIN_WIDTH, i + MIN_HEIGHT);
			switch (mapArr[i][j])
			{
			case Wall: // zero is wall
				cout << "■";
				break;
			case Rock: // one is a rock
				cout << "▥";
				break;
			case Empty: // two is empty space
				cout << "  ";
				break;
			case Player: // three is player
				cout << "◎";	
				break;
			case Location: // four is location where rocks should be
				cout << "☆";
				break;
			}
		}
		cout << endl;
	}
}

int setMap(char mapArr[][20], char choiceMap, PLAYER *user) 
{
	system("cls");

	switch (choiceMap)
	{
	case 1:
		strcpy_s(mapArr[0],  "0000000000000000000");
		strcpy_s(mapArr[1],  "0322222222222222000");
		strcpy_s(mapArr[2],  "0222222221222000000");
		strcpy_s(mapArr[3],  "0122200000000000000");
		strcpy_s(mapArr[4],  "0222222220000000000");
		strcpy_s(mapArr[5],  "0422222222222000000");
		strcpy_s(mapArr[6],  "0220022000022200000");
		strcpy_s(mapArr[7],  "0220222200022120000");
		strcpy_s(mapArr[8],  "0000002200002220000");
		strcpy_s(mapArr[9],  "0000002200002200000");
		strcpy_s(mapArr[10], "0022222222022200000");
		strcpy_s(mapArr[11], "0022422242002200000");
		strcpy_s(mapArr[12], "0022221222000000000");
		strcpy_s(mapArr[13], "0022222212000000000");
		strcpy_s(mapArr[14], "0022422242000000000");
		strcpy_s(mapArr[15], "0022222222000000000");
		strcpy_s(mapArr[16], "0000000000000000000");
		strcpy_s(mapArr[17], "0000000000000000000");
		strcpy_s(mapArr[18], "0000000000000000000");
		strcpy_s(mapArr[19], "0000000000000000000");
		user->posX = 1;
		user->posY = 1;
		return 1;
	case 2:
		return 2;
	case 3:
		return 3;
	default:
		return 0;
	}
}

void drawMainView(void)
{
	// up / down
	gotoxy(16, 1);
	for (int j = 0; j < 26; j++)
	{
		printf("%c", 6);
	}
	gotoxy(16, 4);
	for (int j = 0; j < 26; j++)
	{
		printf("%c", 6);
	}
	// left / right
	for (int j = 2; j < 4; j++)
	{
		gotoxy(15, j);
		printf("%c", 5);
	}
	for (int j = 2; j < 4; j++)
	{
		gotoxy(42, j);
		printf("%c", 5);
	}

	gotoxy(15, 1);
	printf("%c", 1);
	gotoxy(15, 4);
	printf("%c", 3);
	gotoxy(42, 1);
	printf("%c", 2);
	gotoxy(42, 4);
	printf("%c", 4);

	gotoxy(19, 2);
	cout << "Sokovan Game";
	gotoxy(19, 3);
	cout << "Enjoy your play!!";
}

void toDir(char mapArr[][20], PLAYER *user, int u, int d, int l, int r)
{
	// 벽(0) 돌(1) 공간(2) 플레이어(3) 별(4) 
	// 빈 공간(2) 이면 갈 수 있따
	// 돌(1) 번일때, 돌 앞이 벽인지 검사, 맞으면 못가게
	// 아니면, 돌이랑 나 움직이게
	// 마지막으로 그것도 아니면 못가게
	int posX = user->posX;
	int posY = user->posY;

	if (u == 1)
	{
		posY--;
	}
	else if (d == 1)
	{
		posY++;
	}
	else if (l == 1)
	{
		posX--;
	}
	else if (r == 1)
	{
		posX++;
	}
	
	// 벽(0) 돌(1) 공간(2) 플레이어(3) 별(4) 
	/*
	1. 앞에 있는것이 공간 혹은 별이면 갈 수 있다
	2. else if + if: 앞에 있는게 돌이고 그 앞에있는게 벽이면 못움직인다
	3. 그게 아니면 : 앞에 있는게 돌이고, 그 앞에 있는게 벽이 아니면 움직일 수 있다
	*/
	if (mapArr[user->posY - u + d][user->posX - l + r] == '2' || mapArr[user->posY - u + d][user->posX - l + r] == '4')
	{
		mapArr[user->posY - u + d][user->posX - l + r] = mapArr[user->posY][user->posX];
		mapArr[user->posY][user->posX] = '2';
		user->posX = posX;
		user->posY = posY;
		
		return;
	}
	else if (mapArr[user->posY - u + d][user->posX - l + r] == '1')
	{
		if (mapArr[user->posY + (-u + d) * 2][user->posX + (-l + r) * 2] == '0')
		{
			return;
		}
		else if (mapArr[user->posY + (-u + d) * 2][user->posX + (-l + r) * 2] == '2' || mapArr[user->posY + (-u + d) * 2][user->posX + (-l + r) * 2] == '4')
		{
			mapArr[user->posY + (-u + d) * 2][user->posX + (-l + r) * 2] = mapArr[user->posY - u + d][user->posX - l + r];
			mapArr[user->posY - u + d][user->posX - l + r] = mapArr[user->posY][user->posX];
			mapArr[user->posY][user->posX] = '2';
			user->posX = posX;
			user->posY = posY;
			// 벽(0) 돌(1) 공간(2) 플레이어(3) 별(4) 

			return;
		}
	}
}

void writeOnMainView(int c)
{
	gotoxy(19, 2);
	cout << "                  ";
	gotoxy(19, 3);
	cout << "                  ";
	if (c == 1)
	{
		gotoxy(19, 2);
		cout << "if you do, select '1'";
		gotoxy(19, 3);
		cout << "replay >> ";
	}
	else if (c == -1)
	{
		gotoxy(19, 2);
		cout << "if you do, select '2'";
		gotoxy(19, 3);
		cout << "exit   >> ";
	}
}

void drawAssistView(void) // toDir function is called this function!!  // 50, 
{
	for (int i = 0; i < 20; i++)
	{
		gotoxy(50, 5 + i);
		printf("%c", 5);
		gotoxy(70, 5 + i);
		printf("%c", 5);
	}

	for (int i = 0; i < 21; i++)
	{
		gotoxy(50 + i, 5);
		printf("%c", 6);
		gotoxy(50 + i, 7);
		printf("%c", 6);
		gotoxy(50 + i, 15);
		printf("%c", 6);
		gotoxy(50 + i, 24);
		printf("%c", 6);
	}
	// edge
	gotoxy(50, 5);
	printf("%c", 1);
	gotoxy(50, 24);
	printf("%c", 3);
	gotoxy(70, 5);
	printf("%c", 2);
	gotoxy(70, 24);
	printf("%c", 4);

	// left side
	gotoxy(50, 7);
	printf("%c", 25);
	gotoxy(50, 15);
	printf("%c", 25);

	// right side
	gotoxy(70, 7);
	printf("%c", 23);
	gotoxy(70, 15);
	printf("%c", 23);

	gotoxy(55, 6);
	cout << "Assist View";
	gotoxy(59, 9);
	cout << "↑";
	gotoxy(59, 13);
	cout << "↓";
	gotoxy(55, 11);
	cout << "←";
	gotoxy(63, 11);
	cout << "→";

	gotoxy(52, 17);
	cout << "Pos   >> (  ,  )";// 62~63 / 65~66
	
	gotoxy(52, 19);
	cout << "Count >> ";
	gotoxy(52, 21);
	cout << "Time  >> ????";

	gotoxy(10, 26);
	cout << "Exit >> press esc key";
	gotoxy(10, 27); 
	cout << "Replay >> press space bar key";

	
}

void writeInformation(PLAYER *user, int count)
{
	gotoxy(62, 17);
	cout << "  ";
	gotoxy(65, 17);
	cout << "  ";
	
	gotoxy(62, 17);
	cout << user->posX;
	gotoxy(65, 17);
	cout << user->posY;

	gotoxy(61, 19);
	cout << count;
}
	
void endView(void)
{
	char printTemp[256];
	FILE *fFile;
	fopen_s(&fFile, "bear.txt", "rt");
	if (fFile == NULL)
	{
		cout << "실패" << endl;
		return ;
	}

	while (fgets(printTemp, 255, fFile) != NULL)
	{
		printf(printTemp);
	}
	puts("");

	fclose(fFile);
}

void debugView(char mapArr[][20], PLAYER *user)
{
	for (int i = 0; i < 20; i++)
	{
		gotoxy(50, 5 + i);//
		for (int j = 0; j < 20; j++)
		{
			cout << mapArr[i][j] << " ";
		}
		cout << endl;
	}
	gotoxy(50, 26);
	cout << "mapArr[user.posY][user.posX] >> " << mapArr[user->posY][user->posX];
	gotoxy(50, 27);
	cout << "user.posX >> " << user->posX;
	gotoxy(50, 28);
	cout << "user.posY >> " << user->posY;
	gotoxy(50, 29);
	cout << "mapArr[user.posY][user.posX] + U >> " << mapArr[user->posY - 1][user->posX];
	gotoxy(50, 30);
	cout << "mapArr[user.posY][user.posX] + U + 2 >> " << mapArr[user->posY - 2][user->posX];
	gotoxy(50, 31);
	cout << "mapArr[user.posY][user.posX] + D >> " << mapArr[user->posY + 1][user->posX];
	gotoxy(50, 32);
	cout << "mapArr[user.posY][user.posX] + D + 2 >> " << mapArr[user->posY + 2][user->posX];
	gotoxy(50, 33);
	cout << "mapArr[user.posY][user.posX] + L >> " << mapArr[user->posY][user->posX - 1];
	gotoxy(50, 34);
	cout << "mapArr[user.posY][user.posX] + L >> " << mapArr[user->posY][user->posX - 2];
	gotoxy(50, 35);
	cout << "mapArr[user.posY][user.posX] + R >> " << mapArr[user->posY][user->posX + 1];
	gotoxy(50, 36);
	cout << "mapArr[user.posY][user.posX] + R >> " << mapArr[user->posY][user->posX + 2];
}
