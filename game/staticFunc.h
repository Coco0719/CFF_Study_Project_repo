#pragma once

class staticFunc;

class staticFunc
{
public:
	static void gotoxy(int x, int y)
	{
		COORD pos;
		pos.X = x;
		pos.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}

	static void cursorHide(void)
	{
		CONSOLE_CURSOR_INFO cur_info;
		cur_info.dwSize = 1;
		cur_info.bVisible = false;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur_info);
	}

	static void delay(int nDelay)
	{
		int tick = GetTickCount();
		while (GetTickCount() - tick < nDelay){}
	}
};