#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n^2)
// Space Complxexity: O(1)
// Adaptability: True
// Stable: False
// K-Passes: True

void SelectionSort(vector<int> &arr)
{
    int size = arr.size();
    for (int i = 0; i < size - 1; ++i)
    {
        int j = i + 1, index{i};
        while (j < size)
        {
            if (arr[j] < arr[index])
                index = j;
            j++;
        }
        swap(arr[index], arr[i]);
    }
}

int main()
{
    vector<int> arr{8, 2, 4, 1, 3, -6, 7, 8, 9};
    int size = arr.size();
    SelectionSort(arr);
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
    return 0;
}