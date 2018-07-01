#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include <conio.h>

using namespace std;

extern void setPuzzle(int puzzle[]);
extern void shufflePuzzle(int puzzle[]);
extern void printPuzzle(int puzzle[]);
extern int moveToDir(int puzzle[], char dir, int index);