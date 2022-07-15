#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

#define pii pair<int, int>

class Comparator
{
public:
	bool operator()(const pii &num1, const pii &num2)
	{
		return num1 > num2;
	}
};

vector<int> topKFrequent(vector<int> &nums, int k)
{
	vector<int> res{};
	unordered_map<int, int> hash{};
	priority_queue<pii, vector<pii>, greater<pii>> minHeap{};

	for (int num : nums)
		hash[num]++;

	auto itr = hash.begin();
	int t = k;
	while (t--)
	{
		minHeap.push({itr->second, itr->first});
		itr++;
	}

	while (itr != hash.end())
	{
		if (minHeap.top().first < itr->second)
		{
			minHeap.pop();
			minHeap.push({itr->second, itr->first});
		}
		itr++;
	}

	while (minHeap.empty() == false)
	{
		res.push_back(minHeap.top().second);
		minHeap.pop();
	}

	return res;
}

void solve()
{
	vector<int> nums{1, 1, 1, 2, 2, 3};
	int k = 2;

	auto res = topKFrequent(nums, k);

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
