#include <iostream>
using namespace std;

int fact(int n) {
    return n == 0 ? 1 : n * fact(n-1);
}
void DecBin(int num, int base) {
    if (num > 0) {
        DecBin(num/base, base);
        cout << num % base;
    }
}
int fib(int a, int b,int n) {
    if(n == 1) return a;
    else if (n == 2) return b;
    return fib(a,b,n-1)+fib(a,b,n-2);
}
int fib(int n) { // My Version.
    if (n <= 2) return 1;
    return fib(n-1) + fib(n-2);
}
void hanoi(int DiskCount, int source, int dest, int spare){
    if (DiskCount == 1)
        cout << "Move disk " << DiskCount << " from Needle " << source << " to Needle " << dest << endl;
    else {
        hanoi(DiskCount - 1, source, spare, dest);
        cout << "Move disk "  << DiskCount << " from Needle " << source << " to Needle " << dest << endl;
        hanoi(DiskCount - 1, spare, dest, source);
    }
}
int AddUp(unsigned int number) {
    if (number == 0) return number;
    else return number + AddUp(number - 1);
}

/*
 * Write a recursive function that computes and returns
 * the sum of all elements in an array, where the array and
 * its size are passed as parameters.
 */
int arraySum(int arr[], int n){
    if (n == 0) return 0;
    return *arr + arraySum(arr + 1, n-1);
}

int arrSum(int arr[], int s) { // My Version
    if (s < 0) return 0;
    return arr[s-1] + arrSum(arr, s-1);
}

int largest(int list[], int lowerIndex, int upperIndex){
    if (lowerIndex == upperIndex) return list[lowerIndex];
    int max = largest(list, lowerIndex+1, upperIndex);
    if (list[lowerIndex] >= max) return list[lowerIndex];
    return max;
}


int main() {

    cout << fact(5) << endl;

    return 0;
}
