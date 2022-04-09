// listnode.cpp
//
// Description:	This program implements a simple linked list of nodes
// without a head structure and without sentinel nodes. It simply links
// node to node. The caller is responsible for maintaining the the first
// node (head) of the list. Most functions need the first node to work
// with the list and returns the first node of the list since it may be
// changed inside of the functions.
//
// 03/13/19:	Created by idebtor@gmail.com
// 10/01/20:	show_timeit, inserrion sort, keep second half, zap duplicate
//

/*On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this programming assignment. Signed: Á¤¿¹Âù*/


#include <iomanip>
#include <cstdlib>
#include <stack>
#include "listnode.h"

#if 0
// a basic stack functinality only provided for pedagogical purpose
// To use STL stack, just comment out this section and inclucde <stack> above.
#include <vector>
template <typename T>
struct stack {
	vector<T> data;

	bool empty() const {
		return data.empty();
	}
	auto size() const {
		return data.size();
	}
	void push(T const& item) {
		data.push_back(item);
	}
	void pop() {
		if (data.empty())
			throw out_of_range("stack<>::pop(): pop stack");
		data.pop_back();
	}
	T top() const {
		if (data.empty())
			throw out_of_range("stack<>::top(): top stack");
		return data.back();
	}
};
#endif

// removes all the nodes from the list (which are destroyed),
// and leaving the container nullptr or its size to 0.
pNode clear(pNode p) {
	if (empty(p)) return nullptr;
	DPRINT(cout << "clear: ";);

	pNode curr = p;
	while (curr != nullptr) {
		pNode prev = curr;
		curr = curr->next;
		DPRINT(cout << prev->data << " ";);
		delete prev;
	}
	cout << "\n\tCleared...Happy Coding!\n";
	return nullptr;
}

// returns the number of nodes in the list.
int size(pNode p) {
	if (empty(p)) return 0;
	int count = 0;
	for (pNode c = p; c != nullptr; c = c->next, count++);
	return count;
}

// sets the min and max values that are passed as references in the list
void minmax(pNode p, int& min, int& max) {
	if (empty(p)) {
		min = max = 0;
		return;
	}

	//cout << "your code here\n";

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

// returns the last node of in the list.
pNode last(pNode p) {
	if (empty(p)) return nullptr;
	while (p->next != nullptr) p = p->next;
	return p;
}

// returns true if the list is empty or no nodes.
// To remove all the nodes of a list, see clear().
bool empty(pNode p) {
	return p == nullptr;
}

// inserts a new node with val at the beginning of the list.
// This effectively increases the list size by one.
Node* push_front(Node* p, int val) {
	DPRINT(cout << "><push_front val=" << val << endl;);
	if (empty(p)) return new Node{ val };
	return new Node{ val, p };
}

// adds a new node with val at the end of the list and returns the
// first node of the list. This effectively increases the list size by one.
pNode push_back(pNode p, int val) {
	DPRINT(cout << "><push_back val=" << val << endl;);

	if (empty(p)) return new Node{ val };

	pNode curr = p;
	while (curr->next != nullptr) {
		curr = curr->next;
	}
	curr->next = new Node{ val };

	return p;
}

// inserts a new node with val at the position of the node with x.
// The new node is actually inserted in front of the node with x.
// It returns the first node of the list.
// This effectively increases the container size by one.
pNode push(pNode p, int val, int x) {
	if (empty(p)) return push_front(p, val);
	if (p->data == x) return push_front(p, val);

	pNode curr = p;
	pNode prev = nullptr;

	//cout << "your code here : use while or for, but do not use if \n";

	while ( curr!=nullptr && curr->data != x) {
		prev = curr;
		curr = curr->next;
	}
	prev->next = new Node{ val, prev->next };

	return p;
}

// returns an extended random number of which the range is from 0
// to (RAND_MAX + 1)^2 - 1. // We do this since rand() returns too 
// small range [0..RAND_MAX) where RAND_MAX is usually defined as 
// 32767 in cstdlib. Refer to the following link for details
// https://stackoverflow.com/questions/9775313/extend-rand-max-range
unsigned long rand_extended(int range) {
	if (range < RAND_MAX) return rand();
	return rand() * RAND_MAX + rand();
}

// adds N number of new nodes at the front or back of the list.
// Values of new nodes are randomly generated in the range of
// [0..(N + size(p))]. 
// push_fp should be either a function pointer to push_front() 
// or push_back().
Node* push_N(Node* p, int N, Node* (*push_fp)(Node*, int)) {
	DPRINT(cout << ">push_N = " << N << endl;);

	int range = N + size(p);
	srand((unsigned)time(nullptr));

	//cout << "your code here \n";

	int random_number = 0;
	for (int i = 0; i < N; i++) {
		random_number = rand_extended(range) % range;
		p = push_fp(p, random_number);
	}


	DPRINT(cout << "<push_N = " << N << endl;);
	return p;
}

// inserts a new node in sorted ascending order in the list. 
// The basic strategy is to iterate down the list looking for the place to insert 
// the new node. That could be the end of the list, or a point just before a node 
// which is larger than the new node.
Node* push_sorted(Node* p, int val) {
	if (empty(p) || val <= p->data) return push_front(p, val);

	Node* curr = p;
	Node* prev = nullptr;
	// locate the node before the point of insertion
	
	//cout << "your code here \n";
	while (curr != nullptr) {
		if (val <= curr->data) {
			p = push(p, val, curr->data);
			return p;
		}
		prev = curr;
		curr = curr->next;
	}

	p = push_back(p, val);

	return p;
}

// sorts the singly linked list using insertion sortand returns a new list sorted.
// Repeatedly, invoke push_sorted() with a value in the list such that push_sorted() 
// returns a newly formed list head.
Node* insertion_sort(Node* p) {
	if (empty(p)) return nullptr;
	if (size(p) < 2) return p;

	Node* sorted = nullptr;
	
	//cout << "your code here \n";
	
	Node* curr = p;

	while (curr != nullptr) {
		sorted = push_sorted(sorted, curr->data);
		curr = curr->next;
	}

	clear(p);
	return sorted;
}

// removes the first node in the list and returns the new first node.
// This destroys the removed node, effectively reduces its size by one.
pNode pop_front(pNode p) {
	DPRINT(cout << ">pop_front size=" << size(p) << endl;);

	//cout << "your code here \n";
	pNode temp = p;
	p = p-> next;
	delete temp;

	return p;
}

// removes the last node in the list, effectively reducing the
// container size by one. This destroys the removed node.
pNode pop_back(pNode p) {
	DPRINT(cout << ">pop_back size=" << size(p) << endl;);
	if (empty(p)) return nullptr;

	//cout << "your code here \n";

	if (size(p) < 2) {
		p = pop_front(p);
		return p;
	}

	pNode curr = p;
	pNode prev = nullptr;
	while (curr->next != nullptr) {
		prev = curr;
		curr = curr->next;
	}
	prev->next = nullptr;
	delete curr;

	DPRINT(cout << "<pop_back size=" << size(p) << endl;);
	return p;
}

// deletes N number of nodes, starting from the beginning or back of the list. 
// It deletes all the nodes if N is zero which is the default or out of 
// the range of the list. 
Node* pop_N(Node* p, int N, Node* (*pop_fp)(Node*)) {
	DPRINT(cout << ">pop_N N=" << N << endl;);

	//cout << "your code here \n";

	for (int i = 0; i < N; i++) {
		p = pop_fp(p);
	}


	DPRINT(cout << "<pop_N size=" << size(p) << endl);
	return p;
}

// removes the first occurrence of the node with val from the list
pNode pop(pNode p, int val) {
	DPRINT(cout << ">pop val=" << val << endl;);
	if (empty(p)) return nullptr;    // nothing to delete

	if (p->data == val) return pop_front(p);

	//cout << "your code here : use while or for, but do not use if \n";

	pNode curr = p;
	pNode prev = nullptr;

	while (curr != nullptr && curr->data != val) {
		prev = curr;
		curr = curr->next;
	}

	while (curr == nullptr) return p;
	prev->next = curr->next;
	delete curr;

	//UNRESOLVED.

	DPRINT(cout << "<pop size=" << size(p) << endl;);
	return p;
}

// reverses a singly linked list using stack and returns the new head. 
// The last node becomes the head node. This function pushes all of its 
// nodes onto a stack. Then top/pop stack and relink the nodes again. 
// It does not create any new node, but recycles and relink them.
Node* reverse_using_stack(Node* head) {
	if (empty(head)) return nullptr;    // nothing to reverse
	stack<Node*> s;
	Node* curr = head;

	//cout << "your code here \n";

	while (curr != nullptr) {
		s.push(curr);
		curr = curr->next;
	}
	
	curr = s.top();
	head = curr;
	s.pop();

	while (!empty(s)) {		
		curr->next = s.top();
		s.pop();
		curr = curr->next;
	}

	curr->next = nullptr;

	return head;
}

// reverses a singly linked list and returns the new head. The last node
// becomes the head node. 
Node* reverse_in_place(Node* head) {
	if (empty(head)) return nullptr;    // nothing to reverse
	Node* prev = nullptr;
	Node* curr = head;

	//cout << "your code here \n";

	Node* temp = nullptr;
	while (curr != nullptr) {
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}

	return prev;
}

// removes the first half of the list and returns the new head of the list which 
// begins with the second half of the list. If there are an odd number of nodes, 
// remove less and keep more. For example, keep 5 nodes if there are 9 nodes. 
Node* keep_second_half(Node* p) {
	if (empty(p)) return nullptr;

	//cout << "your code here\n";

	//remove half
	int size_n = size(p) / 2;
	pNode curr = p;
	for (int i = 0; i < size_n;i++) {
		pNode prev = curr;
		curr = curr->next;
		DPRINT(cout << prev->data << " ";);
		delete prev;
	}

	return curr;
}

// removes consecutive items in the list, and leaves its neighbors unique.
// We can proceed down the listand compare adjacent nodes. When adjacent nodes 
// are the same, remove the second one.There's a tricky case where the node after 
// the next node needs to be noted before the deletion. Your implementation must 
// go through the list only once.
Node* zap_duplicates(Node* p) {
	if (empty(p)) return nullptr;

	//cout << "your code here\n";
	
	pNode curr = p->next;
	pNode prev = p;

	while (curr != nullptr) {
		if (curr->data == prev->data) {
			p = pop(p, prev->data);
		}
		prev = curr;
		curr = curr->next;
	}

	return p;
}

// shows the values of all the nodes in the list if all is true or
// the list size is less than or equal to show_n * 2. If there are more than
// (show_n * 2) nodes, then it shows only show_n number of nodes from
// the beginning and the end in the list.
void show(pNode p, bool all, int show_n) {
	DPRINT(cout << "show(" << size(p) << ")\n";);
	if (empty(p)) {
		cout << "\n\tThe list is empty.\n";
		return;
	}
	int i;
	pNode curr;
	const int N = size(p);

	if (all || N < show_n * 2) {
		for (i = 1, curr = p; curr != nullptr; curr = curr->next, i++) {
			cout << " -> " << curr->data;
			if (i % show_n == 0) cout << endl;
		}
		return;
	}
	else {
		pNode curr = p;
		for (int i = 0; i < show_n; i++) {
			cout << " -> " << curr->data;
			curr = curr->next;
		}
		cout << endl;
		cout << "...left out..." << endl;
		for (int i = 0; i < size(p) - (2 * show_n); i++) {
			curr = curr->next;
		}
		for (int i = 0; i < show_n; i++) {
			cout << " -> " << curr->data;
			curr = curr->next;
		}
	}
	// print the first show_n items
	//cout << "your code here \n";

	//cout << "\n...left out...\n";
	// print the last show_n items
	// move the pointer to the place where show_n items are left.

	//cout << "your code here \n";

	cout << "\n";
}
