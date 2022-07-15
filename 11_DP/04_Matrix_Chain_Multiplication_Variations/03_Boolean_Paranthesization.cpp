// Problem Link:
// https://www.interviewbit.com/problems/evaluate-expression-to-true/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
// Recursion (TLE)
int countHelper1(string &expression, int i, int j, bool target)
{
    if (i == j)
    {
        if (target == true)
            return expression[i] == 'T';
        else
            return expression[i] == 'F';
    }

    // ( T & F ^ T | F )
    //     ^   ^   ^     k should increase by 2,
    //     |   |   |     starting from i+1 till j-1 (inclusive)
    int totalCount{};
    for (int k = i + 1; k < j; k += 2)
    {
        int leftTrue = countHelper1(expression, i, k - 1, true);
        int leftFalse = countHelper1(expression, i, k - 1, false);
        int rightTrue = countHelper1(expression, k + 1, j, true);
        int rightFalse = countHelper1(expression, k + 1, j, false);

        int currCount{};
        if (expression[k] == '|')
        {
            if (target == true)
                currCount = ((leftTrue * rightFalse) +
                             (leftTrue * rightTrue) +
                             (leftFalse * rightTrue));
            else
                currCount = (leftFalse * rightFalse);
        }
        else if (expression[k] == '&')
        {
            if (target == true)
                currCount = (leftTrue * rightTrue);
            else
                currCount = ((leftTrue * rightFalse) +
                             (leftFalse * rightFalse) +
                             (leftFalse * rightTrue));
        }
        else
        {
            if (target == true)
                currCount = (leftTrue * rightFalse) +
                            (leftFalse * rightTrue);
            else
                currCount = (leftTrue * rightTrue) +
                            (leftFalse * rightFalse);
        }

        totalCount += currCount;
    }

    return totalCount;
}

int countWays1(string &expression)
{
    // Since for a single expression to be true or false
    // there are so many different sub-expressions
    // which when true leads 'n' results
    // and when false leads 'm' results
    // We take a boolean variable to assist to our target boolean
    int n = expression.size();

    return countHelper1(expression, 0, n - 1, true);
}

// Approach 2:
// Recursion + Memoization (3D vector)
int countHelper2(string &expression, int i, int j, bool target, vector<vector<vector<int>>> &dp)
{
    if (i == j)
    {
        if (target == true)
            return expression[i] == 'T';
        else
            return expression[i] == 'F';
    }

    if (dp[i][j][target] != -1)
        return dp[i][j][target];

    // ( T & F ^ T | F )
    //     ^   ^   ^     k should increase by 2,
    //     |   |   |     starting from i+1 till j-1 (inclusive)
    int totalCount{};
    for (int k = i + 1; k < j; k += 2)
    {
        int leftTrue = (dp[i][k - 1][true] == -1) ? countHelper2(expression, i, k - 1, true, dp) : dp[i][k - 1][true];
        int leftFalse = (dp[i][k - 1][false] == -1) ? countHelper2(expression, i, k - 1, false, dp) : dp[i][k - 1][false];
        int rightTrue = (dp[k + 1][j][true] == -1) ? countHelper2(expression, k + 1, j, true, dp) : dp[k + 1][j][true];
        int rightFalse = (dp[k + 1][j][false] == -1) ? countHelper2(expression, k + 1, j, false, dp) : dp[k + 1][j][false];

        int currCount{};
        if (expression[k] == '|')
        {
            if (target == true)
                currCount = ((leftTrue * rightFalse) +
                             (leftTrue * rightTrue) +
                             (leftFalse * rightTrue));
            else
                currCount = (leftFalse * rightFalse);
        }
        else if (expression[k] == '&')
        {
            if (target == true)
                currCount = (leftTrue * rightTrue);
            else
                currCount = ((leftTrue * rightFalse) +
                             (leftFalse * rightFalse) +
                             (leftFalse * rightTrue));
        }
        else
        {
            if (target == true)
                currCount = (leftTrue * rightFalse) +
                            (leftFalse * rightTrue);
            else
                currCount = (leftTrue * rightTrue) +
                            (leftFalse * rightFalse);
        }

        totalCount += currCount;
    }

    // If question states to mod the result
    // return dp[i][j][target] = totalCount % mod;
    return dp[i][j][target] = totalCount;
}

int countWays2(string &expression)
{
    // Since for a single expression to be true or false
    // there are so many different sub-expressions
    // which when true leads 'n' results
    // and when false leads 'm' results
    // We take a boolean variable to assist to our target boolean
    int n = expression.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));

    return countHelper2(expression, 0, n - 1, true, dp);
}

// Approach 3:
// Recursion + Memoization (map<string, int>)
int countHelper3(string &expression, int i, int j, bool target, unordered_map<string, int> &dp)
{
    if (i == j)
    {
        if (target == true)
            return expression[i] == 'T';
        else
            return expression[i] == 'F';
    }

    string key = to_string(i) + " " + to_string(j) + " " + to_string(target);
    if (dp.find(key) != dp.end())
        return dp[key];

    // ( T & F ^ T | F )
    //     ^   ^   ^     k should increase by 2,
    //     |   |   |     starting from i+1 till j-1 (inclusive)
    int totalCount{};
    for (int k = i + 1; k < j; k += 2)
    {
        int leftTrue = countHelper3(expression, i, k - 1, true, dp);
        int leftFalse = countHelper3(expression, i, k - 1, false, dp);
        int rightTrue = countHelper3(expression, k + 1, j, true, dp);
        int rightFalse = countHelper3(expression, k + 1, j, false, dp);

        int currCount{};
        if (expression[k] == '|')
        {
            if (target == true)
                currCount = ((leftTrue * rightFalse) +
                             (leftTrue * rightTrue) +
                             (leftFalse * rightTrue));
            else
                currCount = (leftFalse * rightFalse);
        }
        else if (expression[k] == '&')
        {
            if (target == true)
                currCount = (leftTrue * rightTrue);
            else
                currCount = ((leftTrue * rightFalse) +
                             (leftFalse * rightFalse) +
                             (leftFalse * rightTrue));
        }
        else
        {
            if (target == true)
                currCount = (leftTrue * rightFalse) +
                            (leftFalse * rightTrue);
            else
                currCount = (leftTrue * rightTrue) +
                            (leftFalse * rightFalse);
        }

        totalCount += currCount;
    }

    // If question states to mod the result
    // return dp[key] = totalCount % mod;
    return dp[key] = totalCount;
}

int countWays3(string &expression)
{
    // Since for a single expression to be true or false
    // there are so many different sub-expressions
    // which when true leads 'n' results
    // and when false leads 'm' results
    // We take a boolean variable to assist to our target boolean
    int n = expression.size();
    unordered_map<string, int> dp;

    return countHelper3(expression, 0, n - 1, true, dp);
}

void solve()
{
    string expression{"T^F|F"};
    // string expression{"T|T&F^T"};

    cout << countWays1(expression) << endl;
    cout << countWays2(expression) << endl;
    cout << countWays3(expression) << endl;
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