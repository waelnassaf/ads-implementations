#define MAX_SIZE 100
#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};


class Queue {
private:
    Node *rear;
    Node *front;
public:
    Queue() {   rear = NULL;  front = NULL;   }

    void enqueue(int element) {
        Node *temp = new Node;
        temp->data = element;
        temp->next = NULL;

        if (front == NULL)
            front = rear = temp;
        else
            rear->next = temp;
        rear = temp;
    }

    bool dequeue() {
        if (front == NULL) return false;
        else {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
        return true;
    }

    void display() {
        if (front == NULL) cout << "Nothing to Display" << endl;
        else {
            Node *temp = front;
            while (temp != NULL) {
                cout << temp->data << endl;
                temp = temp->next;
            }
        }
    }
};


int main() {

    Queue q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.dequeue();
    q1.dequeue();
    q1.display();

    return 0;
}
