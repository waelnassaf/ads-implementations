// Fibonacci Algorithm | Recursive Implementation
// This Algorithm Assumes Fibonacci Sequence starts at 1 : 1, 1, 2, 3, 5, 8, 13...
// Some sources may assume it starts at 0 : 0, 1, 1, 2, 3, 5, 8, 13...
// However, Keep in mind that Fibonacci himself started the sequence with 1 and not 0
// Source: https://bit.ly/1QrQ3SH
// A contribution by Wael Assaf.

#include <iostream>
using namespace std;

int fib(int n) {
    if (n <= 2)
        return 1;
    return fib(n-1) + fib(n-2);
}

int main () {
    cout << fib(7) << endl;
}
