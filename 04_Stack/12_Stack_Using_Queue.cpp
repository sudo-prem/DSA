#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

class Stack
{
private:
	queue<int> numQu;

public:
	void push(int num)
	{
		int n = numQu.size();
		numQu.push(num);

		for(int i=0; i<n; ++i)
		{
			int t = numQu.front();
			numQu.pop();
			numQu.push(t);
		}
	}

	int top()
	{
		return numQu.front();
	}

	void pop()
	{
		numQu.pop();
	}

	int size()
	{
		return numQu.size();
	}
};

void solve()
{
	Stack myStack;
	vector<int> nums{1,6, 17, 32, 45};
	for(int num: nums)
		myStack.push(num);

	cout << myStack.top() << " ";
	myStack.pop();
	cout << myStack.top() << " ";
	myStack.pop();

	myStack.push(5);
	cout << myStack.size() << endl;
	cout << myStack.top() << " ";
	cout << myStack.size() << endl;
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

