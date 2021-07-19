// Problem Link:
// https://leetcode.com/problems/super-egg-drop/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
// Recursion
int superEggDrop1(int e, int f)
{
    if (f <= 1 or e == 1)
        return f;

    int minAttempt{INT_MAX};
    for (int i = 1; i <= f; ++i)
    {
        int currAttempt = 1 + max(superEggDrop1(e - 1, i - 1),
                                  superEggDrop1(e, f - i));
        minAttempt = min(minAttempt, currAttempt);
    }

    return minAttempt;
}

// Approach 2:
// Recursion + Memoization
int helper2(int e, int f, vector<vector<int>> &dp)
{
    if (f <= 1 or e == 1)
        return f;

    if (dp[e][f] != -1)
        return dp[e][f];

    int minAttempt{INT_MAX};
    for (int i = 1; i <= f; ++i)
    {
        int currAttempt = 1 + max(helper2(e - 1, i - 1, dp),
                                  helper2(e, f - i, dp));
        minAttempt = min(minAttempt, currAttempt);
    }

    return dp[e][f] = minAttempt;
}

int superEggDrop2(int e, int f)
{
    vector<vector<int>> dp(e + 1, vector<int>(f + 1, -1));

    return helper2(e, f, dp);
}

void solve()
{
    int e = 3, f = 14;

    cout << superEggDrop1(e, f) << endl;
    cout << superEggDrop2(e, f) << endl;
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