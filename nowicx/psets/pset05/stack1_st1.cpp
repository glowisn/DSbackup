/*On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this programming assignment. Signed: 정예찬*/

//stack1_st1.cpp - using a stack class in C++ STL

#include <iostream>
#include <stack>

using namespace std;

void printStack(stack<string> s);
void printStack_fromBottom(stack<string> s);


int main(){
	// int list[] = {1,2,3,4,5,0,6,0,0,7,0,0,0,8};
	string list[] = {"to", "be", "or", "not", "to", "-", "be", \
	"-", "-", "that", "-", "-", "-", "is"};

	stack<string> s;
	for(auto item : list){
		if(item != "-"){
			s.push(item);
		}else{
			cout << s.top() << ' ';
			s.pop();
		}
	}

	cout << "\nsize: " << s.size(); // 2
	cout << "\ntop : " << s.top(); // is (8)
	cout << "\nstack T: "; printStack(s); // is to (8 1)
	cout << "\nstack B: "; printStack_fromBottom(s); // to is (1 8)
	cout << "\nHappy Coding";

}

void printStack(stack<string> s){
	while (s.empty())return;
	cout << s.top() << ' ';
	string item = s.top();
	s.pop();
	printStack(s);
	s.push(item);
}

void printStack_fromBottom(stack<string> s){
	while (s.empty())return;
	string item = s.top();
	s.pop();
	printStack(s);
	s.push(item);
	cout << s.top() << ' ';
}
