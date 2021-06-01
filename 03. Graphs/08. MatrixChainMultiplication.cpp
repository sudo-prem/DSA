#include <bits/stdc++.h>
using namespace std;

int MatrixChainMultiplication(vector<int> dim)
{
    int n = dim.size();
    vector<vector<int>> M(n, vector<int>(n, 0));
    vector<vector<int>> S(n, vector<int>(n, 0));

    for (int d = 1; d < n - 1; ++d)
    {
        for (int i = 1; i < n - d; ++i)
        {
            int j = i + d, min = INT_MAX;
            for (int k = i; k < j; ++k)
            {
                int curr = M[i][k] + M[k + 1][j] + (dim[i - 1] * dim[k] * dim[j]);
                if (curr < min)
                {
                    min = curr;
                    M[i][j] = curr;
                }
            }
            M[i][j] = min;
        }
    }

    return M[1][n - 1];
}

int main()
{
    vector<int> dimensions{5, 4, 6, 2, 7};
    int res = MatrixChainMultiplication(dimensions);
    cout << "Minimum no. of Multiplications: " << res << endl;

    return 0;
}