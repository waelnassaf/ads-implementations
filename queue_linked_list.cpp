#include <iostream>
#include <string>
using namespace std;
class Node {
public:
    static int counter;
    int id;
    double price;
    string name;
    Node* next;
    Node() {
        next = 0;
        id = ++counter;
    }
    Node(string name, double price) {
        this->name = name;
        this->price = price;
        id = ++counter;
        next = 0;
    }
};
int Node::counter = 0;
 
 
class List {
public:
    Node* head;
    Node* tail;
     
    List() {        head = tail = 0;    }
     
     
    void add_to_head(string name, double price) {
        if (head == 0)
            head = tail = new Node(name, price);
        else
        {
            Node* temp = new Node(name, price);
            temp->next = head;
            head = temp;
        }
    }
  
    void add_to_tail(string name, double price) {
        if (head == 0)
            head = tail = new Node(name, price);
        else
        {
            tail->next = new Node(name, price);
            tail = tail->next;
  
        }
    }
  
    double find_total(double &total) {
        total = 0;
        Node* temp = head;
        while (temp != 0) {
            total += temp->price;
            temp = temp->next;
        }
        return total;
    }
     
    void print() {
        if (head == 0)
            return;
        Node* temp = head;
        while (temp != 0) {
            cout << "+-+-+-+-+-+-+-+-" << endl;
            cout << temp->id << endl;
            cout << temp->name << endl;
            cout << temp->price << endl;
            temp = temp->next;
        }
        cout << "+-+-+-+-+-+-+-+-" << endl;
        cout << "Total number of elements: " << Node::counter << endl;
        cout << "===================================================" << endl;
    }
  
    bool delete_head() {
        if (head == 0)
            return false;
        if (head == tail)
        {
            delete head;
            head = tail = 0;
        }
        else
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        Node::counter--;
        return true;
    }
 
    void delete_tail() {
        if (head == 0)
            return;
        if (head == tail) {
            delete head;
            head = tail = 0;
        }
        else
        {
            Node* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = 0;
        }
         Node::counter--;
    }
};

class Queue {
    List l;
public:
    void enqueue(string name, double price) {
        l.add_to_tail(name, price);
    }
    
    void dequeue() {
        l.delete_head();
    }
    
    void get_front(string& name, double& price) {
        name = l.head->name;
        price = l.head->price;
    }

    void destroy() {
        while (l.head != 0)
            l.delete_head();
    }
    bool is_empty() {
        return l.head == 0;
    }
    void print() {
        l.print();
    }
};
int main()
{
    Queue q;
    q.enqueue("Rice", 500);
    q.enqueue("Rice2", 600);
    q.enqueue("Rice4", 800);
    q.enqueue("Rice3", 700);
    q.print();
     
     
    q.dequeue();
    
  
    q.print();


    cout << "The first item in the new queue is ";
    string name = "";
    double price = 0;
    q.get_front(name, price);
    cout << name << " with price of " << price << endl;

    return 0;
}
