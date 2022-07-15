#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
private:
	int data, height;
	TreeNode *left, *right;

public:
	TreeNode(int data, int height) : data(data), left(NULL), right(NULL), height(height) {}
	friend class AVL;
};

class AVL
{
private:
	TreeNode *root;

public:
	// Constructor
	AVL()
	{
		root = NULL;
	}

	// Helper functions for Insertion
	int nodeHeight(TreeNode *);
	int balanceFactor(TreeNode *);

	// Helper function for Deletion
	TreeNode *inorderPre(TreeNode *);
	TreeNode *inorderSuc(TreeNode *);

	// Rotations for balancing
	TreeNode *LLRotation(TreeNode *);
	TreeNode *LRRotation(TreeNode *);
	TreeNode *RRRotation(TreeNode *);
	TreeNode *RLRotation(TreeNode *);

	// Insertion and Deletion
	TreeNode *Insert(TreeNode *, int);
	void Insert(int data)
	{
		Insert(root, data);
	}

	TreeNode *Delete(TreeNode *, int);
	void Delete(int data)
	{
		Delete(root, data);
	}

	// Tree Traversals
	void inorder(TreeNode *);
	void inorder()
	{
		inorder(root);
	}

	void preorder(TreeNode *);
	void preorder()
	{
		preorder(root);
	}
};

int AVL::nodeHeight(TreeNode *root)
{
	int leftHeight, rightHeight;

	// check if root and root->direction exist and take its value
	leftHeight = ((root and root->left) ? root->left->height + 1 : 1);
	rightHeight = ((root and root->right) ? root->right->height + 1 : 1);

	// return the max of the two values
	return ((leftHeight > rightHeight) ? leftHeight : rightHeight);
}

int AVL::balanceFactor(TreeNode *root)
{
	int leftHeight, rightHeight;

	// incremented the values by 1 just to maintain consistency
	leftHeight = ((root and root->left) ? root->left->height + 1 : 1);
	rightHeight = ((root and root->right) ? root->right->height + 1 : 1);

	// returns negative BF if leftH is more than rightHeight
	return leftHeight - rightHeight;
}

TreeNode *AVL::LLRotation(TreeNode *root)
{
	TreeNode *rootL = root->left;
	TreeNode *rootLR = rootL->right;

	rootL->right = root;
	root->left = rootLR;

	root->height = nodeHeight(root);
	rootL->height = nodeHeight(rootL);

	if (this->root == root)
		this->root = rootL;
	return rootL;
}

TreeNode *AVL::LRRotation(TreeNode *root)
{
	TreeNode *rootL = root->left;
	TreeNode *rootLR = rootL->right;
	TreeNode *rootLRL = rootLR->left;
	TreeNode *rootLRR = rootLR->right;

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

TreeNode *AVL::RRRotation(TreeNode *root)
{
	TreeNode *rootR = root->right;
	TreeNode *rootRL = rootR->left;

	root->right = rootRL;
	rootR->left = root;

	root->height = nodeHeight(root);
	rootR->height = nodeHeight(rootR);

	if (root == this->root)
		this->root = rootR;
	return rootR;
}

TreeNode *AVL::RLRotation(TreeNode *root)
{
	TreeNode *rootR = root->right;
	TreeNode *rootRL = rootR->left;
	TreeNode *rootRLL = rootRL->left;
	TreeNode *rootRLR = rootRL->right;

	root->right = rootRLL;
	rootR->left = rootRLR;
	rootRL->right = rootR;
	rootRL->left = root;

	// recalibrating the height of nodes
	root->height = nodeHeight(root);
	rootR->height = nodeHeight(rootR);
	rootRL->height = nodeHeight(rootRL);

	if (root == this->root)
		this->root = rootRL;
	return rootRL;
}

TreeNode *AVL::inorderPre(TreeNode *root)
{
	root = root->left;
	while (root and root->right)
		root = root->right;
	return root;
}

TreeNode *AVL::inorderSuc(TreeNode *root)
{
	root = root->right;
	while (root and root->left)
		root = root->left;
	return root;
}

void AVL::inorder(TreeNode *root)
{
	if (!root)
		return;

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void AVL::preorder(TreeNode *root)
{
	if (!root)
		return;

	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

TreeNode *AVL::Insert(TreeNode *root, int data)
{
	// if it has reached the bottom
	if (!root)
	{
		root = root = new TreeNode(data, 1);
		if (!this->root)
			this->root = root;
		return root;
	}
	else if (data < root->data)
		root->left = Insert(root->left, data);
	else if (data > root->data)
		root->right = Insert(root->right, data);

	// Update height in the returning phase of the recursion
	root->height = nodeHeight(root);

	// Rotate Tree based on the balance factor
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

TreeNode *AVL::Delete(TreeNode *root, int data)
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
			TreeNode *temp = inorderPre(root);
			root->data = temp->data;
			root->left = Delete(root->left, temp->data);
		}
		else
		{
			TreeNode *temp = inorderSuc(root);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}
	}
	root->height = nodeHeight(root);
	// Here we are doing rotation like how we did for insertion,
	// But, here we need to include one more condition
	// When BF is 2 and the child nodes have 0 as their BF
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

	avl.inorder();
	cout << endl;

	avl.Delete(28);

	avl.inorder();
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
