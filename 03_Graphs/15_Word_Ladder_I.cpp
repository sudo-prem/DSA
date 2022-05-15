// Problem Link:
// https://leetcode.com/problems/word-ladder/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1: (Recursion + Backtracking) (DFS)
bool isAdjacent(string &s1, string &s2)
{
    int count{};
    int n = s1.size();
    for (int i = 0; i < n; ++i)
    {
        if (s1[i] != s2[i])
        {
            count++;
            if (count > 1)
                return false;
        }
    }

    return true;
}

int helper1(string &begin, string &end, vector<string> &words, vector<bool> &visited)
{
    if (begin == end)
        return 1;

    int n = words.size();
    int minSeq{INT_MAX};
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i] and isAdjacent(begin, words[i]))
        {
            visited[i] = true;
            int temp = helper1(words[i], end, words, visited);
            visited[i] = false;

            if (temp != INT_MAX)
                temp++;
            minSeq = min(minSeq, temp);
        }
    }

    return minSeq;
}

int ladderLength1(string &begin, string &end, vector<string> &words)
{
    int n = words.size();

    vector<bool> visited(n, false);
    int ans = helper1(begin, end, words, visited);

    if (ans == INT_MAX)
        return 0;
    return ans;
}

// Approach 2: (Graph BFS - Similar to Level Order)
int ladderLength2(string &begin, string &end, vector<string> &wordList)
{
    // Algorithm
    // 1. Create a set from words
    // 2. Check if end word is present in set
    // 3. Traverse by BFS and check if adjacent word is present
    set<string> words(wordList.begin(), wordList.end());
    if (words.find(end) == words.end())
        return 0;

    queue<string> nodeQu{};
    nodeQu.push(begin);
    int level{}, queueSize{};

    while (!nodeQu.empty())
    {
        level++;
        queueSize = nodeQu.size();

        while (queueSize--)
        {
            string curr = nodeQu.front();
            nodeQu.pop();

            // Iterate throught each character
            int n = curr.size();
            for (int i = 0; i < n; ++i)
            {
                // Change current position character to a
                // new character and check if it is in set
                char prevChar = curr[i];
                for (char c = 'a'; c <= 'z'; ++c)
                {
                    curr[i] = c;
                    if (c != prevChar)
                    {
                        if (curr == end)
                            return level + 1;
                        if (words.find(curr) != words.end())
                        {
                            nodeQu.push(curr);
                            words.erase(curr);
                        }
                    }
                }
                // Change back to the original stringa
                curr[i] = prevChar;
            }
        }
    }

    return 0;
}

void solve()
{
    string begin{"hit"};
    string end{"cog"};
    vector<string> words{"hot", "dot", "dog", "lot", "log", "cog"};

    cout << ladderLength1(begin, end, words) << endl;
    cout << ladderLength2(begin, end, words) << endl;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t{1};
    // cin >> t;
    while (t--)
        solve();
    return 0;
}