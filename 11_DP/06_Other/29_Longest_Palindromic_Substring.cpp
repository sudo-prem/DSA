#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

void expandFromMiddle(string &s, int i, int j, string &res)
{
	int n = s.size();
	while (i >= 0 and j < n and s[i] == s[j])
		i--, j++;
	i++, j--;

	if (j - i + 1 > res.size())
		res = s.substr(i, j - i + 1);
}

string longestPalindrome(string s)
{
	int n = s.size();
	string res{};

	for (int i = 0; i < n; ++i)
	{
		expandFromMiddle(s, i, i, res);
		expandFromMiddle(s, i, i + 1, res);
	}

	return res;
}

void solve()
{
	cout << longestPalindrome("aaaabbaa") << endl;
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
