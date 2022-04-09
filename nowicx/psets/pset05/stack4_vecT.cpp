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


template<typename T>
struct Stack{
	vector<T> item;
};
template<typename T>
using stack = Stack<T> *;

template<typename T>
stack<T> newStack(T n){
	stack<T> s = new Stack<T>;
	return s;
}

template<typename T>
void free(stack<T> s){
	delete s;
}

template<typename T>
int size(stack<T> s){return s->item.size();}
template<typename T>
bool empty(stack<T> s){return s->item.empty();}
template<typename T>
void pop(stack<T> s){s->item.pop_back();}

template<typename T>
T top(stack<T> s){
	return s->item.back();
}
template<typename T>
void push(stack<T> s, T item){
	DPRINT(cout << "\nDebug : size: " << s->item.size() << endl;);
	return s->item.push_back(item);
}

template<typename T>
void printStack(stack<T> s){
	for(int i = 0; i <s->item.size(); i++){
		cout << s->item[i] << ' ';
	}

}

template<typename T>
void printStack_fromBottom(stack<T> s){
	for(int i = s->item.size()-1; i >= 0 ; i--){
		cout << s->item[i] << ' ';
	}

}


int main(){
	int list[] = {1,2,3,4,5,0,6,0,0,7,0,0,0,8};
	//string list[] = {"to", "be", "or", "not", "to", "-", "be", \
	"-", "-", "that", "-", "-", "-", "is"};

	stack<int> s = newStack(list[0]);
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
