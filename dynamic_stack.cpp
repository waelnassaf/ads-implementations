// A contribution by Wael Assaf.
#define STACK_MAX 100 // #define preprocessor allows us to define constants.
#include<iostream>
#include<string>
using namespace std;
template<class T>
class Stack {
private:
    T* data;
    int size;
public:
    Stack() { data = new T[STACK_MAX]; size = 0;} // constructor initializing stack
     
    bool is_empty() { return (size == 0); }
     
    bool is_full() { return (size == STACK_MAX); } 
     
    T top() {
    if (size != 0){
        cout << "The element located at the top is:" << endl; 
        return data[size - 1];
    } else
        return -1;
    }
 
    void push(T item) {
    if (size < STACK_MAX){
        data[size] = item;
        size++;
    } else
        cout << "sorry the stack is full" << endl;
    }
    void pop() {
    if (size == 0)
        cout << "sorry the stack is empty" << endl;
    else
        size--;
    }
};
 
int main() {
     
    Stack<int>* s = new Stack<int>();

    s->push(1001);
    s->push(32);
    s->push(54);
    s->push(10);

    cout << s->top() << endl;
     
    s->pop();
    cout << s->top() << endl;
     
     
    return 0;
}