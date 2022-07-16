// Problem Link:
// https://leetcode.com/problems/combination-sum/

// TC: O(n^target)
// SC: O(target)

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
		curr.push_back(nums[i]);
		helper(nums, target - nums[i], i, curr, res);
		curr.pop_back();
	}
}

vector<vector<int>> combinationSum(vector<int> &nums, int target)
{
	sort(nums.begin(), nums.end());
	vector<int> curr{};
	vector<vector<int>> res{};

	helper(nums, target, 0, curr, res);
	return res;
}

void solve()
{
	vector<int> nums{2, 3, 6, 7};
	int target = 7;

	vector<vector<int>> res = combinationSum(nums, target);
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
