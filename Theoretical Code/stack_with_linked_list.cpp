#include<iostream>
using namespace std;

class Node {
public:
    double data;
    Node* next;
};

class Stack{
private:
    Node *head;
    int size;
    int capacity;
public:
    Stack(){    head = NULL;   size = 0; capacity = 100;    }

    void Push(double element){
        if (size == capacity)
            cout<<"Sorry, Stack is full" << endl;
        else {
            Node* newNode = new Node;
            newNode->data = element;
            newNode->next = head;
            head = newNode;
            size++;
        }
    }

    void Pop() {
        if (head == NULL)
            cout << "Sorry, the stack is empty => nothing to pop" << endl;
        else {
            head = head->next;
            size--;
        }
    }

    void display() {
        Node *temp = head;
        while(temp != NULL) {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack sl;
    sl.Push(1);
    sl.Push(2);
    sl.Push(5);
    sl.display();
    sl.Pop();
    sl.display();
}

