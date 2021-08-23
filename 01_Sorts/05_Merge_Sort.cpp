#include <bits/stdc++.h>
using namespace std;

// == Analysis ===================================
// Time Complexity: O(n*log(n))
// Space Complexity: O(n)
// Adaptability: False
// Stability: True
// K-Passes: False
// Algorithm:
//  Perform merge on 2 elements at a time
//  perform merge on 4 elements at a time
//  and so on till the entire list is sorted

// Merges the array arr from l to mid with arr from mid+1 to h-1
// Consumes O(n) extra space
void Merge(vector<int> &arr, int l, int mid, int h)
{
    int i{l}, j{mid + 1}, k{0};
    vector<int> res(h + 1);
    while (i <= mid and j <= h)
    {
        if (arr[i] < arr[j])
            res[k++] = arr[i++];
        else
            res[k++] = arr[j++];
    }
    while (i <= mid)
        res[k++] = arr[i++];
    while (j <= h)
        res[k++] = arr[j++];
    k = 0;
    while (l <= h)
        arr[l++] = res[k++];
}

// Iterative Algorithm
void MergeSort(vector<int> &arr)
{
    int start = 0, end = arr.size();
    int i{}, j{};
    int l{}, mid{}, h{};
    // Outer For loop is to denote how many elements to take at a time
    for (i = 2; i <= end; i *= 2)
    {
        // Inner for loop is to find the start and end of each iteration
        for (j = 0; j + i - 1 < end; j += i)
        {
            l = j;
            h = j + i - 1;
            mid = l / 2 + h / 2;
            Merge(arr, l, mid, h);
        }
    }
    // if total number of elements in list is odd,
    // we have to merge the last element separately
    if (i / 2 < end)
        Merge(arr, 0, i / 2 - 1, end - 1);
}

// // Recursive Algorithm
// void MergeSort(vector<int> &arr, int l, int h)
// {
//     if (l < h)
//     {
//         int mid = (l + h) / 2;
//         MergeSort(arr, l, mid);
//         MergeSort(arr, mid + 1, h);
//         Merge(arr, l, mid, h);
//     }
// }

// void MergeSort(vector<int> &arr)
// {
//     MergeSort(arr, 0, arr.size() - 1);
// }

int main()
{
    vector<int> arr{2, 3, 7, 4, 9, 2, 6, 5, 1};
    MergeSort(arr);
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
    return 0;
}