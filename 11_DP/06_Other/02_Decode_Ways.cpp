#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

int helper(string &s, int pos, vector<int> &dp)
{
	int n = s.size();
	if (pos == n)
		return 1;
	if (s[pos] == '0')
		return 0;
	if (dp[pos] != -1)
		return dp[pos];

	int res{};
	if (pos + 1 < n)
	{
		int t = stoi(string({s[pos], s[pos + 1]}));
		if (t > 9 and t <= 26)
			res += helper(s, pos + 2, dp);
	}
	res += helper(s, pos + 1, dp);

	return dp[pos] = res;
}

int numDecodings1(string s)
{
	int n = s.size();
	vector<int> dp(n + 1, -1);

	return helper(s, 0, dp);
}

bool isPossible(string &s, int index)
{
	int n = s.size();
	if (index < 2)
		return false;

	char first = s[index - 2];
	char second = s[index - 1];
	if (first == '0' or first > '2')
		return false;
	if (first == '2' and second > '6')
		return false;
	return true;
}

int numDecodings2(string s)
{
	int n = s.size();
	vector<int> dp(n + 1, 0);
	dp[0] = 1;

	for (int i = 1; i <= n; ++i)
	{
		if (s[i - 1] != '0')
			dp[i] += dp[i - 1];
		if (isPossible(s, i))
			dp[i] += dp[i - 2];
	}

	return dp[n];
}

void solve()
{
	string s = "226";
	cout << numDecodings1(s) << endl;
	cout << numDecodings2(s) << endl;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ONPC
	freopen("input.txt", "r", stdin);
#endif
	int t {1};
	/* int i {1}; cin >> t; */
	while (t--)
	{
		/* cout << "Case #" << i++ << ": "; */
		solve();
	}
	return 0;
}
