#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
int helper(vector<vector<int>> &grid, int row, int col, vector<vector<int>> &dp)
{
	int m = grid.size(), n = grid[0].size();
	if (row == m - 1 and col == n - 1)
		return grid[row][col];
	if (dp[row][col] != -1)
		return dp[row][col];

	int res = INT_MAX;
	vector<int> dRow{0, 1}, dCol{1, 0};
	for (int i = 0; i < 2; ++i)
	{
		int x = row + dRow[i];
		int y = col + dCol[i];

		if (x < m and y < n and x >= 0 and y >= 0)
			res = min(res, grid[row][col] + helper(grid, x, y, dp));
	}

	return dp[row][col] = res;
}

int minSumPath1(vector<vector<int>> &grid)
{
	int m = grid.size(), n = grid[0].size();
	vector<vector<int>> dp(m, vector<int> (n, -1));

	return helper(grid, 0, 0, dp);
}

// Approach 2:
int minSumPath2(vector<vector<int>> &grid)
{
	int m = grid.size(), n = grid[0].size();
	vector<vector<int>> dp(m, vector<int> (n, 0));

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i == 0 and j == 0)
				dp[i][j] = grid[i][j];
			else if (i == 0)
				dp[i][j] = grid[i][j] + dp[i][j - 1];
			else if (j == 0)
				dp[i][j] = grid[i][j] + dp[i - 1][j];
			else
				dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	return dp[m - 1][n - 1];
}

// Approach 3:
int minSumPath3(vector<vector<int>> &grid)
{
	int m = grid.size(), n = grid[0].size();
	vector<vector<int>> dp(2, vector<int> (n, 0));

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i == 0 and j == 0)
				dp[i % 2][j] = grid[i][j];
			else if (i == 0)
				dp[i % 2][j] = grid[i][j] + dp[i % 2][j - 1];
			else if (j == 0)
				dp[i % 2][j] = grid[i][j] + dp[(i - 1) % 2][j];
			else
				dp[i % 2][j] = grid[i][j] + min(dp[(i - 1) % 2][j], dp[i % 2][j - 1]);
		}
	}

	return dp[(m - 1) % 2][n - 1];
}

void solve()
{
	vector<vector<int>> grid(2, vector<int> (3));
	grid[0] = {5, 9, 6};
	grid[1] = {11, 5, 2};

	cout << minSumPath1(grid) << endl;
	cout << minSumPath2(grid) << endl;
	cout << minSumPath3(grid) << endl;
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
