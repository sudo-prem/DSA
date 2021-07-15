#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
// Adaptability: True
// Stable: True
// K-Passes: False

class Node
{
public:
    int data;
    Node *next;
    Node(int d) : data(d), next(NULL) {}
};

int FindMax(vector<int> &arr)
{
    int max = INT_MIN;
    for (int i = 0; i < arr.size(); ++i)
        if (arr[i] > max)
            max = arr[i];
    return max == INT_MIN ? 0 : max;
}

int DigitCount(int max)
{
    int count{};
    while (max)
    {
        max /= 10;
        count += 1;
    }
    return count;
}

int pos(int n, int i)
{
    i = pow(10, i);
    return (n / i) % 10;
}

void RadixSort(vector<int> &arr)
{
    // Since we are dealing with decimal numbers
    // we only need 10 slots in a vector
    vector<Node *> radix(10, NULL);
    int max = FindMax(arr), count{};
    // here the count is called as base
    int count = DigitCount(max);
    for (int i = 0; i < count; ++i)
    {
        // adding the values to the hash
        for (int j = 0; j < arr.size(); ++j)
        {
            int curr = pos(arr[j], i);
            if (radix[curr] == NULL)
                radix[curr] = new Node(arr[j]);
            else
            {
                Node *temp = radix[curr];
                while (temp->next)
                    temp = temp->next;
                temp->next = new Node(arr[j]);
            }
        }
        int k{};
        // Updating the list's values
        for (int j = 0; j < 10; ++j)
        {
            Node *temp = radix[j];
            while (temp)
            {
                arr[k++] = temp->data;
                temp = temp->next;
            }
        }
        // replacing the hash values to NULL
        for (int i = 0; i < 10; ++i)
            radix[i] = NULL;
    }
}

int main()
{
    vector<int> arr{2, 331, 97, 4, 9, 22, 6, 5, 10};
    RadixSort(arr);
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
    return 0;
}