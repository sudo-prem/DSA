// Problem Link:
// https://leetcode.com/problems/clone-graph/

// Approach 1: (Recursive) DFS
// TC: O(n)
// SC: O(n)

// Approach 2: (Iterative) BFS
// TC: O(n)
// SC: O(n)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

// Approach 1
Node *cloneHelper(Node *node, unordered_map<Node *, Node *> &hash)
{
    if (hash.find(node) == hash.end())
    {
        hash[node] = new Node(node->val);
        for (Node *i : node->neighbors)
            hash[node]->neighbors.push_back(cloneHelper(i, hash));
    }

    return hash[node];
}

Node *cloneGraph1(Node *node)
{
    if (!node)
        return NULL;

    unordered_map<Node *, Node *> hash{};
    return cloneHelper(node, hash);
}

// Approach 2
Node *cloneGraph2(Node *node)
{
    if (!node)
        return NULL;

    unordered_map<Node *, Node *> hash{};
    queue<Node *> nodeQu;

    // Add the first node to the hash and queue
    hash[node] = new Node(node->val);
    nodeQu.push(node);

    while (!nodeQu.empty())
    {
        Node *curr = nodeQu.front();
        nodeQu.pop();

        // Explore all its neighbors
        for (Node *neighbor : curr->neighbors)
        {
            // If Cloned Graph contains neighbor then dont create again
            if (hash.find(neighbor) == hash.end())
            {
                hash[neighbor] = new Node(neighbor->val);
                nodeQu.push(neighbor);
            }
            hash[curr]->neighbors.push_back(hash[neighbor]);
        }
    }

    return hash[node];
}

void visitGraph(Node *root, unordered_set<Node *> hash)
{
    if (!root or hash.find(root) != hash.end())
        return;
    cout << root->val << " ";
    hash.insert(root);
    for (Node *neighbor : root->neighbors)
        visitGraph(neighbor, hash);
}

void solve()
{
    Node *one = new Node(1);
    Node *two = new Node(2);
    Node *three = new Node(3);
    Node *four = new Node(4);
    one->neighbors.push_back(two);
    one->neighbors.push_back(four);
    two->neighbors.push_back(one);
    two->neighbors.push_back(three);
    three->neighbors.push_back(two);
    three->neighbors.push_back(four);
    unordered_set<Node *> hash{};
    visitGraph(one, hash);
    cout << endl;

    Node *res;
    res = cloneGraph1(one);
    visitGraph(res, hash);
    cout << endl;

    res = cloneGraph2(one);
    visitGraph(res, hash);
    cout << endl;
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