#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1: (Simple BFS)
// TC: O(n*n)
// SC: O(n)

// Approach 2: (Topo Sort + BFS)
// TC: O(n)
// SC: O(n)

class Graph
{
private:
    // pair<index, weight>
    vector<vector<pair<int, int>>> List;

public:
    Graph(int n);
    void addEdge(int u, int v, int w);
    void displayList();
    // Approach 1
    vector<int> shortestDistance1(int start);
    // Approach 2
    stack<int> topoSort();
    void topoHelper(int start, vector<bool> &visited, stack<int> &nodeSt);
    vector<int> shortestDistance2(int start);
};

Graph::Graph(int n)
{
    List.resize(n);
}

void Graph::addEdge(int u, int v, int w)
{
    List[u].push_back({v, w});
}

void Graph::displayList()
{
    int size = List.size();
    int count{};
    for (auto i : List)
    {
        cout << count++ << ": ";
        for (auto j : i)
            cout << j.first << " - " << j.second << " ";
        cout << "\n";
    }
    cout << "\n";
}

// Approach 1
vector<int> Graph::shortestDistance1(int start)
{
    int n = List.size();
    vector<int> distance(n, INT_MAX);
    queue<pair<int, int>> nodeQu;

    distance[start] = 0;
    nodeQu.push({start, 0});

    while (!nodeQu.empty())
    {
        int currNode = nodeQu.front().first;
        nodeQu.pop();

        for (auto i : List[currNode])
        {
            if (distance[currNode] + i.second < distance[i.first])
            {
                distance[i.first] = distance[currNode] + i.second;
                nodeQu.push(i);
            }
        }
    }

    return distance;
}

// Approach 2
void Graph::topoHelper(int start, vector<bool> &visited, stack<int> &nodeSt)
{
    visited[start] = true;

    for (auto i : List[start])
        if (!visited[i.first])
            topoHelper(i.first, visited, nodeSt);

    nodeSt.push(start);
}

stack<int> Graph::topoSort()
{
    int n = List.size();
    vector<bool> visited(n, false);
    stack<int> nodeSt;

    for (int i = 0; i < n; ++i)
        if (!visited[i])
            topoHelper(i, visited, nodeSt);

    return nodeSt;
}

vector<int> Graph::shortestDistance2(int start)
{
    int n = List.size();
    stack<int> sortedNodes = topoSort();
    vector<int> distance(n, INT_MAX);
    distance[start] = 0;

    while (!sortedNodes.empty())
    {
        int curr = sortedNodes.top();
        sortedNodes.pop();

        // To make sure we start with the 'start' node
        if (distance[curr] != INT_MAX)
            for (auto i : List[curr])
                if (distance[curr] + i.second < distance[i.first])
                    distance[i.first] = distance[curr] + i.second;
    }

    return distance;
}

void solve()
{
    // 0 Based Indexing
    int n = 6;
    Graph g(n);
    vector<int> U{0, 0, 1, 2, 4, 4, 5};
    vector<int> V{1, 4, 2, 3, 2, 5, 3};
    vector<int> W{2, 1, 3, 6, 2, 4, 1};

    for (int i = 0; i < U.size(); ++i)
        g.addEdge(U[i], V[i], W[i]);

    // Displays Adjacency List
    cout << "List: \n";
    g.displayList();

    vector<int> distance;
    distance = g.shortestDistance1(0);
    cout << "Shortest Distance 1:\n";
    for (int i = 0; i < n; ++i)
        cout << i << ": " << distance[i] << endl;

    distance = g.shortestDistance2(0);
    cout << "Shortest Distance 2:\n";
    for (int i = 0; i < n; ++i)
        cout << i << ": " << distance[i] << endl;
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