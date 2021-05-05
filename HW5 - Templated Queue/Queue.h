#include <iostream>
using namespace std;

template<class T>
class Queue {
private:
	T* array; // array to store queue elemnts
	int size; // Total size of queue
	int front; // First element of the queue
	int rear; // Last element of the queue
	int numOfElements; // Elements in the queue

public:
	// Constructor
	Queue(int qsize) {
		array = new T[qsize];
		size = qsize;
		front = 0;
		rear = -1;
		numOfElements = 0;
	}

	// Copy Constructor
	Queue(const Queue& q1) {
		array = q1.array;
		size = q1.size;
		front = q1.front;
		rear = q1.rear;
		Queue queueCopy(5);
		queueCopy.array = array;
		queueCopy.size = size;
		queueCopy.front = front;
		queueCopy.rear = rear;
	}

	// Destructor
	~Queue() {
		delete[] array;
	}

	// Copy assignment operator
	Queue& operator = (const Queue& q2) {
		q2 = Queue();
		q2.array = array;
		q2.size = size;
		q2.front = front;
		q2.rear = rear;
	}

	// Push: Inserts new element at the end of queue and assigns val to newly inserted element
	void Push(T value) {
		if (numOfElements == size) {
			cout << "Queue Full" << endl;
		}
		else {
			size++;
			rear = (rear + 1) % size;
			array[rear] = value;
			numOfElements++;
		}
	}

	// Pop: Removes front element of the queue and reduces size of the queue by one
	void Pop() {
		if (IsEmpty()) {
			cout << "Queue Empty" << endl;
		}
		else {
			front = (front + 1) % size;
			numOfElements--;
			size--;
		}
	}

	// Gets number of elements in the Queue
	int GetSize() {
		return numOfElements;
	}

	// IsEmpty (Returns True if queue is empty, else returns false)
	bool IsEmpty() {
		if (numOfElements == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	// Print: writes in console the contents of the queu
	void Print() {
		for (int i = 0; i < numOfElements; i++) {
			cout << array[i] << endl;
		}
	}

};



