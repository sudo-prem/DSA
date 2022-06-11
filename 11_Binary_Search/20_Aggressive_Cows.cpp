// Problem Link:
// https://www.spoj.com/problems/AGGRCOW/

// TC: O(n*log(n))
// SC: O(1)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

bool isPossible(vector<int> &stalls, int cows, int currLimit)
{
    int currCows{1}, currStall{stalls[0]};
    int n = stalls.size();

    for (int i = 1; i < n; ++i)
    {
        if (stalls[i] - currStall >= currLimit)
        {
            currCows++;
            currStall = stalls[i];
        }

        if (currCows >= cows)
            return true;
    }

    return false;
}

int largestMinDistance(vector<int> &stalls, int cows)
{
    if (cows > stalls.size())
        return -1;
    int n = stalls.size(), res{0};

    // Defining the search space
    int minValue{1}, maxValue = stalls[n - 1] - stalls[0];

    // Defining variables for search
    int low = minValue, high = maxValue, currLimit{};
    while (low <= high)
    {
        currLimit = low + (high - low) / 2;

        if (isPossible(stalls, cows, currLimit))
        {
            res = currLimit;
            low = currLimit + 1;
        }
        else
            high = currLimit - 1;
    }

    return res;
}

void solve()
{
    int n, cows, temp;
    cin >> n >> cows;

    vector<int> stalls;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        stalls.push_back(temp);
    }

    sort(stalls.begin(), stalls.end());
    cout << largestMinDistance(stalls, cows) << endl;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t{1};
    cin >> t;
    while (t--)
        solve();
    return 0;
}

