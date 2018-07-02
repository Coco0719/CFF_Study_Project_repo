#pragma once

#include <Windows.h>
#include <iostream>
#include <cstring>

#define MAX_BOOK 100
#define MAX_NAME 64

using namespace std;


extern enum BOOK {
	None,
	Register,
	Rent,
	Return,
	Search,
	ListOutput,
	Exit
};

extern struct book {
	char name[MAX_NAME];
	int fee;
	int number;
	bool rented;
};

extern void printMenu(void);
extern bool selectMenu(int *select);
extern bool registerBook(book books[], int *bookIndex);
extern bool rentBook(book books[], int *bookIndex);
extern bool returnBook(book books[], int *bookIndex);
extern bool searchBook(book books[], int *bookIndex);
extern bool outputList(book books[], int *bookIndex);