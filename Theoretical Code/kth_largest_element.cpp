#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cout << "Enter the size of the array: n" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array" << endl;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr+n, greater<int>()); // To sort the array descending.
    
    cout << "Enter your Kth largest element?" << endl;
    cin >> k;
    
    cout << "The " << k << " largest element is: " << endl;
    cout << arr[k-1] << endl;
    
    
    
    return 0;
}

