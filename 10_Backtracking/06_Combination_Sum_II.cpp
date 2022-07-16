// Problem Link:
// https://leetcode.com/problems/combination-sum-ii/

// TC: O(2^n)
// SC: O(n)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

void helper(vector<int> &nums, int target, int index, vector<int> &curr, vector<vector<int>> &res)
{
	if (target <= 0)
	{
		if (target == 0)
			res.push_back(curr);
		return;
	}

	for (int i = index; i < nums.size(); ++i)
	{
		if (i > index and nums[i] == nums[i - 1])
			continue;

		curr.push_back(nums[i]);
		helper(nums, target - nums[i], i + 1, curr, res);
		curr.pop_back();
	}
}

vector<vector<int>> combinationSum2(vector<int> &nums, int target)
{
	sort(nums.begin(), nums.end());
	vector<int> curr{};
	vector<vector<int>> res{};
	int index = 0;

	helper(nums, target, index, curr, res);
	return res;
}

void solve()
{
	vector<int> nums{10, 1, 2, 7, 6, 1, 5};
	int target = 8;

	vector<vector<int>> res = combinationSum2(nums, target);
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
