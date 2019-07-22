#include <iostream>
using namespace std;

int seqSearch(int arr[], int s, int item) {
    for (int i = 0; i < s; i++)
        if (arr[i] == item)
            return i;
    return -1;
}

int main() {
    
    int array[] = {21, 44, 62, 14, 88};
    int size = sizeof(array)/sizeof(array[0]);
    cout << seqSearch(array, size, 88) << endl;
    
}
