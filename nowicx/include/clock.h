/*
 On my honour, I pledge that I have neither received nor provided improper assistance in the
 completion of this assignment.
 Signed: _정예찬___Student Number: ___21700663______
*/

//clock.h - header file for clockDriver

#ifndef CLOCK_H
#define CLOCK_H

#include <iostream>
#include <iomanip>
#include <Windows.h>
struct Clock{
	int hr, min, sec;
};

using pClock = Clock*;
void tick(pClock ptr);
void show(pClock ptr, char ch = '\n');
void runs(pClock ptr, char ch = '\n');

#endif
