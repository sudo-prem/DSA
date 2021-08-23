#include <bits/stdc++.h>
using namespace std;

// == Analysis ================================
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// Adaptability: True
// Stability: True
// K-Passes: False
// Algorithm:
//  Assume that the first element is sorted
//  add elements from 2nd index to the sorted
//  array by finding its appropriate position

void InsertionSort(vector<int> &arr)
{
    int size = arr.size();
    for (int i = 1; i < size; ++i)
    {
        int j = i;
        while (j > 0 and arr[j] < arr[j - 1])
        {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}

int main()
{
    vector<int> arr{8, 2, 4, 1, 3, -6, 7, 8, 9};
    int size = arr.size();
    InsertionSort(arr);
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
    return 0;
}