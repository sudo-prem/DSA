// Problem Link:
// https://leetcode.com/problems/palindrome-partitioning/solution/

// TC: O()
// SC: O()

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

bool isPalindrome(string s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

void helper(string s, int index, vector<string> &curr, vector<vector<string>> &res)
{
    if (index == s.size())
    {
        res.push_back(curr);
        return;
    }

    for (int i = index; i < s.size(); ++i)
    {
        if (isPalindrome(s, index, i))
        {
            curr.push_back(s.substr(index, i + 1 - index));
            helper(s, i + 1, curr, res);
            curr.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<string> curr;
    vector<vector<string>> res;

    helper(s, 0, curr, res);
    return res;
}

void solve()
{
    string s{"aab"};
    vector<vector<string>> res = partition(s);

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