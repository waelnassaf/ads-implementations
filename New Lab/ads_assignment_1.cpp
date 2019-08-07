/*
|--------------------------------------------------------------------------
| ADSL Assignment 1 | Maximum Sum Problem.                                |
|--------------------------------------------------------------------------
| * You are provided with two sorted lists as input.
| * Those lists have some nodes in common.
| * Find a new list composed of the union of the nodes of those two lists.
| * To create the new list, you should take parts (paths of one or more nodes) from each list and merge them together.
| * You are allowed to switch between the two original lists only at intersections (same node in both lists).
| * in order to figure out the resulting list having the path that represents the greatest maximum total.
| Input:
|   * Two Sorted Linked Lists.
| Output:
|   * New list containing maximum sum path. (Still not solved)
|   * Location of switches between the 2 lists.
*/
#include <iostream>
using namespace std;
class Node {
public:
    int num;
    Node* next;
    Node(int data, Node* next = 0) {    this->num = data;  this->next = next;     }
    Node() {    this->next = 0;     }
};
class List {
public:
    Node* head;
    Node* tail;
    List() {    head = tail = 0;    }

    void AddToTail(int data) {
        if (head == 0) head = tail = new Node(data);
        else {
            tail->next = new Node(data);
            tail = tail->next;
            tail->next = 0;
        }
    }

    void Print() {
        Node* temp = head;
        if (temp == 0) cout << "Empty List\n";
        while(temp != 0) {
            cout << temp->num << "\t";
            temp = temp->next;
        }
        cout << "\n";
    }

};

List MaxSumPath(Node* head1, Node* head2)
{
    List    l;

    Node*   temp1   = 0;
    Node*   temp2   = 0;
    Node*   temp    = 0;
    Node*   result  = 0;
    int     sum1    = 0;
    int     sum2    = 0;

    while (head1 || head2) {

        temp1 = head1;
        temp2 = head2;
        sum1 = sum2 = 0;

        while (head1 && head2)
        {
            if (head1->num < head2->num)
            {
                sum1 += head1->num;
                head1 = head1->next;
            }
            else if (head2->num < head1->num)
            {
                sum2 += head2->num;
                head2 = head2->next;
            }
            else {
                break;
            }
        }

        if (head1 == 0)
        {
            while (head2){
                sum2 += head2->num;
                head2 = head2->next;
            }
        }

        if (head2 == 0)
        {
            while (head1){
                sum1 += head1->num;
                head1 = head1->next;
            }
        }

        if (sum1 >= sum2)
        {
            if (result == 0) {
                result = temp1;
                temp = head1;
            } else {
                temp->next = temp1;
                temp = head1;
            }
        }

        else if (sum1 < sum2) {
            if(result == 0) {
                result = temp2;
                temp = head2;
            } else {
                temp->next = temp2;
                temp = head2;
            }
        }

       if (head1 && head2 && temp) {
            head1 = head1->next;
            head2 = head2->next;
            temp->next = 0;
        }
    }


    while (result)
    {
        l.AddToTail(result->num);
        result = result->next;
    }
    return l;
}


int main() {

    List l1;
    l1.AddToTail(1);
    l1.AddToTail(3);
    l1.AddToTail(30);
    l1.AddToTail(90);
    l1.AddToTail(120);
    l1.AddToTail(240);
    l1.AddToTail(511);

    List l2;
    l2.AddToTail(0);
    l2.AddToTail(3);
    l2.AddToTail(12);
    l2.AddToTail(32);
    l2.AddToTail(90);
    l2.AddToTail(125);
    l2.AddToTail(240);
    l2.AddToTail(249);


    cout << "List 1 = ";
    l1.Print();
    cout << "List 2 = ";
    l2.Print();

    cout << "---------------------------" << endl;

    cout << "List 3 = ";

    List result = MaxSumPath(l1.head, l2.head);
    result.Print();

   return 0;
}




