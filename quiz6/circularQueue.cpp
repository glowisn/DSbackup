/*On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this programming assignment. Signed: 정예찬*/

#include <iostream>
#define SIZE 5
using namespace std;

struct Queue{
	int items[SIZE], front, rear;
};
using queue = Queue *;

queue newQueue(){
	queue q = new Queue;
	q->front = -1;
	q->rear = -1;
	return q;
}

bool full(queue q){
	if(q->front == 0 && q ->rear == SIZE -1)
	 return true;
	if(q->front == q->rear + 1) return true;
	return false;
}

bool empty(queue q){
	if (q->front == -1) return true;
	return false;
}

void enqueue(queue q, int element){
	if(full(q)){
		cout << "Queue is full" << endl;
	} else{
		if(q->front == -1) q->front = 0;
		q->rear = (q->rear + 1) % SIZE;
		q->items[q->rear] = element;
		cout << "enqueued: " << element << endl;
	}
}

int dequeue(queue q){
	int element;
	if(empty(q)){
		cout << "Queue is empty" << endl;
		return (-1);
	}
	else {
		element = q->items[q->front];
		if(q->front == q->rear){
			q->front = -1;
			q->rear = -1;
		}else{
			q->front=(q->front + 1) % SIZE;
		}
		return element;
	}
}

void display(queue q){
	int i;
	if(empty(q))
		cout << endl << "Empty Queue" << endl;
	else{
		cout << "Front[" << q->front <<"]\n";
		cout << "Items: ";
		for(i = q->front; i!=q->rear; i=(i+1)%SIZE)
			cout << q->items[i] << ' ';
		cout << q->items[i];
		cout << endl << " Rear[" << q->rear << "]\n";
	}
}
