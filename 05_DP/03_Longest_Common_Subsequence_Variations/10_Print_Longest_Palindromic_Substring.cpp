#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
// Recursion
// Memoization of this Recursive solution is not feasible
// for each state there are 4 variable to cache
// (low high, left, right)
string helper1(string &word, int low, int high, string left, string right)
{
    if (low > high)
        return left + right;
    if (low == high)
        return left + word[low] + right;

    string res1{}, res2{}, res3{};
    if (word[low] == word[high])
        res1 = helper1(word, low + 1, high - 1, left + word[low], word[high] + right);
    res2 = helper1(word, low, high - 1, "", "");
    res3 = helper1(word, low + 1, high, "", "");

    if (res1.size() > res2.size())
        return (res1.size() > res3.size()) ? res1 : res3;
    return (res2.size() > res3.size()) ? res2 : res3;
}

string longestPalindromicSubstring1(string word)
{
    return helper1(word, 0, word.size() - 1, "", "");
}

// Approach 2:
// Tabulation + Iteration
// Find LCSubstring with word and reversed word
// *** Dry Run, then code ***
string longestPalindromicSubstring2(string word)
{
    // Data Structures
    int n = word.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    int maxLen{1}, index{0};

    // Initialization
    // Fill up the first and second diagonal
    for (int i = 0; i < n; ++i)
    {
        dp[i][i] = 1;
        if (i + 1 != n and word[i] == word[i + 1])
        {
            dp[i][i + 1] = 1;
            index = i;
            maxLen = 2;
        }
    }

    // Tabulation
    // Start filling from the third diagonal
    for (int i = 2; i < n; ++i)
    {
        for (int j = 0; j < n - i + 1; ++j)
        {
            if (word[j] == word[j + i] and dp[j + 1][j + i - 1])
            {
                dp[j][j + i] = 1;
                // Since 0 -> i is the length, we check with (i+1)
                if (i + 1 > maxLen)
                {
                    index = j;
                    maxLen = i + 1;
                }
            }
        }
    }

    return word.substr(index, maxLen);
}

void solve()
{
    // string word{"babad"};
    string word{"aacabdkacaa"};
    // string word{"aacabacaa"};
    cout << longestPalindromicSubstring1(word) << endl;
    cout << longestPalindromicSubstring2(word) << endl;
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