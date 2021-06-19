#include <bits/stdc++.h>

using namespace std;

// Time Complexity: O(n*log(n))
// Space Complexity: O(1) Not including implicit recusrion stack
// Adaptability: False
// Stable: False
// K-Passes: False

void Partition(vector<int> &arr, int i, int j)
{
    if (i < j)
    {
        int pivot{i}, end{j};
        // Move i from pivot, j from inifinity
        i++;
        j--;
        do
        {
            while (arr[i] <= arr[pivot])
                i++;
            while (arr[j] > arr[pivot])
                j--;
            if (i < j)
                swap(arr[i], arr[j]);
        } while (i < j);
        // Swap the pivot to its position
        swap(arr[pivot], arr[j]);
        // Here jth element is already in its sorted postion,
        // acts as the last dummy element for the left side Partition
        Partition(arr, pivot, j);
        // since 'end' still holds the last dummy element we can directly pass it
        Partition(arr, j + 1, end);
    }
}

void QuickSort(vector<int> &arr)
{
    Partition(arr, 0, arr.size() - 1);
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