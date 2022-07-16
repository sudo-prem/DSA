#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

void helper(vector<vector<int>> &m, int i, int j, string &curr, vector<string> &res)
{
	int n = m.size();

	if (i == n - 1 and j == n - 1)
	{
		res.push_back(curr);
		return;
	}
	if (i >= n or j >= n)
		return;

	vector<int> rows{1, 0, 0, -1};
	vector<int> cols{0, -1, 1, 0};
	vector<char> dir{'D', 'L', 'R', 'U'};

	for (int k = 0; k < 4; ++k)
	{
		int x = rows[k] + i;
		int y = cols[k] + j;

		if (x >= 0 and x < n and y >= 0  and y < n and m[x][y] == 1)
		{
			curr.push_back(dir[k]);
			m[i][j] = 0;
			helper(m, x, y, curr, res);
			m[i][j] = 1;
			curr.pop_back();
		}
	}
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
	if (m[0][0] == 0 or m[n - 1][n - 1] == 0)
		return {};

	string curr{};
	vector<string> res{};
	helper(m, 0, 0, curr, res);

	return res;
}

void solve()
{
	int n = 4;
	vector<vector<int>> m
	{
		{1, 0, 0, 0},
		{1, 1, 0, 1},
		{1, 1, 0, 0},
		{0, 1, 1, 1}
	};


	auto res = findPath(m, n);
	for (auto s : res)
		cout << s << endl;
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
