#include "Sokovan hearder.h"

int main(void)
{
	system("mode con cols=80 lines=30");
	

	cursorHide();
	char mapArr[20][20];
	clock_t startTime;
	clock_t endTime;
	// This two array for star location
	// this code is for start exist 
	int heightArr[5] = { 5, 11, 11, 14, 14 };
	int widthArr[5] = { 1, 4, 8, 4, 8 };
	
	// this array for drawAssistView function about color 
	//int confirmKey[5] = {0, 0, 0, 0, 0};
	
	// loop for map selection
	PLAYER user = {};
	int choiceMap = 0;
	while (true)
	{
		system("cls");
		cout << endl;
		cout << " [1] Easy" << endl;
		cout << " [2] Normar" << endl;
		cout << " [3] Hard" << endl;
		cout << endl << " [1-3] Select Map Stage >> ";
		cin >> choiceMap;
		if(cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n'); 
			continue;
		}
replay:
		choiceMap = setMap(mapArr, choiceMap, &user);
		if (choiceMap != 0)
		{
			break;
		}
	}
	printMap(mapArr);
	drawMainView();
	drawAssistView();

	startTime = clock();
	int count;
	char dir;
	int c; // this var is for drawRepalyAndEsc function
	while (true)
	{
		c = 0;
		dir = _getch();
		// mapArr[세로][가로]
		switch (dir)
		{
		case Up:
			toDir(mapArr, &user, 1, 0, 0, 0);
			break;
		case Down: 	
			toDir(mapArr, &user, 0, 1, 0, 0);
			break;
		case Left:
			toDir(mapArr, &user, 0, 0, 1, 0);
			break;
		case Right:
			toDir(mapArr, &user, 0, 0, 0, 1);
			break;
		case Replay:
			c = 1;
			writeOnMainView(c);
			break;
		case Esc:
			c = -1;
			writeOnMainView(c);
			break;
		}
		if (c == 1 || c == -1)
		{
			int select = 0;
			while (true)
			{
				gotoxy(29, 3);
				cout << "             ";
				gotoxy(29, 3);

				cin >> select;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}
				break;
			}
			if (select == 2) // exit
			{
				break;
			}
			else if (select == 1) // replay
			{
				goto replay;
			}

			gotoxy(19, 2);  
			cout << "                       ";
			gotoxy(19, 3);
			cout << "                       ";
			drawMainView();
		}

		
		// this code is for star exist 
		char val;
		count = 0;
		for (int i = 0; i < 5; i++)
		{
			val = mapArr[heightArr[i]][widthArr[i]];
			if (val != '3' && val != '1')
			{
				mapArr[heightArr[i]][widthArr[i]] = '4';
			}
			if (val == '1')
			{
				count++;
			}
		}

		printMap(mapArr);
		writeInformation(&user, count);
		
		if (count == 5)
		{
			endTime = clock();
			double diffTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;

			gotoxy(61, 21);
			cout << "     ";
			gotoxy(61, 21);
			printf("%.2f", diffTime);

			Sleep(5000);
			break;
		}
	}

	system("cls");
	endView();
	cout << endl << "수고하셨습니다!!" << endl << endl;

	system("pause");

	return 0;
}

