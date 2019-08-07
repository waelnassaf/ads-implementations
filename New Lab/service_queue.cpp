#include<iostream>
#include<string>
using namespace std;
#define max_size  100
class queue {
private:
	int front;
	int rear;
	int data[max_size];
public:
	int size;
	queue() {
		size = 0;
		front = rear = -1;
	}
	bool Is_Empty() {
		return(rear == -1 && front == -1);
	}
	bool Is_Full() {
		return(front - rear == 1) || (rear == max_size - 1 && (front == 0));
	}
	int getfront() {
		int temp;
		if (Is_Empty())
			return -1;
		else if (front == rear) {
			temp = data[front];
			return temp;
		}
		else if (front == max_size - 1) {
			temp = data[front];
			return temp;
		}
		else {
			temp = data[front];
			return temp;
		}
	}
	void enqueue(int item) {
		size++;
		if (Is_Full()) {
			cout << "The queue is full, no space to add any item" << endl;
			size--;
		}
		else if (Is_Empty()) {
			data[++rear] = item;
			front++;
		}
		else if (rear == max_size - 1) {
			rear = 0;
			data[rear] = item;
		}
		else
			data[++rear] = item;
	}

	int dequeue() {
		size--;
		int temp;
		if (Is_Empty()) {
			size++;
			return false;
		}
		else if (front == rear) {
			temp = data[front];
			front = -1; rear = -1;
			return temp;
		}
		else if (front == max_size - 1) {
			temp = data[front];
			front = 0;
			return temp;
		}
		else {
			temp = data[front];
			front++;
			return temp;
		}
	}

};

class node {
public:
	static int counter;
    int id;
    double priority;
	string name;
	node* next;
	node() {
		next = 0;
		id = ++counter;
	}
	node(string name, double priority, node* next = 0) {
		this->name = name;
		this->priority = priority;
		this->next = next;
		id = ++counter;
	}
};
int node::counter = 0;
class list {
public:
	node* head;
	node* tail;
	list() {
		head = tail = 0;
	}
	//insert to head
	void AddToHead(string name, double priority) {
		if (head == 0)
			head = tail = new node(name, priority,0);
		else
		{
			node* temp = new node(name, priority);
			temp->next = head;
			head = temp;

			//head = new node(name, priority, head);
		}
	}

	//AddToTail
	void AddToTail(string name, double priority) {
		if (head == 0)
			head = tail = new node(name, priority);
		else
		{
			/*node* temp = head;
			while (temp->next != 0) {
				temp = temp->next;
			}
			node* newNode = new node(name, priority);
			temp->next = newNode;
			newNode->next = 0;*/
			tail->next = new node(name, priority, 0);
			tail = tail->next;
		}
	}

	int FindTotal(double &total) {
		total = 0;
		int counter = 0;
		node* temp = head;
		while (temp != 0) {
			total += temp->priority;
			counter++;
			temp = temp->next;
		}
		return counter;
	}
	void Print() {
		node* temp = head;
		while (temp != 0) {
			cout << temp->priority << endl;
			temp = temp->next;
		}
	}

	bool DeleteHead(string &name, double &priority) {
		if (head == 0)
			return false;
		name = head->name;
		priority = head->priority;
		if (head == tail)
		{
			delete head;
			head = tail = 0;
		}
		else
		{
			node* temp = head;
			head = head->next;
			delete temp;
		}
		return true;
	}
	void DeleteTail() {
		if (head == 0)
			return;
		if (head == tail) {
			delete head;
			head = tail = 0;
		}
		else
		{
			node* temp = head;
			while (temp->next != tail) {
				temp = temp->next;
			}
			delete tail;
			tail = temp;
			tail->next = 0;
		}

	}

};
class queueLL{
	public:
	list l;
	queueLL(){
		l.head = l.tail =0;
	}
	//head 3-2-2-1-1 tail
	void enqueue(string name,double priority){
		if(l.head==0 || priority>=l.head->priority)
			l.AddToHead(name,priority);
		else if(priority<l.tail->priority)
			l.AddToTail(name,priority);
		else
		{
			node* temp = l.head;
			node* newNode = new node(name,priority);
			while(temp->next != 0 && priority<temp->next->priority)
				temp= temp->next;
			newNode->next = temp->next;
			temp->next = newNode;
		}
	}
	double dequeue(){
		if(l.tail !=0){
		double pr = l.tail->priority;
		l.DeleteTail();
		return pr;
		}
	}
	void Print(){
		l.Print();
	}
	bool isEmpty(){
		return l.head ==0;
	}
};
void Enter(queue &q1, queue &q2, queue &q3, queueLL &MainQ) {
	int f1 = q1.getfront();
	int f2 = q2.getfront();
	int f3 = q3.getfront();
	int s1 = q1.size;
	int s2 = q2.size;
	int s3 = q3.size;

	double factor1 = 0.65*f1 + 0.35*s1;
	double factor2 = 0.65*f2 + 0.35*s2;
	double factor3 = 0.65*f3 + 0.35*s3;
	int temp;
	if (factor1 > factor2 &&factor1 > factor3) {
		 temp= q1.getfront();
		 q1.dequeue();
	}
	else if (factor2 > factor1 &&factor2 > factor3)
	{
		temp = q2.getfront();
		q2.dequeue();
	}
	else {
		temp = q3.getfront();
		q3.dequeue();
	}

	MainQ.enqueue("x",temp);

}
void main() {


	queue q1;
	q1.enqueue(5);
	q1.enqueue(4);
	q1.enqueue(12);

	queue q2;
	q2.enqueue(6);
	q2.enqueue(23);
	q2.enqueue(1);

	queue q3;
	q3.enqueue(10);
	q3.enqueue(3);
	q3.enqueue(2);

	queueLL m;
	Enter(q1, q2, q3, m);
	Enter(q1, q2, q3, m);
	Enter(q1, q2, q3, m);
	Enter(q1, q2, q3, m);
	Enter(q1, q2, q3, m);
	Enter(q1, q2, q3, m);
	Enter(q1, q2, q3, m);

	/*queueLL q;
	int s=100;
	while(s>0){
		q.enqueue("x",rand());
		s--;
	}
	q.Print();
	system("pause");*/

	int r = m.dequeue();
	while (m.l.head !=0) {
		r = m.dequeue();
		cout << r << endl;
	}
	system("pause");
}
