#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

bool isPossible(vector<string> &curr, int row, int col)
{
	int n = curr.size(), i{}, j{};

	for (int i = 0; i < row; ++i)
		if (curr[i][col] == 'Q')
			return false;

	i = row - 1, j = col - 1;
	while (i >= 0 and j >= 0)
		if (curr[i--][j--] == 'Q')
			return false;

	i = row - 1, j = col + 1;
	while (i >= 0 and j < n)
		if (curr[i--][j++] == 'Q')
			return false;

	return true;
}

void helper(int row, int n, vector<string> &curr, vector<vector<string>> &res)
{
	if (row == n)
	{
		res.push_back(curr);
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		if (isPossible(curr, row, i))
		{
			curr[row][i] = 'Q';
			helper(row + 1, n, curr, res);
			curr[row][i] = '.';
		}
	}
}

vector<vector<string>> solveNQueens(int n)
{
	vector<string> curr(n, string (n, '.'));
	vector<vector<string>> res{};

	helper(0, n, curr, res);
	return res;
}

void solve()
{
	auto res = solveNQueens(4);

	for (auto itr : res)
	{
		for (auto c : itr)
			cout << c << " ";
		cout << endl;
	}
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
