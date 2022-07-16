// Problem Link: (Power Set)
// https://leetcode.com/problems/subsets/

// Approach 1: (Backtracking)
// TC: O(2^n)
// SC: O(2^n)

// Approach 2: (Bit-Manipulation)
// TC: O(2^n)
// SC: O(2^n)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
void helper1(vector<int> &nums, int index, vector<int> &curr, vector<vector<int>> &res)
{
	res.push_back(curr);

	for (int i = index; i < nums.size(); ++i)
	{
		curr.push_back(nums[i]);
		helper1(nums, i + 1, curr, res);
		curr.pop_back();
	}
}

vector<vector<int>> subsets1(vector<int> &nums)
{
	vector<vector<int>> res;
	vector<int> curr;
	helper1(nums, 0, curr, res);
	return res;
}

// Approach 2:
bool isSet(int num, int pos)
{
	return (num & (1 << pos));
}

vector<vector<int>> subsets2(vector<int> &nums)
{
	vector<vector<int>> res{};
	vector<int> curr{};
	int n = nums.size();

	for (int i = 0; i < (1 << n); ++i)
	{
		curr = {};
		for (int j = 0; j < n; ++j)
		{
			if (isSet(i, j))
				curr.push_back(nums[j]);
		}
		res.push_back(curr);
	}

	return res;
}

void solve()
{
	vector<int> nums{1, 2, 3};
	vector<vector<int>> res;

	res = subsets1(nums);
	for (auto i : res)
	{
		cout << "[ ";
		for (auto j : i)
			cout << j << " ";
		cout << "]" << endl;
	}

	cout << endl;

	res = subsets2(nums);
	for (auto i : res)
	{
		cout << "[ ";
		for (auto j : i)
			cout << j << " ";
		cout << "]" << endl;
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
