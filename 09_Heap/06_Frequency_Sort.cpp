#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

class Comparator
{
public:
	bool operator()(const pii &p1, const pii &p2)
	{
		if (p1.first == p2.first)
			return p1.second < p2.second;
		return p1 > p2;
	}
};

vector<int> frequencySort(vector<int>& nums)
{
	unordered_map<int, int> hash{};
	for (int num : nums)
		hash[num]++;

	priority_queue<pii, vector<pii>, Comparator> minHeap{};
	for (auto itr : hash)
		minHeap.push({itr.second, itr.first});

	vector<int> res{};
	while (!minHeap.empty())
	{
		int curr = minHeap.top().second;
		int freq = minHeap.top().first;
		minHeap.pop();

		while (freq--)
			res.push_back(curr);
	}

	return res;
}

void solve()
{
	vector<int> nums{1, 1, 2, 2, 2, 3};
	auto res = frequencySort(nums);

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
