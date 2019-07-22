#include <iostream>
using namespace std;
#define capacity 100

class Stack {
private:
    char s[capacity];
    int size;
public:
    Stack() {   size = 0;   }

    void Push(char c) { if (size < capacity) s[size++] = c; }

    char Pop() { if (size > 0) { size--; return s[size]; } return -1; }

    bool Is_Empty(){ return (size == 0); }

    bool Is_Full(){ return (size == capacity); }
};

int main() {

    Stack s;
    char str[40] = {"My name is Wael Assaf"};
    int i = 0;
    cout << str << endl;

    while (str[i] != '\0' && !s.Is_Full())
        s.Push(str[i++]);

    while (!s.Is_Empty())
        cout << s.Pop();
    cout << endl;
    return 0;
}

