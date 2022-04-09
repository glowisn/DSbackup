/*On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this programming assignment. Signed: 정예찬*/

//stack2_arr.cpp - using a fixed size array

#include <iostream>

using namespace std;

template<typename T>
struct Stack{
	T *item;
	int N;
	int capacity;
};
template<typename T>
using stack = Stack<T> *;

template<typename T>
stack<T> newStack(int capacity,T n){
	stack<T> s = new Stack<T>;
	s->item = new T[capacity];
	s->N = 0;
	s->capacity = capacity;
	return s;
}

template<typename T>
void free(stack<T> s){
	delete[] s->item;
	delete s;
}

template<typename T>
int size(stack<T> s){return s->N;}
template<typename T>
bool empty(stack<T> s){return s->N == 0;}
template<typename T>
void pop(stack<T> s){s->N--;}

template<typename T>
T top(stack<T> s){
	return s->item[s->N - 1];
}

template<typename T>
void push(stack<T> s, T item){
	s->item[s->N++] = item;
}

template<typename T>
void printStack(stack<T> s){
	for(int i = 0; i <s->N; i++){
		cout << s->item[i] << ' ';
	}

}

template<typename T>
void printStack_fromBottom(stack<T> s){
	for(int i = s->N-1; i >= 0 ; i--){
		cout << s->item[i] << ' ';
	}

}


int main(){
	int list[] = {1,2,3,4,5,0,6,0,0,7,0,0,0,8};
	//string list[] = {"to", "be", "or", "not", "to", "-", "be", \
	"-", "-", "that", "-", "-", "-", "is"};

	stack<int> s;
	s = newStack(sizeof(list),list[0]);
	for(auto item : list){
		if(item != 0){
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
