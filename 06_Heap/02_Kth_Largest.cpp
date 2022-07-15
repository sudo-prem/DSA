#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

int findKthLargest(vector<int>& nums, int k)
{
	priority_queue<int, vector<int>, greater<int>> minHeap;
	int n = nums.size();

	for (int i = 0; i < k; ++i)
		minHeap.push(nums[i]);

	for (int i = k; i < n; ++i)
	{
		if (minHeap.top() < nums[i])
		{
			minHeap.pop();
			minHeap.push(nums[i]);
		}
	}

	return minHeap.top();
}

void solve()
{
	vector<int> nums{3, 2, 1, 5, 6, 4};
	int k = 2;

	cout << findKthLargest(nums, k) << endl;
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
