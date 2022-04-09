// print_list by idebtor@gmail.com

/*On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this programming assignment. Signed: 정예찬*/

//Lab 5 : Create print_list.cpp

#include <iostream>
void print_list(int *list, int n) {
	for (int i = 0; i < n; i++)
		std::cout << list[i] << " ";
	std::cout << std::endl;
}
