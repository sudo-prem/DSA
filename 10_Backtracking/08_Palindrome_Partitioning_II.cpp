// Problem Link:
// https://leetcode.com/problems/palindrome-partitioning-ii/

// Approach 1: (Brute Force)
// TC: O(n!)
// SC: O(n)

// Approach 2: (DP) (Not implemented yet)
// TC: O()
// SC: O()

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
bool isPalindrome(string s, int i, int j)
{
    while (i < j)
        if (s[i++] != s[j--])
            return false;
    return true;
}

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

int minCut(string s)
{
    vector<string> curr;
    int res{INT_MAX};
    int index{};

    helper(s, index, curr, res);
    return res;
}

void solve()
{
    string s{"aab"};
    int res = minCut(s);

    cout << res << endl;
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