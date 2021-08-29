// Problem Link:
// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1#

// Approach 1: (Brute Force)
// TC: O(n^2)
// SC: O(n)

// Approach 2: (Priority Queue as MinHeap)
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
    vector<int> prims1();
    vector<int> prims2();
    void displayMST(vector<int> &parent);
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

vector<int> Graph::prims1()
{
    int n = List.size();
    // Visited helps in checking cycle formation
    // Parent keeps track of parent node, in its corresponding index nodes
    // keys store the minimum edge weight needed to add the corresponding index node

    vector<bool> visited(n, false);
    vector<int> parent(n);
    vector<int> key(n, INT_MAX);

    parent[0] = -1;
    key[0] = 0;

    for (int i = 0; i < n; ++i)
    {
        // Find a node that has the minimum edge weight and has not been visited
        int minNode, minValue{INT_MAX};
        for (int j = 0; j < n; ++j)
            // Relaxation
            if (visited[j] == false and key[j] < minValue)
            {
                minValue = key[j];
                minNode = j;
            }

        // Mark it as visited
        visited[minNode] = true;

        // Find the minimum edges that spans from minNode
        // and update its weight if its lesser than the old weight
        for (auto edges : List[minNode])
        {
            int currNode = edges.first;
            int currWeight = edges.second;
            if (visited[currNode] == false and currWeight < key[currNode])
            {
                parent[currNode] = minNode;
                key[currNode] = currWeight;
            }
        }
    }

    return parent;
}

vector<int> Graph::prims2()
{
    int n = List.size();
    // Visited helps in checking cycle formation
    // Parent keeps track of parent node, in its corresponding index nodes
    // minHeap stores pair<Weight, Node>

    vector<bool> visited(n, false);
    vector<int> parent(n);
    vector<int> key(n, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    parent[0] = -1;
    key[0] = 0;
    minHeap.push({0, 0});

    while (!minHeap.empty())
    {
        // Find a node that has the minimum edge weight and has not been visited
        int minNode = minHeap.top().second;
        minHeap.pop();

        // Mark it as visited
        visited[minNode] = true;

        // Find the minimum edges that spans from minNode
        // and update its weight if its lesser than the old weight
        for (auto edges : List[minNode])
        {
            int currNode = edges.first;
            int currWeight = edges.second;
            if (visited[currNode] == false and currWeight < key[currNode])
            {
                parent[currNode] = minNode;
                key[currNode] = currWeight;
                minHeap.push({currWeight, currNode});
            }
        }
    }

    return parent;
}

void Graph::displayMST(vector<int> &parent)
{
    int n = List.size();
    cout << "MST: " << endl;
    for (int i = 1; i < n; ++i)
        for (auto j : List[i])
            if (j.first == parent[i])
                cout << i << " to " << j.first << " - " << j.second << endl;
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

    // Returns selected edges
    // in the form of index as a node and its value as another node of a edge
    vector<int> resParent;

    resParent = G.prims1();
    G.displayMST(resParent);

    cout << endl;

    resParent = G.prims2();
    G.displayMST(resParent);

    return 0;
}