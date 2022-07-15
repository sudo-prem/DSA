#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

vector<int> findClosestElements(vector<int>& nums, int k, int x)
{
	int n = nums.size();
	priority_queue<pii> maxHeap{};

	for (int i = 0; i < k; ++i)
		maxHeap.push({abs(x - nums[i]), nums[i]});

	for (int i = k; i < n; ++i)
	{
		pii curr = {abs(x - nums[i]), nums[i]};

		if (maxHeap.top() > curr)
		{
			maxHeap.pop();
			maxHeap.push(curr);
		}
	}

	vector<int> res{};
	while (maxHeap.empty() == false)
	{
		res.push_back(maxHeap.top().second);
		maxHeap.pop();
	}

	sort(res.begin(), res.end());
	return res;
}

void solve()
{
	vector<int> nums{1, 2, 3, 4, 5};
	int k = 4, x = 3;

	auto res = findClosestElements(nums, k, x);
	for (int num : res)
		cout << num << " ";
	cout << endl;
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
