#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node() {}
    Node(int _data) : data(_data), left(NULL), right(NULL) {}
};

class BinaryTree
{
private:
    Node *root;

public:
    // BT creation, create() makes use of a queue and takes user input for tree generation
    BinaryTree();
    void create();
    // Recursive Traversals
    void preOrderR(Node *);
    void preOrderR() { preOrderR(root); }
    void inOrderR(Node *);
    void inOrderR() { inOrderR(root); }
    void postOrderR(Node *);
    void postOrderR() { postOrderR(root); }
    // Iterative Traversal
    void preOrderI();
    void inOrderI();
    void postOrderI();
    void levelOrder();
    // Generates a tree from given pre-in/pos-in arrays
    Node *generateFromPre(vector<int> &, vector<int> &, unordered_map<int, int> &, int &, int, int);
    Node *generateFromPre(vector<int> &, vector<int> &);
    Node *generateFromPost(vector<int> &, vector<int> &, unordered_map<int, int> &, int &, int, int);
    Node *generateFromPost(vector<int> &, vector<int> &);
    // notice that all the Sum, Count, Height functions use post order form (left, right, root)
    int Sum(Node *);
    int Sum() { return Sum(root); }
    int Count(Node *);
    int Count() { return Count(root); }
    int Height(Node *);
    int Height() { return Height(root); }
    int Leaf(Node *);
    int Leaf() { return Leaf(root); }
    int NonLeaf(Node *);
    int NonLeaf() { return NonLeaf(root); }
    int Degree1Nodes(Node *);
    int Degree1Nodes() { return Degree1Nodes(root); }
    int Degree2Nodes(Node *);
    int Degree2Nodes() { return Degree2Nodes(root); }
};

BinaryTree::BinaryTree()
{
    root = new Node;
    root->left = root->right = NULL;
}

void BinaryTree::create()
{
    cout << "Enter Value for Root: ";
    cin >> root->data;
    root->left = root->right = NULL;
    queue<Node *> Address;
    Address.push(root);
    while (!Address.empty())
    {
        Node *temp = Address.front();
        Address.pop();
        int newdata;
        cout << "Enter Left Node Data for " << temp->data << ": ";
        cin >> newdata;
        if (newdata != -1)
        {
            Node *node = new Node;
            node->data = newdata;
            node->left = node->right = NULL;
            temp->left = node;
            Address.push(node);
        }
        cout << "Enter Right Node Data for " << temp->data << ": ";
        cin >> newdata;
        if (newdata != -1)
        {
            Node *node = new Node;
            node->data = newdata;
            node->left = node->right = NULL;
            temp->right = node;
            Address.push(node);
        }
    }
}

void BinaryTree::preOrderR(Node *t)
{
    if (t)
    {
        cout << t->data << " ";
        preOrderR(t->left);
        preOrderR(t->right);
    }
}

void BinaryTree::inOrderR(Node *t)
{
    if (t)
    {
        inOrderR(t->left);
        cout << t->data << " ";
        inOrderR(t->right);
    }
}

void BinaryTree::postOrderR(Node *t)
{
    if (t)
    {
        postOrderR(t->left);
        postOrderR(t->right);
        cout << t->data << " ";
    }
}

void BinaryTree::preOrderI()
{
    Node *t = root;
    stack<Node *> st;
    while (t or !st.empty())
    {
        if (t)
        {
            st.push(t);
            cout << t->data << " ";
            t = t->left;
        }
        else
        {
            t = st.top();
            st.pop();
            t = t->right;
        }
    }
}

void BinaryTree::inOrderI()
{
    Node *t = root;
    stack<Node *> st;
    while (t or !st.empty())
    {
        if (t)
        {
            st.push(t);
            t = t->left;
        }
        else
        {
            t = st.top();
            st.pop();
            cout << t->data << " ";
            t = t->right;
        }
    }
}

void BinaryTree::postOrderI()
{
    Node *t = root;
    stack<Node *> st1, st2;
    st1.push(t);
    while (!st1.empty())
    {
        Node *temp = st1.top();
        st2.push(temp);
        st1.pop();
        if (temp->left)
            st1.push(temp->left);
        if (temp->right)
            st1.push(temp->right);
    }
    while (!st2.empty())
    {
        cout << st2.top()->data << " ";
        st2.pop();
    }
}

void BinaryTree::levelOrder()
{
    queue<Node *> Q1, Q2;
    Node *t = root;
    Q1.push(t);
    Q2.push(t);
    while (!Q1.empty())
    {
        Node *temp = Q1.front();
        Q1.pop();
        if (temp->left)
        {
            Q1.push(temp->left);
            Q2.push(temp->left);
        }
        if (temp->right)
        {
            Q1.push(temp->right);
            Q2.push(temp->right);
        }
    }
    while (!Q2.empty())
    {
        cout << Q2.front()->data << " ";
        Q2.pop();
    }
}

Node *BinaryTree::generateFromPre(vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> &hash, int &currPos, int start, int end)
{
    if (start > end)
        return NULL;

    int pivot = hash[preorder[currPos]];
    currPos++;

    Node *root = new Node(inorder[pivot]);
    root->left = generateFromPre(preorder, inorder, hash, currPos, start, pivot - 1);
    root->right = generateFromPre(preorder, inorder, hash, currPos, pivot + 1, end);

    return root;
}

Node *BinaryTree::generateFromPre(vector<int> &preorder, vector<int> &inorder)
{
    int currPos = 0;
    int start = 0;
    int end = inorder.size() - 1;

    unordered_map<int, int> hash{};
    for (int i = 0; i <= end; ++i)
        hash[inorder[i]] = i;

    return generateFromPre(preorder, inorder, hash, currPos, start, end);
}

Node *BinaryTree::generateFromPost(vector<int> &inorder, vector<int> &postorder, unordered_map<int, int> &hash, int &currPos, int start, int end)
{
    if (start > end)
        return NULL;

    int pivot = hash[postorder[currPos]];

    currPos--;
    Node *root = new Node(inorder[pivot]);
    root->right = generateFromPost(inorder, postorder, hash, currPos, pivot + 1, end);
    root->left = generateFromPost(inorder, postorder, hash, currPos, start, pivot - 1);

    return root;
}

Node *BinaryTree::generateFromPost(vector<int> &postorder, vector<int> &inorder)
{
    int currPos = postorder.size() - 1;
    int start = 0;
    int end = inorder.size() - 1;

    unordered_map<int, int> hash{};
    for (int i = 0; i <= end; ++i)
        hash[inorder[i]] = i;

    return generateFromPost(inorder, postorder, hash, currPos, start, end);
}

int BinaryTree::Sum(Node *root)
{
    if (root)
    {
        int x = Sum(root->left);
        int y = Sum(root->right);
        return x + y + root->data;
    }
    return 0;
}

int BinaryTree::Count(Node *root)
{
    if (root)
    {
        int x = Count(root->left);
        int y = Count(root->right);
        return x + y + 1;
    }
    return 0;
}

int BinaryTree::Height(Node *root)
{
    if (root)
    {
        int x = Height(root->left);
        int y = Height(root->right);
        return (x > y ? x + 1 : y + 1);
    }
    return 0;
}

int BinaryTree::Leaf(Node *root)
{
    if (root)
    {
        int x = Leaf(root->left);
        int y = Leaf(root->right);
        if (!root->left and !root->right)
            return x + y + 1;
        return x + y;
    }
    return 0;
}

int BinaryTree::NonLeaf(Node *root)
{
    if (root)
    {
        int x = NonLeaf(root->left);
        int y = NonLeaf(root->right);
        if (root->left or root->right)
            return x + y + 1;
        return x + y;
    }
    return 0;
}

int BinaryTree::Degree1Nodes(Node *root)
{
    if (root)
    {
        int x = Degree1Nodes(root->left);
        int y = Degree1Nodes(root->right);
        // Exclusive OR
        // (p and q') or (p' and q)
        if (!root->left ^ !root->right)
            return x + y + 1;
        return x + y;
    }
    return 0;
}

int BinaryTree::Degree2Nodes(Node *root)
{
    if (root)
    {
        int x = NonLeaf(root->left);
        int y = NonLeaf(root->right);
        if (root->left and root->right)
            return x + y + 1;
        return x + y;
    }
    return 0;
}

int main()
{
    BinaryTree BT;
    // BT.create();

    // // Since its a recursive function, we have to pass the root in
    // BT.postOrderR();
    // cout << endl;
    // // Iterative traversal, but very different from other iterative tree traversals
    // BT.postOrderI();
    // cout << endl;
    // // Iterative traversal for level order
    // BT.levelOrder();
    // cout << endl;

    // vector<int> preorder{3, 9, 20, 15, 7};
    // vector<int> inorder{9, 3, 15, 20, 7};
    // Node *newRoot = BT.generateFromPre(preorder, inorder);
    // BT.inOrderR(newRoot);
    // cout << endl;

    // vector<int> postorder{9, 15, 7, 20, 3};
    // vector<int> inorder{9, 3, 15, 20, 7};
    // Node *newRoot = BT.generateFromPost(postorder, inorder);
    // BT.inOrderR(newRoot);
    // cout << endl;

    // cout << "Sum: " << BT.Sum(newRoot) << endl;
    // cout << "Count: " << BT.Count(newRoot) << endl;
    // cout << "Height: " << BT.Height(newRoot) << endl;
    // cout << "Leaf: " << BT.Leaf(newRoot) << endl;
    // cout << "NonLeaf: " << BT.NonLeaf(newRoot) << endl;
    // cout << "Degree 1 Nodes: " << BT.Degree1Nodes(newRoot) << endl;
    // cout << "Degree 2 Nodes: " << BT.Degree2Nodes(newRoot) << endl;
    return 0;
}