#pragma once

#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>


extern void Intro(void);
extern int setQuestion(int count);
extern int playerAnswer(void);
extern int evaluate(int correctAnswer, int userAnswer);
extern void gameResult(double clock);