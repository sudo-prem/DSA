// Problem Link:
// https://leetcode.com/problems/number-of-islands/

// Approach 1: (DFS)
// TC: O(n*m) (Amortised)
// SC: O(1)

// Approach 2: (BFS)
// TC: O(n*m) (Amortised)
// SC: O(1)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1
void islandHelper(vector<vector<char>> &grid, int row, int col)
{
	int n = grid.size();
	int m = grid[0].size();
	// Changing it in-place
	// Hence we do not need visited matrix
	grid[row][col] = '0';
	vector<pair<int, int>> coordinates{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

	for (auto i : coordinates)
	{
		int x = row + i.first;
		int y = col + i.second;

		if (x >= 0 and x < n and y >= 0 and y < m)
			if (grid[x][y] == '1')
				islandHelper(grid, x, y);
	}
}

int numIslands1(vector<vector<char>> &grid)
{
	int n = grid.size();
	int m = grid[0].size();
	int res{};

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (grid[i][j] == '1')
			{
				res++;
				islandHelper(grid, i, j);
			}

	return res;
}

// Approach 2
int numIslands2(vector<vector<char>> &grid)
{
	int n = grid.size();
	int m = grid[0].size();
	int res{};

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (grid[i][j] == '1')
			{
				res++;
				queue<pair<int, int>> nodeQu;
				nodeQu.push({i, j});
				grid[i][j] = '0';

				while (!nodeQu.empty())
				{
					vector<pair<int, int>> coordinates{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
					int row = nodeQu.front().first;
					int col = nodeQu.front().second;
					nodeQu.pop();

					for (auto i : coordinates)
					{
						int x = row + i.first;
						int y = col + i.second;
						if (x >= 0 and x < n and y >= 0 and y < m)
							if (grid[x][y] == '1')
							{
								nodeQu.push({x, y});
								grid[x][y] = '0';
							}
					}
				}
			}
		}
	}

	return res;
}

void solve()
{
	vector<vector<char>> grid1
	{
		{'1', '1', '0', '0', '0'},
		{'1', '1', '0', '0', '0'},
		{'0', '0', '1', '0', '0'},
		{'0', '0', '0', '1', '1'}
	};
	cout << numIslands1(grid1) << endl;

	vector<vector<char>> grid2
	{
		{'1', '1', '0', '0', '0'},
		{'1', '1', '0', '0', '0'},
		{'0', '0', '1', '0', '0'},
		{'0', '0', '0', '1', '1'}
	};
	cout << numIslands2(grid2) << endl;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t{1};
	// cin >> t;
	while (t--)
		solve();
	return 0;
}
