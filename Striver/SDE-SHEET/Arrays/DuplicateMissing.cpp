/*
Find the repeating and the missing
https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/


Method 1 (Use Sorting)
Approach:

Sort the input array.
Traverse the array and check for missing and repeating.

Time Complexity: O(nLogn)

Method 2 (Use count array)
Approach:

Create a temp array temp[] of size n with all initial values as 0.
Traverse the input array arr[], and do following for each arr[i]
if(temp[arr[i]] == 0) temp[arr[i]] = 1;
if(temp[arr[i]] == 1) output “arr[i]” //repeating
Traverse temp[] and output the array element having value as 0 (This is the missing element)
Time Complexity: O(n)

Auxiliary Space: O(n)

Method 3 (Use elements as Index and mark the visited places)
Approach:
Traverse the array. While traversing, use the absolute value of every element as an index and make the value at this index as negative to mark it visited. If something is already marked negative then this is the repeating element. To find missing, traverse the array again and look for a positive value.
*/

// C++ program to Find the repeating
// and missing elements

#include <bits/stdc++.h>
using namespace std;

void printTwoElements(int arr[], int size)
{
    int i;
    cout << " The repeating element is ";

    for (i = 0; i < size; i++)
    {
        if (arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        else
            cout << abs(arr[i]) << "\n";
    }

    cout << "and the missing element is ";
    for (i = 0; i < size; i++)
    {
        if (arr[i] > 0)
            cout << (i + 1);
    }
}

/* Driver code */
int main()
{
    int arr[] = {7, 3, 4, 5, 5, 6, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    printTwoElements(arr, n);
}
