#include <iostream>
#include<string>
using namespace std;
 
class Node {
public:
    static int counter;
    int id;
    string name;
    double price;
    Node* next;
    Node() {id = ++counter; next = 0;}
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
     
    List() {head = tail = 0;}
  
    void add_to_head(string name, double price)
    {
        if (head == 0) {head = tail = new Node(name, price);}    
        else {
            Node* temp = new Node(name, price);
            temp->next = head;
            head = temp;
        }
    }
     
  
    void add_to_tail(string name, double price)
    {
        if (head == 0) {head = tail = new Node(name, price);}    
        else {
            tail->next = new Node(name, price);
            tail = tail->next;
        }
    }
     
    double find_total() {
        double total = 0;
        Node* temp = head;
        while(temp != 0) {
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
        cout << "Total number of nodes: " << Node::counter << endl;
        cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl;
    }
     
    void delete_head() {
        if (head == 0)
            return;
        if (head == tail)
            delete head;
        else {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        Node::counter--;
    }
     
         
    void delete_tail() {
        if (head == 0)
            return;
        if (head == tail)
            delete tail;
        else {
            Node* temp = head;
            while(temp->next != tail) {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = 0;
        }
        Node::counter--;
    }
     
     
    int find_or_delete(int id, bool op)
    {
        Node* temp = head;
        if (op) // then find
        {
            if (temp == 0)
                return -1;
            int index = 0;
            while(temp != 0 && temp->id != id) {
                temp = temp->next;
                index++;
            }
            return index;
        }
        else // then delete
        {
            if (head == 0)
                return -1;
            else if (head->id == id)
                {
                    delete_head();
                    return 0;
                }
            else if (tail->id == id)
                {
                    delete_tail();
                        int i = 0;
                        Node* temp = head;
                        while (temp != 0) {
                            temp = temp->next;
                            i++;
                        }
                        return i;
                }
                 
            else
          
                {
                    int c = 0;
                    Node* current = head;
                    Node* previous = 0;
                    while (current != tail && current->id != id) {
                        previous = current;
                        current = current->next;
                        c++;
                    }
                    if (current == tail)
                        return -1;
                    else
                        {
                            previous->next = current->next;
                            delete current;
                            return c;
                        }
                }
        }
    }
};
 
int main()
{
     
     
    List l;
    l.add_to_tail("Wael", 100);
    l.add_to_head("Wael", 300);
    l.add_to_head("Wael", 500);
    l.add_to_tail("Wael", 300);
     
    l.print();
     
    l.delete_head();

    
    l.print();

    return 0;
}