#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

int trap(vector<int>& height)
{
	int n = height.size();
	vector<int> leftMax(n), rightMax(n);
	leftMax[0] = height[0], rightMax[n - 1] = height[n - 1];

	for (int i = 1; i < n; ++i)
		leftMax[i] = max(leftMax[i - 1], height[i]);
	for (int i = n - 2; i >= 0; --i)
		rightMax[i] = max(rightMax[i + 1], height[i]);

	int res{};
	for (int i = 0; i < n; ++i)
		res += min(leftMax[i], rightMax[i]) - height[i];
	return res;
}

void solve()
{
	vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	cout << trap(height) << endl;
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
