#include <iostream>
using namespace std;

int binary_search(int a[], int size, int x) {
    int low  = 0;
    int high = size - 1;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] < x)
            low = mid + 1;
        else if (a[mid] > x)
            high  = mid - 1;
        else
            return mid;
    }
    return -1;
}


int main()
{

    int arr[] = {12, 32, 39, 88, 120, 1211};
    int s = sizeof(arr)/sizeof(arr[0]);
    cout << binary_search(arr, s, 39) << endl;

    return 0;
}
