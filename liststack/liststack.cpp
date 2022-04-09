// liststack.cpp
// This program implements a stack using singly-linked list
// without a head structure and without sentinel nodes. It simply links
// node to node. The caller is responsible for maintaining the the first
// node (head) of the list. Most functions need the first node to work
// with the list and returns the first node of the list since it may be
// changed inside of the functions.
//
// 2020/10/01 Created by idebtor@gmail.com

/*On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this programming assignment. Signed: Á¤¿¹Âù*/

#include "liststack.h"
//#include "stack.h"

// removes all the nodes from the list (which are destroyed),
// and leaving the container nullptr or its size to 0.
pNode clear(pNode p) {
	if (empty(p)) return nullptr;
	Node* curr = p;
	while (curr != nullptr) {
		Node* zap = curr;
		curr = curr->next;
		delete zap;
	}
	cout << "\n\tCleared...Happy Coding^^\n";
	return nullptr;
}

// returns the number of nodes in the list.
int size(pNode p) {
	if (empty(p)) return 0;
	int count = 0;
	pNode curr = p;
	while (curr != nullptr) {
		curr = curr->next;
		count++;
	}
	return count;
}

// sets the min and max values that are passed as references in the list
void minmax(pNode p, int& min, int& max) {
	if (empty(p)) {
		min = max = 0;
		return;
	}
	pNode curr = p;
	min = max = curr->data;
	while (curr != nullptr) {
		if (min < curr->data)
			min = curr->data;
		if (max > curr->data)
			max = curr->data;
		curr = curr->next;
	}
	
	return;
}

// returns true if the list is empty or no nodes.
// To remove all the nodes of a list, see clear().
bool empty(pNode p) {
	return p == nullptr;
}

// inserts a new node with val at the beginning of the list.
// This effectively increases the list size by N.
pNode push(pNode p, int val, int N) {
	DPRINT(cout << ">push val=" << val << " N="<< N << endl;);

	if (N == 1)
		p = new Node{ val, p };
	else {
		int count = 0;
		while (N > 0) {
			p = new Node{ count , p };
			N--; count++;
		}
	}
	DPRINT(cout << "<push size=" << size(p) << endl;);
	return p;
}

// removes N nodes in the list and returns the new first node.
// This deallocates the removed node, effectively reduces its size by N.
pNode pop(pNode p, int N) {
	DPRINT(cout << ">pop size=" << size(p) << " N="<< N << endl;);
	if (empty(p)) return nullptr;
	
	Node* curr = p;
	while ((N > 0) && (curr != nullptr)) {
		Node* zap = curr;
		curr = curr->next;
		delete zap;
		N--;
	}
	

	/*
	pNode zap = p;
	p = p->next;
	delete zap;
	*/

	DPRINT(cout << "<pop size=" << size(p) << endl;);
	return curr;
	//return p;
}

// returns the first node in the list. This does not destroy the node.
pNode top(pNode p) {
	if (empty(p)) return nullptr;
	return p;
}

// shows all the list elements, show_n items per line  if all is true.
// shows the first and the last show_n items in the list if all is false.
void show(pNode p, bool all, int show_n) {
	DPRINT(cout << "show(" << size(p) << ")\n";);
	if (empty(p)) {
		cout << "\n\tThe list is empty.\n";
		return;
	}

	//size for the linked list
	int size_p = size(p);

	//if all is true, print all stack simply with newline
	if (all == true) {
		int count = 0;
		for (pNode curr = p; curr != nullptr; curr = curr->next) {
			cout << " -> " << curr->data;
			count++;
			if ((count!=size_p) &&(count % show_n == 0)) cout << endl;
		}
	}

	//if all is false, depend on (size_p <= n*2) -> same with true
	// else show only n and after size - n times curr move
	if (all == false) {
		if (size_p <= show_n * 2) {
			int count = 0;
			for (pNode curr = p; curr != nullptr; curr = curr->next) {
				cout << " -> " << curr->data;
				count++;
				if ((count != size_p) && (count % show_n == 0)) cout << endl;
			}
		}
		else{
			pNode curr = p;
			for (int i = 0; i < show_n; i++) {
				cout << " -> " << curr->data;
				curr = curr->next;
			}
			cout << endl;
			cout << "...left out..." << endl;
			for (int i = 0; i < size_p - (2*show_n); i++) {
				curr = curr->next;
			}
			for (int i = 0; i < show_n; i++) {
				cout << " -> " << curr->data;
				curr = curr->next;
			}
		}
	}
	cout << endl;
}