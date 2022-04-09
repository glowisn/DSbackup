/*
 On my honour, I pledge that I have neither received nor provided improper assistance in the
 completion of this assignment.
 Signed: _정예찬___Student Number: ___21700663______
*/

//clock 4 - change line as time using /r, Sleep()

#include <iostream>
#include <iomanip>
#include <Windows.h>

struct Clock{
	int hr, min, sec;
};
using pClock = Clock*;
void tick(pClock ptr){
	ptr->sec++;
	if(ptr->sec==60){
		ptr->sec=0;
		ptr->min++;
	}
	if(ptr->min==60){
		ptr->min=0;
		ptr->min++;
	}
}

void show(pClock ptr, char ch = '\n'){
	std::cout.fill('0');
	std::cout << std::setw(2) << ptr -> hr << ":"
			 			<< std::setw(2) << ptr -> min << ":"
			 			<< std::setw(2) << ptr -> sec << ch;
}

void runs(pClock clk, char ch = '\n'){
	while(true){
		Sleep(1000);
		tick(clk);
		show(clk,ch);
	}
}
