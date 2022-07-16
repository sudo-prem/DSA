// Problem Link:
// https://leetcode.com/problems/permutations/

// Approach 1: (Searching)
// TC: O((n^2)*n!)
// TC: O(1)

// Approach 2: (Swapping)
// TC: O(n!)
// TC: O(1)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1
void helper_1(vector<int> &nums, vector<int> &curr, vector<vector<int>> &res)
{
	if (curr.size() == nums.size())
	{
		res.push_back(curr);
		return;
	}

	for (int i = 0; i < nums.size(); ++i)
	{
		if (find(curr.begin(), curr.end(), nums[i]) == curr.end())
		{
			curr.push_back(nums[i]);
			helper_1(nums, curr, res);
			curr.pop_back();
		}
	}
}

vector<vector<int>> permute_1(vector<int> &nums)
{
	vector<int> curr;
	vector<vector<int>> res;

	helper_1(nums, curr, res);
	return res;
}

// Approach 2
void helper_2(vector<int> &nums, int index, vector<vector<int>> &res)
{
	if (index == nums.size())
	{
		res.push_back(nums);
		return;
	}

	for (int i = index; i < nums.size(); ++i)
	{
		swap(nums[index], nums[i]);
		helper_2(nums, index + 1, res);
		swap(nums[index], nums[i]);
	}
}

vector<vector<int>> permute_2(vector<int> &nums)
{
	vector<vector<int>> res;
	int index{};

	helper_2(nums, index, res);
	return res;
}

void solve()
{
	vector<int> nums{1, 2, 3};
	vector<vector<int>> res;

	res = permute_1(nums);
	for (auto i : res)
	{
		cout << "[ ";
		for (auto j : i)
			cout << j << " ";
		cout << "] ";
	}
	cout << endl;

	res = permute_2(nums);
	for (auto i : res)
	{
		cout << "[ ";
		for (auto j : i)
			cout << j << " ";
		cout << "] ";
	}
	cout << endl;
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
