#include <iostream>
using namespace std;

class Node
{
public:
    double data;
    Node* next;
};


class List {
private:
    Node *head;
public:
    List() { head = NULL; }
    ~List();

    bool IsEmpty()
    {
        return head == NULL;
    }

    bool InsertNode(int, double);
    int FindNode(double);
    int DeleteNode(double);
    void DisplayList();
};


bool List::InsertNode(int index, double x) {
    if (index < 0)
        return false;
    if (index > 0 && head == NULL)
        return false;

    Node* newNode = new Node;
    newNode->data = x;


    if (index == 0) {
        newNode->next = head;
        head = newNode;
    }

    if (index >= 1) {
        int currIndex = 1;
        Node* currNode = head;
        while (currNode != NULL && currIndex < index)
        {
            currNode = currNode->next;
            currIndex++;
        }
        newNode->next = currNode->next;
        currNode->next = newNode;
    }
    return true;
}




int List::FindNode(double x){

    Node* currNode = head;
    int currIndex=0;

    while(currNode!= NULL && currNode->data != x){
        currNode = currNode->next;
        currIndex++;
    }
    if (currNode != NULL)
        return currIndex;
    return -1;
}







int List::DeleteNode(double x){
    Node* prevNode= NULL;
    Node* currNode=head;
    int currIndex=0;
    while (currNode!= NULL && currNode->data != x){
        prevNode=currNode;
        currNode=currNode->next;
        currIndex++;
    }
    if (currNode) {
        if (prevNode) {
            prevNode->next = currNode->next;
            delete currNode;
        }
        else {
            head = currNode->next;
            delete currNode;
        }
        return currIndex;
    }

    return -1;
}





void List::DisplayList() {
    int counter = 0;
    Node* currNode = head;
    while (currNode != NULL) {
        cout << currNode->data << endl;
        currNode = currNode->next;
        counter++;
    }
    cout << "Number of nodes in the list: " << counter << endl;

}


List::~List()
{
    Node* currNode = head;
    Node* nextNode = NULL;

    while (currNode != NULL){
        nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
    }
}



int main () {


    List l1;

    l1.InsertNode(0, 21.2);
    l1.InsertNode(1, 321.2);
    l1.InsertNode(2, 61.2);
    l1.DisplayList();



    l1.~List();

    cout << "——————" << endl;
    l1.DisplayList();
    cout << "——————" << endl;



    return 0;
}
