#include <iostream>
using namespace std;
class Node {
public:
    double data;
    Node* next;
};
class List {
public:
    Node *head;
    List() { head = NULL; }
    ~List();
    bool IsEmpty()    {        return head == NULL;    }
    bool InsertNode(int, double);
    int FindNode(double);
    int DeleteNode(double);
    void DisplayList();
};

int MaxAllowedIndex(Node* head) {
    int maxIndex = 0;
    Node* temp = head;
    while (temp != 0) {
        temp = temp->next;
        maxIndex++;
    }
    return maxIndex;
}

bool List::InsertNode(int index, double x) {
    if (index < 0) return false;
    if (index > 0 && head == NULL) return false;
    Node* newNode = new Node;
    newNode->data = x;
    if (index == 0) {
        newNode->next = head;
        head = newNode;
    }
    if(index >= 1) {
        int currIndex = 1;
        Node* currNode = head;
        index = index >= MaxAllowedIndex(head) ? MaxAllowedIndex(head) : index;

        while (currNode != NULL && currIndex < index) {
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
    int currIndex = 0;
    while(currNode!= NULL && currNode->data != x){
        currNode = currNode->next;
        currIndex++;
    }
    if (currNode != NULL)
        return currIndex;
    return -1;
}

int List::DeleteNode(double x) {
    Node* prevNode = NULL;
    Node* currNode = head;
    int currIndex = 0;
    while (currNode != NULL && currNode->data != x){
        prevNode = currNode;
        currNode = currNode->next;
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

List::~List() {
    Node* curr = head;
    while (curr != NULL){
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
    head = 0;
}

int main () {

    List l1;

    l1.InsertNode(0, 10);
    l1.InsertNode(9, 20);
    l1.InsertNode(1, 30);

    cout << l1.FindNode(20) << endl;
    cout << l1.DeleteNode(20) << endl;

    l1.DisplayList();

    l1.~List();

    cout << "———After Deletion———\n" << endl;
    l1.DisplayList();

    return 0;
}
