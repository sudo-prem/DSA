#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

int largestRectangleArea(vector<int> &heights)
{
	int n = heights.size();
	vector<int> leftMin(n), rightMin(n);
	stack<int> numSt{};

	for (int i = 0; i < n; ++i)
	{
		while (!numSt.empty() and heights[numSt.top()] >= heights[i])
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
		while (!numSt.empty() and heights[numSt.top()] >= heights[i])
			numSt.pop();

		if (numSt.empty())
			rightMin[i] = n - 1;
		else
			rightMin[i] = numSt.top() - 1;
		numSt.push(i);
	}

	int res{};
	for (int i = 0; i < n; ++i)
		res = max(res, heights[i] * (rightMin[i] - leftMin[i] + 1));

	return res;
}

void solve()
{
	vector<int> heights{2, 1, 5, 6, 2, 3};

	cout << largestRectangleArea(heights) << endl;
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
