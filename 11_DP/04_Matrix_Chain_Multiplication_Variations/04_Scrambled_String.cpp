// Problem Link:
// https://leetcode.com/problems/scramble-string/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
// Recursion
bool isScramble1(string a, string b)
{
    int n = a.size();
    int m = b.size();

    // Base Conditions
    if (n != m)
        return false;
    if (a == b)
        return true;
    if (n <= 1)
        return false;

    // Recursive Calls
    for (int i = 1; i < n; ++i)
    {
        bool notSwapped = isScramble1(a.substr(0, i), b.substr(0, i)) and
                          isScramble1(a.substr(i, n - i), b.substr(i, n - i));
        if (notSwapped)
            return true;

        bool swapped = isScramble1(a.substr(0, i), b.substr(n - i, i)) and
                       isScramble1(a.substr(i, n - i), b.substr(0, n - i));
        if (swapped)
            return true;
    }

    return false;
}

// Approach 2:
// Recursion + Memoization
bool helper2(string a, string b, unordered_map<string, bool> &dp)
{
    int n = a.size();
    int m = b.size();

    // Base Conditions
    if (n != m)
        return false;
    if (a == b)
        return true;
    if (n <= 1)
        return false;

    string key = a + " " + b;
    if (dp.find(key) != dp.end())
        return dp[key];

    // Recursive Calls
    for (int i = 1; i < n; ++i)
    {
        bool notSwapped = helper2(a.substr(0, i), b.substr(0, i), dp) and
                          helper2(a.substr(i, n - i), b.substr(i, n - i), dp);
        if (notSwapped)
            return dp[key] = true;

        bool swapped = helper2(a.substr(0, i), b.substr(n - i, i), dp) and
                       helper2(a.substr(i, n - i), b.substr(0, n - i), dp);
        if (swapped)
            return dp[key] = true;
    }

    return dp[key] = false;
}

bool isScramble2(string a, string b)
{
    unordered_map<string, bool> dp;

    return helper2(a, b, dp);
}

// Approach 3:
// Recursion + Memoization + Frequency Check
// Equate frequency of char in a and b before calling recursively
bool helper3(string a, string b, unordered_map<string, bool> &dp)
{
    int n = a.size();
    int m = b.size();

    // Base Conditions
    if (n != m)
        return false;
    if (a == b)
        return true;
    if (n <= 1)
        return false;

    string key = a + " " + b;
    if (dp.find(key) != dp.end())
        return dp[key];

    // Frequency test
    vector<int> hash1(26, 0);
    vector<int> hash2(26, 0);
    for (int i = 0; i < n; ++i)
    {
        hash1[a[i] - 'a']++;
        hash2[b[i] - 'a']++;
    }
    if (hash1 != hash2)
        return dp[key] = false;

    // Recursive Calls
    for (int i = 1; i < n; ++i)
    {
        bool notSwapped = helper3(a.substr(0, i), b.substr(0, i), dp) and
                          helper3(a.substr(i, n - i), b.substr(i, n - i), dp);
        if (notSwapped)
            return dp[key] = true;

        bool swapped = helper3(a.substr(0, i), b.substr(n - i, i), dp) and
                       helper3(a.substr(i, n - i), b.substr(0, n - i), dp);
        if (swapped)
            return dp[key] = true;
    }

    return dp[key] = false;
}

bool isScramble3(string a, string b)
{
    unordered_map<string, bool> dp;

    return helper3(a, b, dp);
}

void solve()
{
    string a{"great"};
    string b{"rgeat"};

    isScramble1(a, b) ? cout << "True\n" : cout << "False\n";
    isScramble2(a, b) ? cout << "True\n" : cout << "False\n";
    isScramble3(a, b) ? cout << "True\n" : cout << "False\n";
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