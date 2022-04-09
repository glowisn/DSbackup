/*On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this programming assignment. Signed: 정예찬*/

//stack4_vec.cpp - using a vector in C++ STL

#include <iostream>
#include <vector>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif


struct Stack{
	vector<string> item;
};
using stack = Stack *;

stack newStack(){
	stack s = new Stack;
	return s;
}

void free(stack s){
	delete s;
}

int size(stack s){return s->item.size();}
bool empty(stack s){return s->item.empty();}
void pop(stack s){s->item.pop_back();}

string top(stack s){
	return s->item.back();
}
void push(stack s, string item){
	DPRINT(cout << "\nDebug : size: " << s->item.size() << endl;);
	return s->item.push_back(item);
}

void printStack(stack s){
	for(int i = 0; i <s->item.size(); i++){
		cout << s->item[i] << ' ';
	}

}

void printStack_fromBottom(stack s){
	for(int i = s->item.size()-1; i >= 0 ; i--){
		cout << s->item[i] << ' ';
	}

}


int main(){
	// int list[] = {1,2,3,4,5,0,6,0,0,7,0,0,0,8};
	string list[] = {"to", "be", "or", "not", "to", "-", "be", \
	"-", "-", "that", "-", "-", "-", "is"};

	stack s;
	s = newStack();
	for(auto item : list){
		if(item != "-"){
			push(s,item);
		}else{
			cout << top(s) << ' ';
			pop(s);
		}
	}

	cout << "\nsize: " << size(s); // 2
	cout << "\ntop : " << top(s); // is (8)
	cout << "\nstack T: "; printStack(s); // is to (8 1)
	cout << "\nstack B: "; printStack_fromBottom(s); // to is (1 8)
	cout << "\nHappy Coding";
	free(s);

}
