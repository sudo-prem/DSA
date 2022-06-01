#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

class Comparator
{
public:
	bool operator()(const int &a, const int &b)
	{
		return a > b;
	}
};

vector<int> sortKSorted(vector<int> &nums, int k)
{
	int j{}, n = nums.size();
	priority_queue<int, vector<int>, Comparator> minHeap{};

	for (int i = 0; i < k; ++i)
		minHeap.push(nums[i]);

	for (int i = k; i < n; ++i)
	{
		minHeap.push(nums[i]);

		nums[j++] = minHeap.top();
		minHeap.pop();
	}

	while (j < n)
	{
		nums[j++] = minHeap.top();
		minHeap.pop();
	}

	return nums;
}

void solve()
{
	vector<int> nums{6, 5, 3, 2, 8, 10, 9};
	int k = 3;

	auto res = sortKSorted(nums, k);
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
