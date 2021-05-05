#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
// Adaptability: True
// Stable: True
// K-Passes: False

// Similar to CountSort but this has linked representation

class Node
{
public:
    int data;
    Node *next;
    Node(int d) : data(d), next(NULL) {}
};

int FindMax(vector<int> &arr)
{
    int max{INT_MIN};
    for (int i = 0; i < arr.size(); ++i)
        if (arr[i] > max)
            max = arr[i];
    return max == INT_MIN ? 0 : max;
}

// Also known as Bucket sort
void BinSort(vector<int> &arr)
{
    int max = FindMax(arr);
    vector<Node *> bin(max + 1, NULL);
    for (int i = 0; i < arr.size(); ++i)
    {
        if (bin[arr[i]] == NULL)
            bin[arr[i]] = new Node(arr[i]);
        else
        {
            Node *temp = bin[arr[i]];
            while (temp->next)
                temp = temp->next;
            temp->next = new Node(arr[i]);
        }
    }
    int k{};
    for (int i = 0; i <= max; ++i)
    {
        Node *temp = bin[i];
        while (temp)
        {
            arr[k++] = temp->data;
            temp = temp->next;
        }
    }
}

int main()
{
    vector<int> arr{2, 3, 97, 4, 2, 9, 22, 6, 5, 9, 10};
    BinSort(arr);
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
    return 0;
}