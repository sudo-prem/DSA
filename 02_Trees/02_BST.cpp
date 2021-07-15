#include <bits/stdc++.h>
using namespace std;

class Node
{
private:
    int data;
    Node *left, *right;

public:
    Node(int dataue) : data(dataue), left(NULL), right(NULL) {}
    friend class BST;
};

class BST
{
private:
    Node *root;

public:
    BST();
    BST(vector<int> &);

    // Inorder Traversal for Sorted dataues
    void inOrder(Node *);
    void inOrder() { inOrder(root); }

    // Recursive Insert, Search and Delete
    Node *InsertR(Node *, int);
    void InsertR(int dataue) { root = InsertR(root, dataue); }
    Node *SearchR(Node *, int);
    Node *SearchR(int dataue) { return SearchR(root, dataue); }

    // Iterative Insert, Search, and Delete
    void InsertI(int dataue);
    Node *SearchI(int dataue);

    // Helper Functions for DeleteR
    int Height(Node *);
    Node *inPre(Node *);
    Node *inSuc(Node *);

    // Recursive Delete Function
    Node *DeleteR(Node *, int);
    void DeleteR(int dataue) { DeleteR(root, dataue); }

    // Generating BST with just Preorder
    Node *generateFromPre(vector<int> preorder);
};

BST::BST() { root = NULL; }

BST::BST(vector<int> &vec)
{
    root = NULL;
    for (auto i : vec)
        InsertI(i);
}

void BST::inOrder(Node *root)
{
    if (root)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

Node *BST::InsertR(Node *root, int dataue)
{
    if (!root)
        return new Node(dataue);
    if (dataue < root->data)
        root->left = InsertR(root->left, dataue);
    else if (dataue > root->data)
        root->right = InsertR(root->right, dataue);
    return root;
}

Node *BST::SearchR(Node *root, int dataue)
{
    if (!root or root->data == dataue)
        return root;
    if (root->data < dataue)
        return SearchR(root->left, dataue);
    else
        return SearchR(root->right, dataue);
}

int BST::Height(Node *root)
{
    if (root)
    {
        int x = Height(root->left);
        int y = Height(root->right);
        return x > y ? x + 1 : y + 1;
    }
    return 0;
}

Node *BST::inPre(Node *root)
{
    Node *q = root->left;
    while (q->right)
        q = q->right;
    return q;
}

Node *BST::inSuc(Node *root)
{
    Node *q = root->right;
    while (q->left)
        q = q->left;
    return q;
}

void BST::InsertI(int dataue)
{
    Node *temp = root, *prev;
    if (!root)
    {
        root = new Node(dataue);
        return;
    }
    while (temp)
    {
        if (temp->data == dataue)
            return;
        prev = temp;
        if (dataue < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    if (dataue < prev->data)
        prev->left = new Node(dataue);
    else
        prev->right = new Node(dataue);
}

Node *BST::SearchI(int dataue)
{
    Node *temp = root;
    while (temp)
    {
        if (temp->data == dataue)
            return temp;
        if (dataue < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return NULL;
}

Node *BST::DeleteR(Node *root, int dataue)
{
    Node *q;
    if (!root)
        return NULL;
    if (!root->left and !root->right)
    {
        if (root == this->root)
            this->root = NULL;
        return NULL;
    }
    if (root->data > dataue)
        root->left = DeleteR(root->left, dataue);
    else if (root->data < dataue)
        root->right = DeleteR(root->right, dataue);
    else
    {
        // In this method we are just copying the dataue to another node, it should be relinked for efficiency
        if (Height(root->left) > Height(root->right))
        {
            q = inPre(root->left);
            root->data = q->data;
            // since we shited q's data to root, now we can delete the node q
            root->left = DeleteR(root->left, q->data);
        }
        else
        {
            q = inSuc(root->right);
            root->data = q->data;
            // since we shited q's data to root, now we can delete the node q
            root->right = DeleteR(root->right, q->data);
        }
    }
    return root;
}

Node *BST::generateFromPre(vector<int> preorder)
{
    int currPos = 0;
    int size = preorder.size();

    stack<Node *> nodeSt;
    Node *root = new Node(preorder[currPos++]);
    nodeSt.push(root);
    Node *prev = root;

    while (currPos < size)
    {
        Node *curr = new Node(preorder[currPos++]);

        if (curr->data < prev->data)
        {
            prev->left = curr;
            prev = curr;
            nodeSt.push(curr);
        }
        else
        {
            while (!nodeSt.empty() and nodeSt.top()->data < curr->data)
            {
                prev = nodeSt.top();
                nodeSt.pop();
            }
            prev->right = curr;
            prev = curr;
            nodeSt.push(curr);
        }
    }

    this->root = root;
    return root;
}

int main()
{

    // Constructor and Insert Execution
    // vector<int> vec{9, 15, 5, 20, 16, 8, 12, 3, 6};
    // BST bst(vec);
    // bst.inOrder();
    // cout << endl;

    // Searching for a Node with it's data
    // if (bst.SearchI(9))
    //     cout << "Node Found!\n";
    // else
    //     cout << "Node not Found!\n";

    // bst.DeleteR(9);

    // bst.inOrder();
    // cout << endl;

    // if (bst.SearchI(9))
    //     cout << "Node Found!\n";
    // else
    //     cout << "Node not Found!\n";

    // BST bst;
    // vector<int> preorder{30, 20, 10, 15, 25, 40, 50, 45};
    // bst.generateFromPre(preorder);
    // bst.inOrder();
    // cout << endl;

    return 0;
}