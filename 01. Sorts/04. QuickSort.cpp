#include <bits/stdc++.h>

using namespace std;

void QuickSort(vector<int> &arr, int i, int j)
{
    if (j > i)
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
        QuickSort(arr, pivot, j);
        QuickSort(arr, j + 1, end);
    }
}

void QuickSort(vector<int> &arr)
{
    QuickSort(arr, 0, arr.size());
}

int main()
{
    vector<int> arr{5, 4, 3, 2};
    QuickSort(arr);
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
    return 0;
}