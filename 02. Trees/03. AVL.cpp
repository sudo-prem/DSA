#include <bits/stdc++.h>
using namespace std;

class Node
{
private:
    int data, height;
    Node *left, *right;

public:
    Node(int data, int height) : data(data), left(NULL), right(NULL), height(height) {}
    friend class AVL;
};

class AVL
{
private:
    Node *root;

public:
    // Constructor
    AVL() { root = NULL; }
    // Helper functions for Insertion
    int nodeHeight(Node *);
    int balanceFactor(Node *);
    // Helper function for Deletion
    Node *inOrderPre(Node *);
    Node *inOrderSuc(Node *);

    // Rotations for balancing
    Node *LLRotation(Node *);
    Node *LRRotation(Node *);
    Node *RRRotation(Node *);
    Node *RLRotation(Node *);
    // Insertion and Deletion
    Node *Insert(Node *, int);
    void Insert(int data) { Insert(root, data); }
    Node *Delete(Node *, int);
    void Delete(int data) { Delete(root, data); }
    // Tree Traversals
    void inOrder(Node *);
    void inOrder() { inOrder(root); }
    void preOrder(Node *);
    void preOrder() { preOrder(root); }
};

int AVL::nodeHeight(Node *root)
{
    int leftHeight, rightHeight;
    // check if root and root->direction exist and take its value
    leftHeight = ((root and root->left) ? root->left->height + 1 : 1);
    rightHeight = ((root and root->right) ? root->right->height + 1 : 1);
    // return the max of the two values
    return ((leftHeight > rightHeight) ? leftHeight : rightHeight);
}

int AVL::balanceFactor(Node *root)
{
    int leftHeight, rightHeight;
    // incremented the values by 1 just to keep the consistency
    leftHeight = ((root and root->left) ? root->left->height + 1 : 1);
    rightHeight = ((root and root->right) ? root->right->height + 1 : 1);
    // returns negative BF if leftH is more than rightHeight
    return leftHeight - rightHeight;
}

Node *AVL::LLRotation(Node *root)
{
    Node *rootL = root->left;
    Node *rootLR = rootL->right;

    rootL->right = root;
    root->left = rootLR;

    root->height = nodeHeight(root);
    rootL->height = nodeHeight(rootL);

    if (this->root == root)
        this->root = rootL;
    return rootL;
}

Node *AVL::LRRotation(Node *root)
{
    Node *rootL = root->left;
    Node *rootLR = rootL->right;
    Node *rootLRL = rootLR->left;
    Node *rootLRR = rootLR->right;

    rootLR->right = root;
    rootLR->left = rootL;
    rootL->right = rootLRL;
    root->left = rootLRR;

    root->height = nodeHeight(root);
    rootL->height = nodeHeight(rootL);
    rootLR->height = nodeHeight(rootLR);

    if (root == this->root)
        this->root = rootLR;
    return rootLR;
}

Node *AVL::RRRotation(Node *root)
{
    Node *rootR = root->right;
    Node *rootRL = rootR->left;

    root->right = rootRL;
    rootR->left = root;

    root->height = nodeHeight(root);
    rootR->height = nodeHeight(rootR);

    if (root == this->root)
        this->root = rootR;
    return rootR;
}

Node *AVL::RLRotation(Node *root)
{
    Node *rootR = root->right;
    Node *rootRL = rootR->left;
    Node *rootRLL = rootRL->left;
    Node *rootRLR = rootRL->right;

    root->right = rootRLL;
    rootR->left = rootRLR;
    rootRL->right = rootR;
    rootRL->left = root;

    // recalibration the height of nodes
    root->height = nodeHeight(root);
    rootR->height = nodeHeight(rootR);
    rootRL->height = nodeHeight(rootRL);

    if (root == this->root)
        this->root = rootRL;
    return rootRL;
}

Node *AVL::inOrderPre(Node *root)
{
    root = root->left;
    while (root and root->right)
        root = root->right;
    return root;
}

Node *AVL::inOrderSuc(Node *root)
{
    root = root->right;
    while (root and root->left)
        root = root->left;
    return root;
}

void AVL::inOrder(Node *root)
{
    if (root)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void AVL::preOrder(Node *root)
{
    if (root)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

Node *AVL::Insert(Node *root, int data)
{
    // if it has reached the bottom
    if (!root)
    {
        root = root = new Node(data, 1);
        if (!this->root)
            this->root = root;
        return root;
    }
    else if (data < root->data)
        root->left = Insert(root->left, data);
    else if (data > root->data)
        root->right = Insert(root->right, data);
    // updating the height in the returning phase of the recursion
    root->height = nodeHeight(root);
    // based on the balance-factor rotating the tree
    if (balanceFactor(root) == 2 and balanceFactor(root->left) == 1)
        root = LLRotation(root);
    else if (balanceFactor(root) == 2 and balanceFactor(root->left) == -1)
        root = LRRotation(root);
    else if (balanceFactor(root) == -2 and balanceFactor(root->right) == -1)
        root = RRRotation(root);
    else if (balanceFactor(root) == -2 and balanceFactor(root->right) == 1)
        root = RLRotation(root);
    return root;
}

Node *AVL::Delete(Node *root, int data)
{
    if (!root)
        return NULL;
    if (!root->left and !root->right)
    {
        if (root == this->root)
            this->root = NULL;
        delete root;
        return NULL;
    }
    if (data < root->data)
        root->left = Delete(root->left, data);
    else if (data > root->data)
        root->right = Delete(root->right, data);
    else
    {
        if (nodeHeight(root->left) > nodeHeight(root->right))
        {
            Node *temp = inOrderPre(root);
            root->data = temp->data;
            root->left = Delete(root->left, temp->data);
        }
        else
        {
            Node *temp = inOrderSuc(root);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    root->height = nodeHeight(root);
    // here we are doing rotation like how we did for insertion,
    // because here we need to include one more condition
    // when BF is 2 and the child nodes have 0 as their BF
    if (balanceFactor(root) == 2)
    {
        if (balanceFactor(root->left) == 1)
            return LLRotation(root);
        else
            return LRRotation(root);
    }
    else if (balanceFactor(root) == -2)
    {
        if (balanceFactor(root->right) == -1)
            return RRRotation(root);
        else
            return RLRotation(root);
    }
    return root;
}

void solve()
{
    AVL avl;
    vector<int> vec{10, 20, 30, 25, 28, 27, 5};
    for (auto i : vec)
        avl.Insert(i);

    avl.inOrder();
    cout << endl;

    avl.Delete(28);

    avl.inOrder();
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