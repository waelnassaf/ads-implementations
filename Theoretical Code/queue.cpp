#define MAX_SIZE 100
#include <iostream>
using namespace std;

class Queue {
private:
    int front;
    int rear;
    int data[MAX_SIZE];
public:
    Queue() {   front = -1; rear = -1;   }
    bool isEmpty();
    bool isFull();
    void Enqueue(int);
    bool Dequeue();
    int getFront();
};

bool Queue::isEmpty() {    return front == -1 && rear == -1;   }

bool Queue::isFull() {
    return ( (front - rear == 1) || (front == 0 && rear == MAX_SIZE));
}

void Queue::Enqueue(int item) {
        if(isFull())
            cout << "The queue is full, no space to add any item" << endl;
        else if(isEmpty()) {
            data[++rear] = item;
            front++;
        }
        else if (rear == MAX_SIZE - 1){
            rear = 0;
            data[rear] = item;
        }
        else
            data[++rear] = item;
}

bool Queue::Dequeue() {
    if (isEmpty()) return false;
    else if (front == rear){
        front = -1;
        rear = -1;
        return true;
    }
    else if (front == MAX_SIZE - 1) {
        front=0;
        return true;
    }
    else {
        front++;
        return true;
    }
}

int Queue::getFront() {
    return data[front];
}

int main() {

    Queue q1;
    q1.Enqueue(10);
    q1.Enqueue(20);
    q1.Enqueue(30);
    q1.Enqueue(40);
    q1.Dequeue();
    q1.Dequeue();
    q1.Dequeue();
    cout << q1.getFront() << endl;

    return 0;
}
