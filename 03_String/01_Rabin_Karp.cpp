// TC: O(n-m+1) [Assumption: No Spurious Hit/ Collision in Hashing]
// SC: O(1)

#ifdef ONPC
	#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

#define powerValue 256
#define modValue INT_MAX

// Since we have taken hash function's return value to be integer
// We should mod our values by INT_MAX to avoid overflow
int rollingHash(int textHash, char add, char rem, int highestPower)
{
    textHash = ((powerValue * (textHash - (rem * highestPower))) + add) % modValue;

    if (textHash < 0)
        textHash += modValue;

    return textHash;
}

int hashValue(string &s, int n)
{
    int res{};

    for (int i = 0; i < n; i++)
        res = (powerValue * res + s[i]) % modValue;

    return res;
}

bool checkSame(string &s1, string &s2, int start, int end)
{
	for(int i=start; i<end; ++i)
		if(s1[i-start] != s2[i])
			return false;

	return true;
}

int searchPattern(string text, string pattern)
{
    int patternSize = pattern.size();
    int textSize = text.size();
    char add{}, rem{};

    int highestPower{1};
    for (int i = 0; i < patternSize - 1; ++i)
        highestPower = (highestPower * powerValue) % modValue;

    int patternHash = hashValue(pattern, patternSize);
    int textHash = hashValue(text, patternSize);

    for (int i = 0; i <= textSize - patternSize; ++i)
    {
        if (textHash == patternHash)
            if (checkSame(pattern, text, i, pattern.size()))
                return i;

        rem = text[i];
        add = text[i + patternSize];
        textHash = rollingHash(textHash, add, rem, highestPower);
    }

    return -1;
}

void solve()
{
	string text = "let me type something here";
    string pattern = "ing he";

    int res = searchPattern(text, pattern);
    if (res == -1)
        cout << "Cannot find pattern!" << endl;
    else
        cout << "Found pattern at: " << res << endl;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ONPC
	freopen("input.txt", "r", stdin);
#endif
	int t{1};
	/* int i{1}; cin >> t; */
	while (t--)
	{
		/* cout << "Case #" << i++ << ": "; */
		solve();
	}
	return 0;
}
