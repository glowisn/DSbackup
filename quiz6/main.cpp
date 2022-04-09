#include "circularQueue.cpp"

int main(){
	queue q = newQueue();
	dequeue(q);
	enqueue(q, 1);
	enqueue(q, 2);
	enqueue(q, 3);
	enqueue(q, 4);
	enqueue(q, 5);
	enqueue(q, 6);
	display(q);
	int elem = dequeue(q);
	if (elem != -1)
		cout << "dequeued: " << elem << endl;
	display(q);
	enqueue(q, 7);
	display(q);
	enqueue(q, 8);
	dequeue(q);
	dequeue(q);
	display(q);
	return 0;

}
