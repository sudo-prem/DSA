// Problem Link:
// https://leetcode.com/problems/palindrome-partitioning-ii/

// Approach 1: (Brute Force)
// TC: O(n!)
// SC: O(n)

// Approach 2: (DP)
// TC: O()
// SC: O()

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

bool isPalindrome(string s, int i, int j)
{
	while (i < j)
		if (s[i++] != s[j--])
			return false;
	return true;
}

// Approach 1:
void helper(string s, int index, vector<string> &curr, int &res)
{
	if (index == s.size())
	{
		if (curr.size() - 1 < res)
			res = curr.size() - 1;
		return;
	}

	for (int i = index; i < s.size(); ++i)
	{
		if (isPalindrome(s, index, i))
		{
			curr.push_back(s.substr(index, i - index + 1));
			helper(s, i + 1, curr, res);
			curr.pop_back();
		}
	}
}

int minCut1(string s)
{
	vector<string> curr;
	int res{INT_MAX};
	int index{};

	helper(s, index, curr, res);
	return res;
}

// Approach 2:
int helper(string &s, int pos, vector<int> &dp)
{
	int n = s.size();
	if (pos == n)
		return 0;
	if (isPalindrome(s, pos, n - 1))
		return 0;
	if (dp[pos] != -1)
		return dp[pos];

	int res{INT_MAX};
	for (int i = pos; i < n; ++i)
		if (isPalindrome(s, pos, i))
			res = min(res, 1 + helper(s, i + 1, dp));

	return dp[pos] = res;
}

int minCut2(string s)
{
	int n = s.size();
	vector<int> dp(n + 1, -1);

	return helper(s, 0, dp);
}

void solve()
{
	string s{"aab"};

	cout << minCut1(s) << endl;
	cout << minCut2(s) << endl;
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
