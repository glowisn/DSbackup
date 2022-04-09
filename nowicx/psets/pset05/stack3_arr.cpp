/*On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this programming assignment. Signed: 정예찬*/

//stack3_arr.cpp - using a dynamic size array

#include <iostream>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif


struct Stack{
	string *item;
	int N;
	int capacity;
};
using stack = Stack *;

stack newStack(int capacity = 1){
	stack s = new Stack;
	s->item = new string[capacity];
	s->N = 0;
	s->capacity = capacity;
	return s;
}

void resize(stack s, int new_capacity){
	string *copied = new string[new_capacity];
	for(int i = 0; i < s->N; i++)
		copied[i] = s-> item[i];
	delete[] s->item;
	s->item = copied;
	s->capacity = new_capacity;
}

void free(stack s){
	delete[] s->item;
	delete s;
}

int size(stack s){return s->N;}
bool empty(stack s){return s->N == 0;}
void pop(stack s){
	s->N--;
	if(s->N == s->capacity / 4){
		resize(s,s->capacity / 2);
	}
}

string top(stack s){
	return s->item[s->N - 1];
}
void push(stack s, string item){
	if(s->N == s->capacity) resize(s,s->capacity * 2);
	s->item[s->N++] = item;
	DPRINT(cout << "\nDebug : size: " << s->N << "\tcapacity: " << s->capacity << endl;);
}

void printStack(stack s){
	for(int i = 0; i <s->N; i++){
		cout << s->item[i] << ' ';
	}

}

void printStack_fromBottom(stack s){
	for(int i = s->N-1; i >= 0 ; i--){
		cout << s->item[i] << ' ';
	}

}


int main(){
	// int list[] = {1,2,3,4,5,0,6,0,0,7,0,0,0,8};
	string list[] = {"to", "be", "or", "not", "to", "-", "be", \
	"-", "-", "that", "-", "-", "-", "is"};

	DPRINT(cout << "DEBUG MODE" << endl;);
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
