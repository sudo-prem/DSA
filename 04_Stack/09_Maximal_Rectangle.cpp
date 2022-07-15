#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

int maxAreaHist(vector<int> &nums)
{
	int n = nums.size();
	vector<int> leftMin(n), rightMin(n);
	stack<int> numSt{};

	for (int i = 0; i < n; ++i)
	{
		while (!numSt.empty() and nums[numSt.top()] >= nums[i])
			numSt.pop();

		if (numSt.empty())
			leftMin[i] = 0;
		else
			leftMin[i] = numSt.top() + 1;
		numSt.push(i);
	}

	while (!numSt.empty())
		numSt.pop();

	for (int i = n - 1; i >= 0; --i)
	{
		while (!numSt.empty() and nums[numSt.top()] >= nums[i])
			numSt.pop();

		if (numSt.empty())
			rightMin[i] = n - 1;
		else
			rightMin[i] = numSt.top() - 1;
		numSt.push(i);
	}

	int res{};
	for (int i = 0; i < n; ++i)
		res = max(res, nums[i] * (rightMin[i] - leftMin[i] + 1));

	return res;
}

int maximalRectangle(vector<vector<char>>& charMatrix)
{
	int m = charMatrix.size(), n = charMatrix[0].size();
	vector<vector<int>> matrix(m, vector<int> (n));

	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			matrix[i][j] = charMatrix[i][j] - '0';

	for (int i = 0; i < n; ++i)
		for (int j = 1; j < m; ++j)
			if (matrix[j][i] != 0)
				matrix[j][i] += matrix[j - 1][i];

	int res{};
	for (auto itr : matrix)
		res = max(res, maxAreaHist(itr));

	return res;
}

void solve()
{
	vector<vector<char>> charMatrix{{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};

	cout << maximalRectangle(charMatrix) << endl;
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
