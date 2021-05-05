#include <bits/stdc++.h>

using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(1)
// Adaptability: True
// Stable: True
// K-Passes: True

void BubbleSort(vector<int> &arr)
{
    int size = arr.size();
    bool flag{};
    for (int i = 0; i < size - 1; ++i)
    {
        flag = false;
        for (int j = 0; j < size - 1 - i; ++j)
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = true;
            }
        if (flag == false)
            return;
    }
}

int main()
{
    vector<int> arr{8, 2, 4, 1, 3, -6, 7, 8, 9};
    BubbleSort(arr);
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
    return 0;
}