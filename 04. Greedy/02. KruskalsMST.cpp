// Problem Link:
// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1#

// Priority Queue
// TC: O(n*log(n) + n*(4*alpha)) (4*alpha is the time taken by disjoint set to perform find, union)
// SC: O(n)

#include <bits/stdc++.h>
using namespace std;

class disjointSet
{
private:
    vector<int> parent;
    vector<int> weight;

public:
    disjointSet(int n)
    {
        for (int i = 0; i < n; ++i)
        {
            parent.push_back(i);
            weight.push_back(0);
        }
    }

    int collapsingFind(int node)
    {
        if (parent[node] == node)
            return node;
        parent[node] = collapsingFind(parent[node]);
        return parent[node];
    }

    void weightedUnion(int node1, int node2)
    {
        int parent1 = collapsingFind(node1);
        int parent2 = collapsingFind(node2);

        if (weight[parent1] > weight[parent2])
            parent[parent2] = parent1;
        else if (weight[parent2] > weight[parent2])
            parent[parent1] = parent2;
        else
        {
            parent[parent2] = parent1;
            weight[parent1]++;
        }
    }
};

class Graph
{
private:
    vector<vector<pair<int, int>>> List;

public:
    Graph(int n);
    void addEdge(int u, int v, int w);
    void Display();

    vector<pair<int, int>> kruskals();
    void displayMST(vector<pair<int, int>> &mstEdges);
};

Graph::Graph(int n)
{
    List.resize(n);
}

void Graph::addEdge(int u, int v, int w)
{
    List[u].push_back({v, w});
    List[v].push_back({u, w});
}

vector<pair<int, int>> Graph::kruskals()
{
    int n = List.size();
    vector<pair<int, int>> mstEdges{};
    disjointSet ds(n);

    // Pushing negative weights so that max-heap behaves as a minheap
    priority_queue<pair<int, pair<int, int>>> minHeap;

    // Inserting all the edges to the heap
    for (int i = 0; i < n; ++i)
        for (auto j : List[i])
            minHeap.push({-j.second, {i, j.first}});

    while (!minHeap.empty())
    {
        // Getting the current minimum
        auto curr = minHeap.top();
        minHeap.pop();

        int node1 = curr.second.first;
        int node2 = curr.second.second;

        // if both does not have the same parent, we can say that they wont form a cycle
        // hence can be considered for MST and weighted union should be performed
        if (ds.collapsingFind(node1) != ds.collapsingFind(node2))
        {
            mstEdges.push_back({node1, node2});
            ds.weightedUnion(node1, node2);
        }
    }

    return mstEdges;
}

void Graph::displayMST(vector<pair<int, int>> &mstEdges)
{
    for (auto i : mstEdges)
        for (auto j : List[i.first])
            if (j.first == i.second)
                cout << i.first << " to " << i.second << " - " << j.second << endl;
}

int main()
{
    int n = 5;
    vector<int> U{0, 0, 1, 1, 1, 2};
    vector<int> V{1, 3, 2, 4, 3, 4};
    vector<int> W{2, 6, 3, 5, 8, 7};

    Graph G(n);

    for (int i = 0; i < U.size(); ++i)
        G.addEdge(U[i], V[i], W[i]);

    vector<pair<int, int>> mstEdges = G.kruskals();
    G.displayMST(mstEdges);

    return 0;
}