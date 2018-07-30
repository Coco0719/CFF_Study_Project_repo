#pragma once

#include <iostream>
#include <cstring>
#include <Windows.h>
#include <conio.h>
#include <stdio.h>
#include <ctime>
#include <stdlib.h>

#define MIN_WIDTH 10
#define MIN_HEIGHT 5

using namespace std;

extern struct PLAYER {
	int posX;
	int posY;
};

extern enum Object {
	Wall = 48,
	Rock = 49,
	Empty = 50,
	Player = 51,
	Location = 52
};

extern enum Dir {
	Up = 72,
	Down = 80,
	Left = 75,
	Right = 77,
	Replay = 32,
	Esc = 27	
};

extern void cursorHide(void);
extern void printMap(char mapArr[][20]);
extern int setMap(char mapArr[][20], char choicMap, PLAYER *user);
extern void gotoxy(int x, int y);
extern void toDir(char mapArr[][20], PLAYER *user, int u, int d, int l, int r);
extern void drawAssistView(void); // toDir function is called this function!!  // 50, 27~30
extern void drawMainView(void);
extern void writeOnMainView(int c);
extern void debugView(char mapArr[][20], PLAYER *user);
extern void writeInformation(PLAYER *user, int count);
extern void endView(void);