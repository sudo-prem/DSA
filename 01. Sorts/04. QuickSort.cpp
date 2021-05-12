#include <bits/stdc++.h>

using namespace std;

// Time Complexity: O(n*log(n))
// Space Complexity: O(1) Not including implicit recusrion stack
// Adaptability: False
// Stable: False
// K-Passes: False

void QuickSort(vector<int> &arr, int i, int j)
{
    if (i < j)
    {
        int pivot{i}, end{j};
        do
        {
            do
            {
                i++;
            } while (arr[i] <= arr[pivot]);
            do
            {
                j--;
            } while (arr[j] > arr[pivot]);
            if (i < j)
                swap(arr[i], arr[j]);
        } while (i < j);
        swap(arr[pivot], arr[j]);
        // Here the jth element which is already in its sorted postion,
        // acts as the last dummy element for the left side QuickSort
        QuickSort(arr, pivot, j);
        // since end still holds the last dummy element we can directly pass it
        QuickSort(arr, j + 1, end);
    }
}

void QuickSort(vector<int> &arr)
{
    QuickSort(arr, 0, arr.size() - 1);
}

int main()
{
    // Last element is taken as dummy element
    vector<int> arr{8, 2, 4, 1, 3, -6, 9, 7, 8, INT_MAX};
    QuickSort(arr);
    // Printing all the elements except the last dummy element
    for (int i = 0; i < arr.size() - 1; ++i)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}