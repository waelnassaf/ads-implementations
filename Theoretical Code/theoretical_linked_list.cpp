#include <iostream>
using namespace std;

class Node {
public:
    double data;
    Node* next;
};

class List {
private:
    Node* head;
public:
    List() {    head = NULL;    }
    ~List();
    bool IsEmpty() {    return head == NULL;    }
    bool InsertNode(double, int);
    int FindNode(double);
    int DeleteNode(double);
    void DisplayList();
};

int MaxAllowedIndex(Node* temp) {
    int MaxIndex = 0;
    while (temp != NULL) {
        temp = temp->next;
        MaxIndex++;
    }
    return MaxIndex;
}

bool List::InsertNode(double data, int index = 0) {
    if (index < 0) return false;
//    if (index > 0 && head == NULL) return false; Old Fashioned.
    index = index > MaxAllowedIndex(head) ? MaxAllowedIndex(head) : index;
    Node* newNode = new Node;
    newNode->data = data;

    if (index == 0) {
        newNode->next = head;
        head = newNode;
    }

    else if (index >= 1) {
        int currIndex = 1;
        Node* currNode = head;
        while (currNode != NULL && currIndex < index) {
            currNode = currNode->next;
            currIndex++;
        }
        newNode->next = currNode->next;
        currNode->next = newNode;
    }
    return true;
}

int List::FindNode(double data) {
    Node* currNode = head;
    int currIndex = 0;
    while (currNode != NULL && currNode->data != data) {
        currNode = currNode->next;
        currIndex++;
    }
    if (currNode != NULL)
        return currIndex;
    return -1;
}

int List::DeleteNode(double data) {
    Node* currNode = head;
    Node* prevNode = NULL;
    int currIndex = 0;
    while (currNode != NULL && currNode->data != data) {
        prevNode = currNode;
        currNode = currNode->next;
        currIndex++;
    }
    if (currNode != NULL) {
        if (prevNode != NULL) {
            prevNode->next = currNode->next;
            delete currNode;
        } else {
            Node* temp = head->next;
            delete head;
            head = temp;
        }
        return currIndex;
    }
    return -1;
}

void List::DisplayList() {
    int counter = 0;
    if (IsEmpty()) {
        cout << "The list is empty\n";
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
        counter++;
    }
    cout << endl;
    cout << "Number of nodes are: " << counter << endl;
}

List::~List() {
    Node* curr = head;
    while (curr != NULL) {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
    head = 0;
}

int main() {

    List l;
    l.InsertNode(10.5, 0);
    l.InsertNode(20.5, 1);
    l.InsertNode(30.5, 7);
    l.InsertNode(40.5, 2);

    cout << "-------------" << endl;
    l.DisplayList();

    l.DeleteNode(10.5);
    cout << "-------------" << endl;
    l.DisplayList();

    cout << "+++++++++" << endl;
    cout << l.FindNode(30.5) << endl;

    cout << ",,,,,,,,,,,," << endl;
    l.~List();
    l.DisplayList();

    return 0;
}