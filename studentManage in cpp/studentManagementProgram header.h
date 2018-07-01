#pragma once

#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <cstring>

#define MAX_STUDENT 10

#define MAX_NAME 32
#define PHONE_NUM 14 
#define ADDRESS 100

using namespace std;

extern struct student {
	char name[MAX_NAME];
	char phone[PHONE_NUM];
	char address[ADDRESS];
	int korean;
	int english;
	int math;
	int total;
	double average;
};

extern enum MENU {
	None,
	Insert,
	Delete,
	Search,
	Output,
	Exit
};

extern void printMenu(void);
extern bool selectMenu(int *select);
extern void studentInsert(student *student, int *studentIndex);
extern void studentDelete(student *student, int *studentIndex);
extern void studentSearch(student *student, int *studentIndex);
extern void studentOutput(student *student, int *studentIndex);