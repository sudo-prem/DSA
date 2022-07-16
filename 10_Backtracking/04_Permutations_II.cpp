// Problem Link:
// https://leetcode.com/problems/permutations-ii/

// TC: O(n!)
// SC: O(2^n)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

void helper(vector<int> &nums, int pos, vector<vector<int>> &res)
{
	int n = nums.size();
	if (pos == n)
	{
		res.push_back(nums);
		return;
	}

	unordered_set<int> hash{};
	for (int i = pos; i < n; ++i)
	{
		if (hash.find(nums[i]) != hash.end())
			continue;

		swap(nums[i], nums[pos]);
		helper(nums, pos + 1, res);
		swap(nums[i], nums[pos]);

		hash.insert(nums[i]);
	}
}

vector<vector<int>> permuteUnique(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	vector<vector<int>> res{};

	helper(nums, 0, res);
	return res;
}

void solve()
{
	vector<int> nums{1, 1, 2};
	vector<vector<int>> res = permuteUnique(nums);

	for (auto i : res)
	{
		cout << "[ ";
		for (auto j : i)
			cout << j << " ";
		cout << "]\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t{1};
	// cin >> t;
	while (t--)
		solve();
	return 0;
}
