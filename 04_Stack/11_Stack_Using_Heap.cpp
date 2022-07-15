#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

class Stack
{
private:
	int index;
	priority_queue<pii> maxHeap;

public:
	Stack() 
	{
		this->index = 0;
	}

	int size()
	{
		return index;
	}

	void push(int num)
	{
		maxHeap.push({index++, num});
	}

	void pop()
	{
		maxHeap.pop();
		index--;
	}

	int top()
	{
		return maxHeap.top().second;
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

