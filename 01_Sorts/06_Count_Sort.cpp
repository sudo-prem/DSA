#include <bits/stdc++.h>
using namespace std;

// == Analysis =======================================
// Time Complexity: O(n)
// Space Complexity: O(max_element(n))
// Adaptability: True
// Stability: True
// K-Passes: False
// Algorithm:
//  Create a vector of size(max(given array)) and
//  initialize it to 0, traverse through the array and
//  increment the corresponding value in the vector

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
    // Hashing the values to counter
    for (int i = 0; i < arr.size(); ++i)
        counter[arr[i]]++;
    // Adding back the values to the arr
    int k{};
    for (int i = 0; i < counter.size(); ++i)
        if (counter[i] != 0)
            // Adds counter[i] number of times i to arr
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