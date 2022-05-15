// Problem Link:
// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

// TC: O(n)
// SC: O(n)

#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    vector<vector<int>> List;

public:
    Graph(int n);
    void addEdge(int u, int v);
    void displayList();
    vector<int> BFS();
    void BFSHelper(int start, vector<bool> &visited, vector<int> &bfs);
};

Graph::Graph(int n)
{
    List.resize(n + 1);
}

void Graph::addEdge(int u, int v)
{
    List[u].push_back(v);
    List[v].push_back(u);
}

void Graph::displayList()
{
    int size = List.size();
    int count{};
    for (auto i : List)
    {
        cout << count++ << ": ";
        for (auto j : i)
            cout << j << " ";
        cout << "\n";
    }
    cout << "\n";
}

void Graph::BFSHelper(int start, vector<bool> &visited, vector<int> &bfs)
{
    queue<int> nodeQu;
    nodeQu.push(start);
    visited[start] = true;

    while (!nodeQu.empty())
    {
        int curr = nodeQu.front();
        nodeQu.pop();
        bfs.push_back(curr);

        for (auto i : List[curr])
		{
			if (!visited[i])
			{
				nodeQu.push(i);
				visited[i] = true;
			}
		}
    }
}

vector<int> Graph::BFS()
{
    int size = List.size();
    vector<bool> visited(size, false);
    vector<int> bfs{};

    for (int i = 1; i < size; ++i)
        if (!visited[i])
            BFSHelper(i, visited, bfs);

    return bfs;
}

void solve()
{
    // 1 Based Indexing
    int n = 7;
    Graph g(n);
    vector<int> U{1, 2, 2, 3, 5, 4};
    vector<int> V{2, 3, 7, 5, 7, 6};
    for (int i = 0; i < U.size(); ++i)
        g.addEdge(U[i], V[i]);

    // Displays Adjacency List
    cout << "List: \n";
    g.displayList();

    // Breadth First Search
    cout << "BFS: \n";
    vector<int> res = g.BFS();
    for (auto i : res)
        cout << i << " ";
    cout << "\n";
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
