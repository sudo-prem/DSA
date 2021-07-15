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
    void displayList();
    vector<int> shortestDistance(int start);
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

vector<int> Graph::shortestDistance(int start)
{
    int n = List.size();
    vector<int> distance(n, INT_MAX);
    queue<int> nodeQu;

    distance[start] = 0;
    nodeQu.push(start);

    while (!nodeQu.empty())
    {
        int curr = nodeQu.front();
        nodeQu.pop();

        for (int i : List[curr])
        {
            if (distance[curr] + 1 < distance[i])
            {
                distance[i] = distance[curr] + 1;
                nodeQu.push(i);
            }
        }
    }

    return distance;
}

void solve()
{
    // 1 Based Indexing
    int n = 5;
    Graph g(n);
    vector<int> U{2, 2, 2, 3, 4};
    vector<int> V{1, 3, 5, 4, 5};

    // int n = 4;
    // Graph g(n);
    // vector<int> U{2, 3};
    // vector<int> V{3, 4};

    // int n = 4;
    // Graph g(n);
    // vector<int> U{1, 2, 3, 1};
    // vector<int> V{2, 3, 4, 3};

    for (int i = 0; i < U.size(); ++i)
        g.addEdge(U[i], V[i]);

    // Displays Adjacency List
    cout << "List: \n";
    g.displayList();

    vector<int> distance = g.shortestDistance(1);
    cout << "Shortest Distance:\n";
    for (int i = 1; i < n; ++i)
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