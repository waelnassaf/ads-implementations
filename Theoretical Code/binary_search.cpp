#include <iostream>
using namespace std;

bool IterativeBinarySearch(int arr[], int size, int item) {
    int min = 0;
    int max = size - 1;
    int mid;
    while (min <= max) {
        mid = (min + max) / 2;
        if (arr[mid] > item)
            max = mid - 1;
        else if (arr[mid] < item)
            min = mid + 1;
        else
            return true;
    }
    return false;
}
bool RecursiveBinarySearch(int arr[], int item, int min, int max) {
    if (min > max) return false;
    int mid = (min + max) / 2;
    if (arr[mid] > item) return RecursiveBinarySearch(arr, item, min, mid - 1);
    else if (arr[mid] < item) return RecursiveBinarySearch(arr, item, mid + 1, max);
    else return true;
}

int main()
{

    int arr[] = {21, 65, 99, 140, 190};
    
    cout << IterativeBinarySearch(arr, 5, 66) << endl;
    cout << RecursiveBinarySearch(arr, 140, 0, 5) << endl;

    return 0;
}
