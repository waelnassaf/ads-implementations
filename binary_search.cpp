#include <iostream>
using namespace std;

int binary_search(int a[], int x, int size) {
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
    
    cout << binary_search(arr, 120, 6) << endl;
    
    return 0;
}

