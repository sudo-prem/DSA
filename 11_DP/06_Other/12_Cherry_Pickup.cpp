#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"
#define vvvi vector<vector<vector<int>>>

// Approach 1:
int helper(vector<vector<int>> &grid, int row, int col1, int col2, vvvi &dp)
{
	int m = grid.size(), n = grid[0].size();
	int curr = (col1 == col2) ? grid[row][col1] : grid[row][col1] + grid[row][col2];

	if (row == m - 1)
		return curr;
	if (dp[row][col1][col2] != -1)
		return dp[row][col1][col2];

	int res{};
	vector<int> dCols{-1, 0, 1};
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			int y1 = col1 + dCols[i], y2 = col2 + dCols[j];
			if (y1 >= 0 and y1 < n and y2 >= 0 and y2 < n)
				res = max(res, curr + helper(grid, row + 1, y1, y2, dp));
		}
	}

	return dp[row][col1][col2] = res;
}

int cherryPickup1(vector<vector<int>>& grid)
{
	int m = grid.size(), n = grid[0].size();
	vvvi dp(m, vector<vector<int>> (n, vector<int> (n, -1)));

	return helper(grid, 0, 0, n - 1, dp);
}

// Approach 2:
int cherryPickup2(vector<vector<int>>& grid)
{
	int m = grid.size(), n = grid[0].size();
	vvvi dp(m, vector<vector<int>> (n, vector<int> (n, 0)));

	for (int i = m - 1; i >= 0; --i)
	{
		for (int j = n - 1; j >= 0; --j)
		{
			for (int k = n - 1; k >= 0; --k)
			{
				int curr = j == k ? grid[i][j] : grid[i][j] + grid[i][k];
				if (i == m - 1)
				{
					dp[i][j][k] = curr;
					continue;
				}

				vector<int> dCols{-1, 0, 1};
				for (int r = 0; r < 3; ++r)
				{
					for (int s = 0; s < 3; ++s)
					{
						int y1 = j + dCols[r], y2 = k + dCols[s];
						if (y1 >= 0 and y1 < n and y2 >= 0 and y2 < n)
							dp[i][j][k] = max(dp[i][j][k], curr + dp[i + 1][y1][y2]);
					}
				}
			}
		}
	}

	return dp[0][0][n - 1];
}

// Approach 3:
int cherryPickup3(vector<vector<int>>& grid)
{
	int m = grid.size(), n = grid[0].size();
	vvvi dp(2, vector<vector<int>> (n, vector<int> (n, 0)));

	for (int i = m - 1; i >= 0; --i)
	{
		for (int j = n - 1; j >= 0; --j)
		{
			for (int k = n - 1; k >= 0; --k)
			{
				int curr = j == k ? grid[i][j] : grid[i][j] + grid[i][k];
				if (i == m - 1)
				{
					dp[i % 2][j][k] = curr;
					continue;
				}

				vector<int> dCols{-1, 0, 1};
				for (int r = 0; r < 3; ++r)
				{
					for (int s = 0; s < 3; ++s)
					{
						int y1 = j + dCols[r], y2 = k + dCols[s];
						if (y1 >= 0 and y1 < n and y2 >= 0 and y2 < n)
							dp[i % 2][j][k] = max(dp[i % 2][j][k], curr + dp[(i + 1) % 2][y1][y2]);
					}
				}
			}
		}
	}

	return dp[0][0][n - 1];
}

void solve()
{
	/* vector<vector<int>> grid{{3, 1, 1}, {2, 5, 1}, {1, 5, 5}, {2, 1, 1}}; */
	vector<vector<int>> grid{{4, 1, 5, 7, 1}, {6, 0, 4, 6, 4}, {0, 9, 6, 3, 5}};

	cout << cherryPickup1(grid) << endl;
	cout << cherryPickup2(grid) << endl;
	cout << cherryPickup3(grid) << endl;
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
