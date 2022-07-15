#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

// O(n) Time and Space
int longestValidParentheses1(string s)
{
    int n = s.size(), res{};
    int open{}, close{};

    // Left to Right
    for(int i=0; i<n; ++i)
    {
        if(s[i] == '(')
            open++;
        else
            close++;

        if(close > open)
            open = close = 0;
        else if(open == close)
            res = max(res, open + close);
    }

    // Reset open, close values
    open = close = 0;

    // Right to Left
    for(int i=n-1; i>=0; --i)
    {
        if(s[i] == ')')
            open++;
        else
            close++;

        if(close > open)
            open = close = 0;
        else if(open == close)
            res = max(res, open + close);
    }

    return res;
}

// Using stack
int longestValidParentheses2(string &s)
{
    int curr{}, res{}, n = s.size();
    stack<int> st{};
    st.push(-1);

    for(int i=0; i<n; ++i)
    {
        if(s[i] == '(')
            st.push(i);
        else
        {
            st.pop();
            if(st.empty())
                st.push(i);
            else
                res = max(res, i-st.top());
        }
    }

    return res;
}

void solve()
{
	string s{")()())"};

	cout << longestValidParentheses1(s) << endl;
	cout << longestValidParentheses2(s) << endl;
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

