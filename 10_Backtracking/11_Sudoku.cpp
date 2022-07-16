#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

bool isValid(vector<vector<char>> &board, int row, int col, char value)
{
	for (int i = 0; i < 9; ++i)
		if (board[row][i] == value or board[i][col] == value)
			return false;

	int x, y;
	for (int i = 0; i < 3; ++i)
	{
		x = (row / 3) * 3 + i;
		for (int j = 0; j < 3; ++j)
		{
			y = (col / 3) * 3 + j;
			if (board[x][y] == value)
				return false;
		}
	}

	return true;
}

bool helper(vector<vector<char>> &board)
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (board[i][j] == '.')
			{
				for (char c = '1'; c <= '9'; ++c)
				{
					if (isValid(board, i, j, c))
					{
						board[i][j] = c;
						if (helper(board))
							return true;
						board[i][j] = '.';
					}
				}
				return false;
			}
		}
	}
	return true;
}

void solveSudoku(vector<vector<char>>& board)
{
	helper(board);
}

void solve()
{
	vector<vector<char>> board
	{
		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
	};

	solveSudoku(board);

	for (auto itr : board)
	{
		for (char c : itr)
			cout << c << " ";
		cout << endl;
	}
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
