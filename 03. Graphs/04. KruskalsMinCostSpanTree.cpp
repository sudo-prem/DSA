#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    // adjacency list representation
    vector<pair<pair<int, int>, int>> List;
    int V;

public:
    Graph(int n) : V(n) {}
    void addEdge(int u, int v, int w);
    void displayList();
    vector<pair<pair<int, int>, int>> Kruskals();
    int Cost(vector<pair<pair<int, int>, int>> table);
    int collapsingFind(int u, vector<int> &Set);
    void weightedUnion(int u, int v, vector<int> &Set);
};

void Graph::addEdge(int u, int v, int w)
{
    List.push_back({{u, v}, w});
}

void Graph::displayList()
{
    for (auto i : List)
        cout << "(" << i.first.first << ", " << i.first.second << ") = " << i.second << "\n";
    cout << '\n';
}

// returns the root node(parent node) of the given node
int Graph::collapsingFind(int u, vector<int> &Set)
{
    int x = u, v{};
    while (Set[x] > 0)
        x = Set[x];
    while (u != x)
    {
        v = Set[u];
        Set[u] = x;
        u = v;
    }
    return x;
}

// connects two subsets into one single subset,
// makes the larger subset's root as the new root
void Graph::weightedUnion(int u, int v, vector<int> &Set)
{
    if (Set[u] < Set[v])
    {
        Set[u] += Set[v];
        Set[v] = u;
    }
    else
    {
        Set[v] += Set[u];
        Set[u] = v;
    }
}

vector<pair<pair<int, int>, int>> Graph::Kruskals()
{
    // n stores the number of edges in the list
    int n = List.size(), k{};
    vector<pair<pair<int, int>, int>> res;
    pair<pair<int, int>, int> minIndex;
    // Disjoint set for detecting cycle
    vector<int> Set(V, -1), visited(n, 0);
    int i = 0;
    while (i < V - 2)
    {
        // finding the minimum weight
        int minValue = INT_MAX;
        for (int j = 0; j < n; ++j)
        {
            if (!visited[j])
                if (List[j].second < minValue)
                {
                    minIndex = List[j];
                    minValue = List[j].second;
                    k = j;
                }
        }
        // visit the node
        visited[k] = 1;
        // check if they form a cycle
        int u = minIndex.first.first, v = minIndex.first.second;
        // condition for forming cycle
        int Parent1 = collapsingFind(u, Set), Parent2 = collapsingFind(v, Set);
        if (Parent1 != Parent2)
        {
            res.push_back(minIndex);
            // note that we apply union on the parent nodes only
            weightedUnion(Parent1, Parent2, Set);
            i++;
        }
    }
    return res;
}

int Graph::Cost(vector<pair<pair<int, int>, int>> table)
{
    int res{};
    for (auto i : table)
        res += i.second;
    return res;
}

int main()
{
    // 1 based indexing
    int n = 7 + 1;
    Graph g(n);

    // Adding edges to graph
    vector<int> U{1, 1, 2, 2, 3, 4, 4, 5, 5};
    vector<int> V{6, 2, 3, 7, 4, 7, 5, 7, 6};
    vector<int> W{5, 25, 12, 10, 8, 14, 16, 18, 20};
    for (int i = 0; i < U.size(); ++i)
        g.addEdge(U[i], V[i], W[i]);

    // // Displaying List
    // cout << "List: \n";
    // g.displayList();

    // calculating minimum cost spanning tree
    vector<pair<pair<int, int>, int>> res = g.Kruskals();
    for (auto i : res)
        cout << "(" << i.first.first << ", " << i.first.second << ") = " << i.second << "\n";
    cout << '\n';
    int total = g.Cost(res);
    cout << "Total Minimum Cost: " << total << endl;

    return 0;
}