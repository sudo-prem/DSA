#include <bits/stdc++.h>
using namespace std;

class Node
{
private:
    int data;
    Node *left, *right;

public:
    Node(int value) : data(value), left(NULL), right(NULL) {}
    friend class BST;
};

class BST
{
private:
    Node *root;

public:
    BST();
    BST(vector<int> &);

    // Inorder Traversal for Sorted values
    void inOrder(Node *);
    void inOrder() { inOrder(root); }

    // Recursive Insert, Search and Delete
    Node *InsertR(Node *, int);
    void InsertR(int value) { root = InsertR(root, value); }
    Node *SearchR(Node *, int);
    Node *SearchR(int value) { return SearchR(root, value); }

    // Iterative Insert, Search, and Delete
    void InsertI(int value);
    Node *SearchI(int value);

    // Helper Functions for DeleteR
    int Height(Node *);
    Node *inPre(Node *);
    Node *inSuc(Node *);

    // Recursive Delete Function
    Node *DeleteR(Node *, int);
    void DeleteR(int value) { DeleteR(root, value); }

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

Node *BST::InsertR(Node *root, int value)
{
    if (!root)
        return new Node(value);
    if (value < root->data)
        root->left = InsertR(root->left, value);
    else if (value > root->data)
        root->right = InsertR(root->right, value);
    return root;
}

Node *BST::SearchR(Node *root, int value)
{
    if (!root or root->data == value)
        return root;
    if (root->data < value)
        return SearchR(root->left, value);
    else
        return SearchR(root->right, value);
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

void BST::InsertI(int value)
{
    Node *temp = root, *prev;
    if (!root)
    {
        root = new Node(value);
        return;
    }
    while (temp)
    {
        if (temp->data == value)
            return;
        prev = temp;
        if (value < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    if (value < prev->data)
        prev->left = new Node(value);
    else
        prev->right = new Node(value);
}

Node *BST::SearchI(int value)
{
    Node *temp = root;
    while (temp)
    {
        if (temp->data == value)
            return temp;
        if (value < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return NULL;
}

Node *BST::DeleteR(Node *root, int value)
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
    if (root->data > value)
        root->left = DeleteR(root->left, value);
    else if (root->data < value)
        root->right = DeleteR(root->right, value);
    else
    {
        // In this method we are just copying the value to another node, it should be relinked for efficiency
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
    int i{}, s = preorder.size();
    stack<Node *> st;
    root = new Node(preorder[i++]);
    Node *curr = root;
    while (i < s)
    {
        if (preorder[i] < curr->data)
        {
            st.push(curr);
            Node *temp = new Node(preorder[i++]);
            curr->left = temp;
            curr = temp;
        }
        else
        {
            Node *prev;
            if (st.empty())
                prev = new Node(INT_MAX);
            else
                prev = st.top();

            if (preorder[i] < prev->data)
            {
                Node *temp = new Node(preorder[i++]);
                curr->right = temp;
                curr = temp;
            }
            else
            {
                curr = prev;
                st.pop();
            }
        }
    }
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
    return 0;
}