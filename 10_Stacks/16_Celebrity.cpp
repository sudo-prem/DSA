#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

int celebrity(vector<vector<int>> &matrix, int n)
{
	stack<int> numSt;

	for (int i = 0; i < n; ++i)
		numSt.push(i);

	while (numSt.size() > 1)
	{
		int c1 = numSt.top();
		numSt.pop();
		int c2 = numSt.top();
		numSt.pop();

		if (matrix[c1][c2])
			numSt.push(c2);
		else
			numSt.push(c1);
	}

	int candidate = numSt.top();
	numSt.pop();

	for (int i = 0; i < n; ++i)
		if (i != candidate and (matrix[candidate][i] or !matrix[i][candidate]))
			return -1;

	return candidate;
}

void solve()
{
	vector<vector<int>> matrix{{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};

	cout << celebrity(matrix, matrix.size()) << endl;
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
