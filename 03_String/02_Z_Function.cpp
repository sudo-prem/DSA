// TC: O(n)
// SC: O(n+m)

#ifdef ONPC
	#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

vector<int> computeZ(string s)
{
    int n = s.size();
    vector<int> zVector(n);

    zVector[0] = 0;
    // i and j are index pointers
    int i = 0, j = 0;

    for (int k = 1; k < n; ++k)
    {
        if (k > i)
        {
            j = i = k;
            while (j < n and s[i] == s[i - j])
                i++;
            zVector[k] = i - j;
            i--;
        }
        else
        {
            // Copying from precalculated indices
            int k1 = k - j;
            if (zVector[k1] < i - k + 1)
                zVector[k] = zVector[k1];
            else
            {
                j = k;
                while (i < n && s[i] == s[i - j])
                    i++;
                zVector[k] = i - j;
                i--;
            }
        }
    }

    return zVector;
}

int zFunction(string text, string pattern)
{
    int textSize = text.size();
    int patternSize = pattern.size();

    // Add a character that is not used in text
    // '$' here
    string modifiedString = pattern + '$' + text;

    vector<int> zVector = computeZ(modifiedString);

    for (int i = 0; i < modifiedString.size(); ++i)
    {
        if (zVector[i] == patternSize)
            return (i - patternSize - 1);
    }

    return -1;
}

void solve()
{
    string text{"let's write somthing here"};
    string pattern{"hing h"};
    /* string pattern{"hiang h"}; */

    int res = zFunction(text, pattern);
    if (res == -1)
        cout << "No match found!\n";
    else
        cout << "Match Found at: " << res << endl;
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
