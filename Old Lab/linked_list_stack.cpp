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
        cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl;
    }
 
    bool delete_head(string &name, double &price) {
        if (head == 0)
            return false;
        name = head->name;
        price = head->price;
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
class Stack {
    List l;
public:
    void push(string name, double price) {
        l.add_to_head(name, price);
    }
    void top(string& name, double& price) {
        name = l.head->name;
        price = l.head->price;
    }
    bool pop(string& name, double& price) {
        return l.delete_head(name, price);
    }
    void clear() {
        while (l.head != 0)
            l.delete_tail();
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
    Stack s;
    s.push("Rice", 500);
    s.push("Rice2", 600);
    s.push("Rice3", 700);
    s.push("Rice4", 800);
    s.print();
    
    string name = "";
    double price = 0;
    bool result = s.pop(name, price);
    while (result) {
        cout << name << " " << price << endl;
        cout << "----------"<<endl;
        result = s.pop(name, price);
    }
    
    
 
    return 0;
}