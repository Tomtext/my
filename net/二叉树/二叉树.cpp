#include <iostream>
using namespace std;
template<typename T>
struct TreeNode {
	T val;
	TreeNode* left;
	TreeNode* right;
	TreeNode():val(0),left(NULL),right(NULL){}
	TreeNode(T x):val(x),left(NULL),right(NULL){}
};
template<typename T>
class Tree {
private:
	TreeNode<T>*nodes;
	TreeNode<T>*root;
	size_t nodesize;
	TreeNode<T>* Create(T a[], int size, int  nodeId, T nullnode);
	void visit(TreeNode<T>* node);
	void preorder(TreeNode<T>* node);
	void inorder(TreeNode<T>* node);
	void postorder(TreeNode<T>* node);
public:
	Tree();
	Tree(int maxnode);
	~Tree();
	TreeNode<T>* GetTreeNode(int id);
	void CreatTreeNode(T a[], int size, T nullnode);
	void preorderTravelsal();
	void inorderTravelsal();
	void postOrderTravelsal();
};
template<typename T>
Tree<T>::Tree() {
	nodesize = 10001;
	nodes = new TreeNode<T>[nodesize];
}
template<typename T>
Tree<T>::Tree(int maxnode) {
	nodesize = maxnode;
	nodes = new TreeNode<T>[nodesize];
}
template<typename T>
Tree<T>::~Tree() {
	delete[]nodes;
}
template<typename T>
TreeNode<T>* Tree<T>::GetTreeNode(int id) {
	return &nodes[id];
}
template<typename T>
TreeNode<T>* Tree<T>::Create(T a[], int size, int nodeId, T nullnode)
{
	if (nodeId >= size || a[nodeId] == nullnode) {
		return NULL;
	}
	TreeNode<T>* newnode = GetTreeNode(nodeId);
	newnode->val = a[nodeId];
	newnode->left = Create(a, size, nodeId * 2, nullnode);
	newnode->right = Create(a, size, nodeId * 2 + 1, nullnode);
	return newnode;
}
template<typename T>
void Tree<T>::visit(TreeNode<T>* node) {
	cout << node->val;
}
template<typename T>
void Tree<T>::preorder(TreeNode<T>* node) {
	if (node) {
		visit(node);
		preorder(node->left);
		preorder(node->right);
	}
}
template<typename T>
void Tree<T>::inorder(TreeNode<T>* node) {
	if (node) {
		inorder(node->left);
		visit(node);
		inorder(node->right);
	}
}
template<typename T>
void Tree<T>::postorder(TreeNode<T>* node) {
	if (node) {
		postorder(node->left);
		postorder(node->right);
		visit(node);
	}
}
template<typename T>
void Tree<T>::CreatTreeNode(T a[], int size, T nullnode) {
	root = Create(a, size, 1, nullnode);
}
template<typename T>
void Tree<T>::postOrderTravelsal() {
	postorder(root);
}
template<typename T>
void Tree<T>::inorderTravelsal() {
	inorder(root);
}
template<typename T>
void Tree<T>::preorderTravelsal() {
	preorder(root);
}
int main() {
	const char nullnode = '_';
	char a[15] = {
		nullnode,'a','b','c','d',
		nullnode,'e','f','g','h',
		nullnode,nullnode,nullnode,nullnode,'i'
	};
	Tree<char>T(15);
	T.CreatTreeNode(a, 15, nullnode);
	T.inorderTravelsal(); cout << endl;
	T.postOrderTravelsal(); cout << endl;
	T.preorderTravelsal();
}