// Problem Link:
// https://leetcode.com/problems/subsets-ii/

// TC: O(2^n)
// SC: O((2^n) + (log(n)))

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

void helper(vector<int> &nums, int index, vector<int> &curr, vector<vector<int>> &res)
{
	res.push_back(curr);

	int n = nums.size();
	for (int i = index; i < n; ++i)
	{
		if (i > index and nums[i] == nums[i - 1])
			continue;

		curr.push_back(nums[i]);
		helper(nums, i + 1, curr, res);
		curr.pop_back();
	}
}

vector<vector<int>> subsetsWithDup(vector<int>& nums)
{
	vector<int> curr{};
	vector<vector<int>> res{};
	sort(nums.begin(), nums.end());

	helper(nums, 0, curr, res);
	return res;
}

void solve()
{
	vector<int> nums{1, 2, 2, 3};
	vector<vector<int>> res = subsetsWithDup(nums);

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
