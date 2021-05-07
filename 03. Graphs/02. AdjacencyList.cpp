#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    // Since STL list doesn't have subscript operator[],
    // we can use vector of lists
    vector<list<int>> List;

public:
    Graph(int n);
    void addEdge(int u, int v);
    void displayList();
    vector<int> BFS(int start);
    vector<int> DFS(int start);
    void RDFS(int start, vector<int> &dfs);
};

Graph::Graph(int n)
{
    List.resize(n);
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

vector<int> Graph::BFS(int start)
{
    int size = List.size();
    vector<int> bfs{};
    vector<bool> visited(size, false);
    queue<int> qu;
    qu.push(start);
    visited[start] = true;
    while (!qu.empty())
    {
        int curr = qu.front();
        qu.pop();
        bfs.push_back(curr);
        for (auto i : List[curr])
            if (!visited[i])
            {
                qu.push(i);
                visited[i] = true;
            }
    }
    return bfs;
}

vector<int> Graph::DFS(int start)
{
    int size = List.size();
    vector<int> dfs;
    vector<bool> visited(size, false);
    stack<int> st;
    st.push(start);
    visited[start] = true;
    while (!st.empty())
    {
        int curr = st.top();
        st.pop();
        dfs.push_back(curr);
        for (auto i : List[curr])
        {
            if (!visited[i])
            {
                st.push(i);
                visited[i] = true;
            }
        }
    }
    return dfs;
}

void Graph::RDFS(int start, vector<int> &dfs)
{
    static int n = List.size();
    static vector<int> visited(n, false);
    if (!visited[start])
    {
        dfs.push_back(start);
        visited[start] = true;
        for (auto i : List[start])
        {
            if (!visited[i])
                RDFS(i, dfs);
        }
    }
}

int main()
{
    // Graph designed for Index start from 1
    int n = 7 + 1;
    Graph g(n);
    vector<int> vec1{1, 2, 2, 3, 5, 4};
    vector<int> vec2{2, 3, 7, 5, 7, 6};
    for (int i = 0; i < vec1.size(); ++i)
        g.addEdge(vec1[i], vec2[i]);

    // Displays Adjacency Matrix
    cout << "List: \n";
    g.displayList();

    // Breadth First Search (Iterative)
    cout << "BFS: \n";
    vector<int> res = g.BFS(1);
    for (auto i : res)
        cout << i << " ";
    cout << "\n";
    res = g.BFS(4);
    for (auto i : res)
        cout << i << " ";
    cout << "\n\n";

    // Depth First Search (Iterative)
    cout << "DFS: \n";
    res = g.DFS(1);
    for (auto i : res)
        cout << i << " ";
    cout << "\n";
    res = g.DFS(4);
    for (auto i : res)
        cout << i << " ";
    cout << "\n\n";

    // Depth First Search (Recursive)
    cout << "RDFS: \n";
    res = {};
    g.RDFS(1, res);
    for (auto i : res)
        cout << i << " ";
    cout << "\n";
    res = {};
    g.RDFS(4, res);
    for (auto i : res)
        cout << i << " ";
    cout << "\n\n";

    return 0;
}