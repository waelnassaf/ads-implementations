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

bool balancedBraces(string exp){
    Stack<char> S;
    for(int i = 0; i < exp.length(); i++){
        if (exp[i] != '{' && exp[i] != '}') continue;
        else if(exp[i] ==  '{') S.push(exp[i]);
        else if(exp[i] == '}' && S.is_empty()) return false;
        else S.pop();
    }
    return S.is_empty();
}

int main() {

    if (balancedBraces("asd{{qwdq}qwdqf}"))
        cout << "Braces are Balanced\n";
    else
        cout << "Braces are not Balanced\n";
    
    return 0;
}

