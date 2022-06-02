#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
{
	unordered_map<int, int> hash{};
	stack<int> numSt{};
	int m = nums1.size(), n = nums2.size();

	for (int i = n - 1; i >= 0; --i)
	{
		while (!numSt.empty() and numSt.top() < nums2[i])
			numSt.pop();
		if (numSt.empty())
			hash[nums2[i]] = -1;
		else
			hash[nums2[i]] = numSt.top();
		numSt.push(nums2[i]);
	}

	vector<int> res{};
	for (auto itr : nums1)
		res.push_back(hash[itr]);
	return res;
}

void solve()
{
	vector<int> nums1{4, 1, 2}, nums2{1, 3, 4, 2};

	auto res = nextGreaterElement(nums1, nums2);
	for (auto itr : res)
		cout << itr << " ";
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
