// Problem Link:
// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

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
    void DFSHelper(int start, vector<bool> &visited, vector<int> &dfs);
    vector<int> DFS();
    void RDFSHelper(int start, vector<bool> &visited, vector<int> &dfs);
    vector<int> RDFS();
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

void Graph::DFSHelper(int start, vector<bool> &visited, vector<int> &dfs)
{
    stack<int> nodeSt;
    nodeSt.push(start);
    visited[start] = true;

    while (!nodeSt.empty())
    {
        int curr = nodeSt.top();
        nodeSt.pop();
        dfs.push_back(curr);

        for (int i : List[curr])
        {
            if (!visited[i])
            {
                visited[i] = true;
                nodeSt.push(i);
            }
        }
    }
}

vector<int> Graph::DFS()
{
    int n = List.size();
    vector<bool> visited(n, false);
    vector<int> dfs;

    for (int i = 1; i < n; ++i)
        if (!visited[i])
            DFSHelper(i, visited, dfs);

    return dfs;
}

void Graph::RDFSHelper(int start, vector<bool> &visited, vector<int> &dfs)
{
    visited[start] = true;
    dfs.push_back(start);

    for (int i : List[start])
        if (!visited[i])
            RDFSHelper(i, visited, dfs);
}

vector<int> Graph::RDFS()
{
    int n = List.size();
    vector<bool> visited(n, false);
    vector<int> dfs;

    for (int i = 1; i < n; ++i)
        if (!visited[i])
            RDFSHelper(i, visited, dfs);

    return dfs;
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

    // Displays Adjacency Matrix
    cout << "List: \n";
    g.displayList();

    vector<int> res;

    // Depth First Search (Iterative)
    cout << "DFS: \n";
    res = g.DFS();
    for (auto i : res)
        cout << i << " ";
    cout << "\n";

    // Depth First Search (Recursive)
    cout << "RDFS: \n";
    res = g.RDFS();
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