#include <iostream>
using namespace std;

int main() {
	struct List {
		string who ="";
		char data='';
		List* link = nullptr;
	};

	List a, b, c;
	List *p, *q, *r;
	p = q = r = nullptr;

	
	//1
	p = &a;
	q = &b;
	r = &c;

	//2
	p->data = 'X';
	q->data = 'Y';
	r->data = 'Z';

	//3
	p->link = q;
	q->link = r;
	r->link = nullptr;

	return 0;
}