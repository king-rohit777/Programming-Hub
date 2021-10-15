/*
Sort 2 sorted arrays with o(1) extra space

Input: ar1[] = {10};
       ar2[] = {2, 3};
Output: ar1[] = {2}
        ar2[] = {3, 10}

Input: ar1[] = {1, 5, 9, 10, 15, 20};
       ar2[] = {2, 3, 8, 13};
Output: ar1[] = {1, 2, 3, 5, 8, 9}
        ar2[] = {10, 13, 15, 20}



Approach 1
-----------

Use a 3rd array
TC ->(nlogn)+o(n)+o(n)  // sorting + putting the elements in 3rd + putting in back in original array
SC -> O(n)


Appraoch 2
-----------

Kind of insertion sort where we iterate through both the arrays and check if anyone is greater then swap it


Approach 3
-----------

We can also do the first approach in O(N) time &  O(N) space complexity. Find the minimum element among the current two elements of both the arrays and update the output_array with the least value and increment its index to next position.

We can also do the first approach in O(N) time &  O(N) space complexity. Find the minimum element among the current two elements of both the arrays and update the output_array with the least value and increment its index to next position.
*/

// CPP program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to merge two arrays
void merge(int arr1[], int arr2[], int n, int m)
{
    int i = 0, j = 0, k = n - 1;

    // Untill i less than equal to k
    // or j is less tha m
    while (i <= k && j < m)
    {
        if (arr1[i] < arr2[j])
            i++;
        else
        {
            swap(arr2[j++], arr1[k--]);
        }
    }

    // Sort first array
    sort(arr1, arr1 + n);

    // Sort second array
    sort(arr2, arr2 + m);
}

// Driver Code
int main()
{

    int ar1[] = {1, 5, 9, 10, 15, 20};
    int ar2[] = {2, 3, 8, 13};
    int m = sizeof(ar1) / sizeof(ar1[0]);
    int n = sizeof(ar2) / sizeof(ar2[0]);
    merge(ar1, ar2, m, n);

    cout << "After Merging \nFirst Array: ";
    for (int i = 0; i < m; i++)
        cout << ar1[i] << " ";
    cout << "\nSecond Array: ";
    for (int i = 0; i < n; i++)
        cout << ar2[i] << " ";
    return 0;
}
