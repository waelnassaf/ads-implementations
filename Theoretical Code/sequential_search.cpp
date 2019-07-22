#include <iostream>
using namespace std;

int seq_search(int a[], int item, int n){
    for (int i = 0; i < n; i++)
        if (a[i] == item){
            return i;
            break;
        }
    return -1;
}

int main()
{
    int arr[] = {10, 21, 29, 12, 8};

    cout << seq_search(arr, 29, 5) << endl;

    return 0;
}
