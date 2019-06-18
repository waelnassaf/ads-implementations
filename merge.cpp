// Merge Algorithm (Not Merge Sort)
// Merge Algorithm merges two sorted arrays.
// A contribution by Wael Assaf.
#include<iostream>
using namespace std;

void
mergeArrays (int arr1[], int arr2[], int s1, int s2, int arr3[])
{
  int i = 0, j = 0, k = 0;

  while (i < s1 && j < s2)
    {
      if (arr1[i] < arr2[j])
	arr3[k++] = arr1[i++];
      else
	arr3[k++] = arr2[j++];
    }

  while (i < s1)
    arr3[k++] = arr1[i++];

  while (j < s2)
    arr3[k++] = arr2[j++];
}

int main()
{
  int arr1[] = { 1, 12, 111, 200, 2500, 100000000 };
  int s1 = sizeof (arr1) / sizeof (arr1[0]);

  int arr2[] = { 10, 100, 1000, 4100, 200000 };
  int s2 = sizeof (arr2) / sizeof (arr2[0]);

  int arr3[s1 + s2];
  mergeArrays (arr1, arr2, s1, s2, arr3);

  cout << "Array after Merging" << endl;
  for (int i = 0; i < s1 + s2; i++)
    cout << arr3[i] << " ";
  return 0;
}

