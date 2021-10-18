/*
MergeSort(arr[], l,  r)
If r > l
     1. Find the middle point to divide the array into two halves:
             middle m = l+ (r-l)/2
     2. Call mergeSort for first half:
             Call mergeSort(arr, l, m)
     3. Call mergeSort for second half:
             Call mergeSort(arr, m+1, r)
     4. Merge the two halves sorted in step 2 and 3:
             Call merge(arr, l, m, r)

*/

#include <iostream>
using namespace std;
void merge(int *, int, int, int);
void merge_sort(int *arr, int low, int high)
{
    int mid;
    if (low < high)
    {
        // divide the array at mid and sort independently using merge sort
        mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        // merge or conquer sorted arrays
        merge(arr, low, high, mid);
    }
}
// Merge sort
void merge(int *arr, int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            c[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        arr[i] = c[i];
    }
}
// read input array and call mergesort
int main()
{
    int myarray[30], num;
    cout << "Enter number of elements to be sorted:";
    cin >> num;
    cout << "Enter " << num << " elements to be sorted:";
    for (int i = 0; i < num; i++)
    {
        cin >> myarray[i];
    }
    merge_sort(myarray, 0, num - 1);
    cout << "Sorted array\n";
    for (int i = 0; i < num; i++)
    {
        cout << myarray[i] << "\t";
    }
}