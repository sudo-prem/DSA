#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

char nextGreatestLetter(vector<char>& letters, char target)
{
	int n = letters.size();
	int low = 0, high = n - 1;

	// Upper Bound
	while (low <= high)
	{
		int mid = low + (high - low) / 2;

		if (letters[mid] <= target)
			low = mid + 1;
		else
			high = mid - 1;
	}

	if (low == n)
		return letters[0];
	return letters[low];
}

void solve()
{
	vector<char> letters{'c', 'f', 'j'};
	char target = 'a';

	cout << nextGreatestLetter(letters, target) << endl;
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
