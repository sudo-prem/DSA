// Approach 1: (Queue)
// TC: O(n*n)
// SC: O(n)

// Approach 2: (Priority Queue)
// TC: O(n*log(n))
// SC: O(n)

#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    vector<vector<pair<int, int>>> List;

public:
    Graph(int n);
    void addEdge(int u, int v, int w);
    void Display();
    void displayDist(vector<int> res, int source);
    vector<int> Dijkstra1(int source);
    vector<int> Dijkstra2(int source);
};

Graph::Graph(int n)
{
    List.resize(n);
}

// Dijkstra works on both directed and undirected, non-negative cyclic graphs
void Graph::addEdge(int u, int v, int w)
{
    List[u].push_back({v, w});
    List[v].push_back({u, w});
}

void Graph::displayDist(vector<int> res, int source)
{
    for (int i = 0; i < res.size(); ++i)
        cout << "SP from " << source << " to " << i << " is " << res[i] << endl;
}

// Approach 1
vector<int> Graph::Dijkstra1(int source)
{
    int n = List.size();
    vector<int> distance(n, INT_MAX);
    queue<int> nodeQu;

    distance[source] = 0;
    nodeQu.push(source);

    while (!nodeQu.empty())
    {
        int curr = nodeQu.front();
        nodeQu.pop();

        for (auto i : List[curr])
        {
            if (distance[curr] + i.second < distance[i.first])
            {
                distance[i.first] = distance[curr] + i.second;
                nodeQu.push(i.first);
            }
        }
    }

    return distance;
}

// Approach 2
vector<int> Graph::Dijkstra2(int source)
{
    int n = List.size();
    vector<int> distance(n, INT_MAX);
    // Min-Heap
    // pair<distance, node>
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> nodePq;

    nodePq.push({0, source});
    distance[source] = 0;

    while (!nodePq.empty())
    {
        int curr = nodePq.top().second;
        nodePq.pop();

        for (auto i : List[curr])
        {
            if (distance[curr] + i.second < distance[i.first])
            {
                distance[i.first] = distance[curr] + i.second;
                nodePq.push({distance[i.first], i.first});
            }
        }
    }

    return distance;
}

int main()
{
    int n = 9;
    vector<int> U{1, 2, 3, 4, 5, 5, 5, 6, 7, 7, 7, 8, 8, 8};
    vector<int> V{0, 1, 2, 3, 2, 3, 4, 5, 0, 1, 6, 2, 6, 7};
    vector<int> W{4, 8, 7, 9, 4, 14, 10, 2, 8, 11, 1, 2, 6, 7};

    Graph G(n);

    for (int i = 0; i < U.size(); ++i)
        G.addEdge(U[i], V[i], W[i]);

    int source = 0;
    vector<int> res;

    cout << "Algorithm 1:" << endl;
    res = G.Dijkstra1(source);
    G.displayDist(res, source);

    cout << "\nAlgorithm 2:" << endl;
    res = G.Dijkstra2(source);
    G.displayDist(res, source);

    return 0;
}