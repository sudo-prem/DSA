#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
int helper(vector<vector<int>> &matrix, int row, int col, vector<vector<int>> &dp)
{
	int m = matrix.size(), n = matrix[0].size();
	if (row == m - 1)
		return matrix[row][col];
	if (dp[row][col] != -1)
		return dp[row][col];

	int res{INT_MIN};
	vector<int> dCol{0, -1, 1};
	for (int i = 0; i < 3; ++i)
	{
		int x = row + 1;
		int y = col + dCol[i];
		if (x < m and y >= 0 and y < n)
			res = max(res, matrix[row][col] + helper(matrix, x, y, dp));
	}

	return dp[row][col] = res;
}

int getMaxPathSum1(vector<vector<int>> &matrix)
{
	int m = matrix.size(), n = matrix[0].size();
	vector<vector<int>> dp(m, vector<int> (n, -1));

	int res{INT_MIN};
	for (int i = 0; i < n; ++i)
		res = max(res, helper(matrix, 0, i, dp));

	return res;
}

// Approach 2:
int getMaxPathSum2(vector<vector<int>> &matrix)
{
	int m = matrix.size(), n = matrix[0].size();
	vector<vector<int>> dp(m, vector<int> (n, 0));
	dp[0] = matrix[0];

	for (int i = 1; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int up = dp[i - 1][j] + matrix[i][j];
			int leftDia{INT_MIN}, rightDia{INT_MIN};
			if (j - 1 >= 0)
				leftDia = dp[i - 1][j - 1] + matrix[i][j];
			if (j + 1 < n)
				rightDia = dp[i - 1][j + 1] + matrix[i][j];

			dp[i][j] = max({up, leftDia, rightDia});
		}
	}

	return *max_element(dp[m - 1].begin(), dp[m - 1].end());
}

// Approach 3:
int getMaxPathSum3(vector<vector<int>> &matrix)
{
	int m = matrix.size(), n = matrix[0].size();
	vector<vector<int>> dp(2, vector<int> (n, 0));
	dp[0] = matrix[0];

	for (int i = 1; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int up = dp[(i - 1) % 2][j] + matrix[i][j];
			int leftDia{INT_MIN}, rightDia{INT_MIN};
			if (j - 1 >= 0)
				leftDia = dp[(i - 1) % 2][j - 1] + matrix[i][j];
			if (j + 1 < n)
				rightDia = dp[(i - 1) % 2][j + 1] + matrix[i][j];

			dp[i % 2][j] = max({up, leftDia, rightDia});
		}
	}

	return *max_element(dp[(m - 1) % 2].begin(), dp[(m - 1) % 2].end());
}

void solve()
{
	vector<vector<int>> matrix{{1, 2, 10, 4}, {100, 3, 2, 1}, {1, 1, 20, 2}, {1, 2, 2, 1}};

	cout << getMaxPathSum1(matrix) << endl;
	cout << getMaxPathSum2(matrix) << endl;
	cout << getMaxPathSum3(matrix) << endl;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ONPC
	freopen("input.txt", "r", stdin);
#endif
	int t {1};
	/* int i {1}; cin >> t; */
	while (t--)
	{
		/* cout << "Case #" << i++ << ": "; */
		solve();
	}
	return 0;
}
