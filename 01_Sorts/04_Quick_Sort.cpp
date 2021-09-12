#include <bits/stdc++.h>
using namespace std;

// == Analysis ================================
// Time Complexity: O(n*log(n))
// Space Complexity: O(log(n)) Recusrion Stack
// Adaptability: False
// Stability: False
// K-Passes: False
// Algorithm:
//  Take a number(pivot) find its
//  corresponding position in the list

int partition(vector<int> &arr, int low, int high)
{
    int pivot = low;
    int i = low + 1, j = high;

    while (i <= j)
    {
        while (i <= j and arr[i] <= arr[pivot])
            i++;
        while (i <= j and arr[j] >= arr[pivot])
            j--;
        if (i <= j)
            swap(arr[i], arr[j]);
    }
    swap(arr[pivot], arr[j]);

    return j;
}

void quickSortHelper(vector<int> &arr, int low, int high)
{
    if (low <= high)
    {
        int pivot = partition(arr, low, high);
        quickSortHelper(arr, low, pivot - 1);
        quickSortHelper(arr, pivot + 1, high);
    }
}

void quickSort(vector<int> &arr)
{
    int low = 0;
    int high = arr.size() - 1;
    quickSortHelper(arr, low, high);
}

int main()
{
    vector<int> arr{5, 2, 3, 1};
    // vector<int> arr{5, 1, 1, 2, 0, 0};
    // vector<int> arr{8, 2, 4, 1, 3, -6, 9, 7, 8};
    quickSort(arr);

    // Printing all the elements except the last dummy element
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}