#include <bits/stdc++.h>
using namespace std;

// Approach 1: (Queue)
// TC: O(n*n)
// SC: O(n)

// Approach 2: (Priority Queue)
// TC: O(n*log(n))
// SC: O(n)

class Graph
{
private:
    vector<vector<int>> Matrix;

public:
    Graph(int n);
    void addEdge(int u, int v, int w);
    void Display();
    void displayDist(vector<int> res, int source);
    int minDist(vector<int> vec, vector<bool> visited);
    vector<int> Dijkstra1(int source);
    vector<int> Dijkstra2(int source);
};

Graph::Graph(int n)
{
    Matrix.resize(n, vector<int>(n, 0));
}

// Assuming that the graph is undirected
// Dijkstra works on both directed and undirected
void Graph::addEdge(int u, int v, int w)
{
    Matrix[u][v] = Matrix[v][u] = w;
}

void Graph::Display()
{
    for (auto i : Matrix)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}

void Graph::displayDist(vector<int> res, int source)
{
    for (int i = 0; i < res.size(); ++i)
        cout << "SP from " << source << " to " << i << " is " << res[i] << endl;
}

int Graph::minDist(vector<int> vec, vector<bool> visited)
{
    int minVal{INT_MAX}, minIndex{};
    for (int i = 0; i < vec.size(); ++i)
        if (!visited[i] and vec[i] < minVal)
        {
            minVal = vec[i];
            minIndex = i;
        }
    return minIndex;
}

// Approach 1
vector<int> Graph::Dijkstra1(int source)
{
    int n = Matrix.size();
    vector<int> distance(n, INT_MAX);
    queue<int> nodeQu;

    distance[source] = 0;
    nodeQu.push(source);

    while (!nodeQu.empty())
    {
        int curr = nodeQu.front();
        nodeQu.pop();

        for (int i = 0; i < n; ++i)
            if (Matrix[curr][i] != 0)
                if (distance[curr] + Matrix[curr][i] < distance[i])
                {
                    distance[i] = distance[curr] + Matrix[curr][i];
                    nodeQu.push(i);
                }
    }

    return distance;
}

// Approach 2
vector<int> Graph::Dijkstra2(int source)
{
    int n = Matrix.size();
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

        for (int i = 0; i < n; ++i)
        {
            if (Matrix[curr][i])
            {
                if (distance[curr] + Matrix[curr][i] < distance[i])
                {
                    distance[i] = distance[curr] + Matrix[curr][i];
                    nodePq.push({distance[i], i});
                }
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