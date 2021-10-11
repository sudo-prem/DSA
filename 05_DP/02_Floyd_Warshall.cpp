// Problem Link:
// https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

// TC: O(n^3)
// SC: O(1)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

void floydWarshall(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][k] == -1 or matrix[k][j] == -1)
                    continue;
                else if (matrix[i][j] == -1)
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                else
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }
}

void display(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void solve()
{
    vector<vector<int>> matrix{{0, 1, 43}, {1, 0, 6}, {-1, -1, 0}};

    display(matrix);
    floydWarshall(matrix);
    display(matrix);
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t{1}, i{1};
    // cin >> t;
    while (t--)
    {
        // cout << "Case #" << i++ << ": ";
        solve();
    }
    return 0;
}