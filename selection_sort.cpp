// Implementation of Selection Sort Algorithm. 
#include <iostream> 
using namespace std; 

void swap(int *x, int *y) 
{
	int temp = *x;
	*x = *y;
	*y = temp;
} 

void selectionSort(int arr[], int n) 
{ 
	int min_idx; 

	// One by one move boundary of unsorted subarray 
	for (int i = 0; i < n-1; i++) 
	{ 
		// Find the minimum element in unsorted array 
		min_idx = i; 
		for (int j = i+1; j < n; j++) 
		if (arr[j] < arr[min_idx]) 
			min_idx = j; 

		// Swap the found minimum element with the first element 
		swap(&arr[min_idx], &arr[i]); 
	} 
} 

/* Function to print an array */
void printArray(int arr[], int size) 
{
	for (int i=0; i < size; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
} 

// Driver program to test above functions 
int main() 
{ 
	int arr[] = {64, 25, 12, 22, 11, 1000}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	selectionSort(arr, n); 
	cout << "Sorted array: \n"; 
	printArray(arr, n); 
	return 0; 
} 







