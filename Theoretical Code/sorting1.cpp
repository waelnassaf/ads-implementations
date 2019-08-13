#include <iostream>
#include <queue> // later use for Radix Sort
#include <cmath> // later use for Radix Sort
using namespace std;


/*
|--------------------------------------------------------------------------
| Sorting Algorithm | Selection Sort.                                      |
|--------------------------------------------------------------------------
*/

void swap(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void selection_sort(int data[], int n)
{
    int min_index;
    for (int i = 0; i < n-1; i++)
    {
        min_index = i;
        for (int j = i + 1 ; j < n ; j++) {
            if (data[j] < data [min_index]) {
                min_index = j;
                swap(data[i], data[min_index]);
            }
        }
    }
}




/*
|--------------------------------------------------------------------------
| Sorting Algorithm | Insertion Sort.                                      |
|--------------------------------------------------------------------------
*/
void insertion_sort (int data[], int n) {
    for (int i = 1; i < n; i++)
    {
        int j = i ;
        int tmp = data[j];
        while (j > 0 && tmp < data[j-1])
        {
            data[j] = data [j-1];
            j--;
        }
        data [j]  = tmp;
    }
}


/*
|--------------------------------------------------------------------------
| Sorting Algorithm | Bubble Sort.                                         |
|--------------------------------------------------------------------------
*/

void bubble_sort (int a[], int n)
{
    for (int i = 0; i < n-1; i++)
        for (int j = n-1 ; j > i ; j--)
            if (a[j] < a[j-1])
                swap (a[j] , a[j-1]);
}



int main() {


    return 0;
}




