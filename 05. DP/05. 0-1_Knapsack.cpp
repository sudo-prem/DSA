#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> P, vector<int> W, int m, int n)
{
    // Table
    vector<vector<int>> T(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (W[i] <= j)
                T[i][j] = max(T[i - 1][j], P[i] + T[i - 1][j - W[i]]);
            else
                T[i][j] = T[i - 1][j];

    int i = n, j = m;
    while (i > 0 and j > 0)
    {
        if (T[i][j] == T[i - 1][j])
        {
            cout << i << ", " << P[i] << " = 0\n";
            i--;
        }
        else
        {
            cout << i << ", " << P[i] << " = 1\n";
            i--;
            j -= W[i];
        }
    }

    return T[n][m];
}

int main()
{
    // Maximum Capacity of Knapsack
    int m = 8;
    int n = 4;
    // Profit
    vector<int> P{0, 1, 2, 5, 6};
    // Weights
    vector<int> W{0, 2, 3, 4, 5};

    int res = knapsack(P, W, m, n);

    cout << res << endl;

    return 0;
}