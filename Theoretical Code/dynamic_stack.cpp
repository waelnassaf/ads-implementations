#define STACK_MAX 100
#include<iostream>
#include<string>
using namespace std;

template<class T>
class Stack {
private:
    T* data;
    int size;
public:
    Stack() {   data = new T[STACK_MAX]; size = 0;  }

    bool is_empty() { return size == 0; }

    bool is_full() { return size == STACK_MAX; }

    T top() {
        if (size != 0) return data[size - 1];
        else return -1;
    }

    void push(T item) {
        if (size < STACK_MAX){
            data[size] = item;
            size++;
        } else
            cout << "Sorry, the stack is full." << endl;
    }

    void pop() {
        if (size == 0)
            cout << "Sorry, the stack is empty." << endl;
        else
            size--;
    }
};

int main() {

    Stack<int> s;

    cout << s.is_empty() << endl;
    cout << s.is_full() << endl;

    s.push(8);
    s.push(80);
    s.push(81);
    s.push(89);

    cout << s.top() << endl;

    s.pop();
    cout << s.top();

    return 0;
}