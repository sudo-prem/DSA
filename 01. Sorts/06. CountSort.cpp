#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
// Adaptability: True
// Stable: True
// K-Passes: False

int FindMax(vector<int> &arr)
{
    int max = INT_MIN;
    for (int i = 0; i < arr.size(); ++i)
        if (arr[i] > max)
            max = arr[i];
    return max == INT_MIN ? 0 : max;
}

void CountSort(vector<int> &arr)
{
    int max = FindMax(arr);
    vector<int> counter(max + 1, 0);
    for (int i = 0; i < arr.size(); ++i)
        counter[arr[i]]++;
    int k{};
    for (int i = 0; i < counter.size(); ++i)
        if (counter[i] != 0)
            while (counter[i]--)
                arr[k++] = i;
}

int main()
{
    vector<int> arr{2, 3, 7, 4, 9, 2, 6, 5, 1};
    CountSort(arr);
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
    return 0;
}