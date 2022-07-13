// Helps finding Strongly Connected Components
// SCC is a component of a graph in which from
// any node we can travel to any other node

// It is a three step algorithm
// 1. Find Topological order
// 2. Inverse the graph (change direction of the edges)
// 3. DFS through the graph using the topological order

// TC: O(n)
// SC: O(n)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

class Graph
{
private:
    vector<vector<int>> List;

public:
    Graph(int n);
    void addEdge(int u, int v);
    void topoHelper(int start, vector<bool> &visited, stack<int> &nodeSt);
    void topoSort(stack<int> &nodeSt);
    void dfs(int start, vector<bool> &visited, vector<int> &currComponent);
    vector<vector<int>> kosaraju();
};

Graph::Graph(int n)
{
    List.resize(n + 1);
}

void Graph::addEdge(int u, int v)
{
    List[u].push_back(v);
}

void Graph::topoHelper(int start, vector<bool> &visited, stack<int> &nodeSt)
{
    visited[start] = true;

    for (auto i : List[start])
        if (!visited[i])
            topoHelper(i, visited, nodeSt);

    nodeSt.push(start);
}

void Graph::topoSort(stack<int> &nodeSt)
{
    int n = List.size();
    vector<bool> visited(n, false);

    for (int i = 1; i < n; ++i)
        if (!visited[i])
            topoHelper(i, visited, nodeSt);
}

void Graph::dfs(int start, vector<bool> &visited, vector<int> &currComponent)
{
    visited[start] = true;
    currComponent.push_back(start);

    for (int i : List[start])
        if (!visited[i])
            dfs(i, visited, currComponent);
}

vector<vector<int>> Graph::kosaraju()
{
    vector<vector<int>> SCC;

    // Get the topological order of graph
    int n = List.size();
    stack<int> nodeSt;
    topoSort(nodeSt);

    // Create Transpose of the Graph
    Graph transpose(n);
    for (int i = 1; i < n; ++i)
        for (int j : List[i])
            transpose.addEdge(j, i);

    // DFS the transpose graph
    vector<bool> visited(n, false);
    while (!nodeSt.empty())
    {
        int curr = nodeSt.top();
        nodeSt.pop();

        if (!visited[curr])
        {
            vector<int> currComponent;
            transpose.dfs(curr, visited, currComponent);
            SCC.push_back(currComponent);
        }
    }
    return SCC;
}

void solve()
{
    int n = 5;
    Graph g(n);
    vector<int> U{1, 2, 3, 2, 4};
    vector<int> V{2, 3, 1, 4, 5};

    for (int i = 0; i < U.size(); ++i)
        g.addEdge(U[i], V[i]);

    vector<vector<int>> SCC = g.kosaraju();
    for (int i = 0; i < SCC.size(); ++i)
    {
        cout << i + 1 << ": ";
        for (int j : SCC[i])
            cout << j << " ";
        cout << endl;
    }
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