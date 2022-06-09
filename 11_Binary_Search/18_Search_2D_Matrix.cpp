#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

bool searchMatrix1(vector<vector<int>>& matrix, int target)
{
	int n = matrix.size(), m = matrix[0].size();
	int i = 0, j = m - 1;

	while (i < n and j >= 0)
	{
		if (matrix[i][j] == target)
			return true;
		if (matrix[i][j] < target)
			i++;
		else
			j--;
	}

	return false;
}

bool searchMatrix2(vector<vector<int>> &matrix, int target)
{
	int m = matrix.size(), n = matrix[0].size();
	int low = 0, high = m * n - 1;

	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		int curr = matrix[mid / n][mid % n];

		if (curr == target)
			return true;
		if (curr < target)
			low = mid + 1;
		else
			high = mid - 1;
	}

	return false;
}

void solve()
{
	vector<vector<int>> matrix{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
	int target = 3;

	cout << searchMatrix1(matrix, target) << endl;
	cout << searchMatrix2(matrix, target) << endl;
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
