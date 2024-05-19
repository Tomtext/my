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
class BinarySearchTree{
private:
    TreeNode<T>* root;
    TreeNode<T>* insertnode(TreeNode <T>*node, T value);
    TreeNode<T>* removenode(TreeNode <T>* node, T value);
    bool searchNode(TreeNode<T>* node, T value);
    void inorder(TreeNode<T>* node);
public:
    BinarySearchTree():root(NULL){}
    ~BinarySearchTree();
    void insert(T value) {
        root = insertnode(root, value);
    }
    void remove(T value) {
        root = removenode(root, value);
    }
    bool search(T value) {
        return searchNode(root, value);
    }
    void InorderTravelsal() {
        inorder(root);
        cout << endl;
    }
};
template<typename T>
BinarySearchTree<T>::~BinarySearchTree() {
    while (root) {
        remove(root->val);
    }
}
template<typename T>
TreeNode<T>* BinarySearchTree<T>::insertnode(TreeNode <T>* node, T value) {
    if (node == NULL) {
        return new TreeNode<T>(value);
    }
    if (value < node->val) {
       node->left= insertnode(node->left, value);
    }
    else if (value > node->val) {
       node->right= insertnode(node->right, value);
    }
    return node;
}
template<typename T>
bool BinarySearchTree<T>::searchNode(TreeNode<T>* node, T value) {
    if (node == NULL) {
        return false;
    }
    if (value < node->val) {
        return searchNode(node->left, value);
    }
    else if (value > node->val) {
        return searchNode(node->right, value);
    }
    return true;
}
template<typename T>
TreeNode<T>* BinarySearchTree<T>::removenode(TreeNode<T>* node, T value) {
    if (node == NULL) {
        return NULL;
    }
    if (value < node->val) {
        node->left = removenode(node->left, value);
    }
    else if (value > node->val) {
        node->right = removenode(node->right, value);
    }
    else {
        if (node->left == NULL && node->right == NULL) {
            delete node;
            return NULL;
        }
        else if (node->left == NULL) {
            TreeNode<T>* rightchild = node->right;
            delete node;
            return rightchild;
        }
        else if (node->right == NULL) {
            TreeNode<T>* leftchild = node->left;
            delete node;
            return leftchild;
        }
        else {
            TreeNode<T>* replacement = node->right;
            while (replacement->left) {
                replacement = replacement->left;
            }
            node->val = replacement->val;
            node->right = removenode(replacement->right, replacement->val);
        }
    }
    return node;
}
template<typename T>
void BinarySearchTree<T>::inorder(TreeNode<T>* node) {
    if (node) {
        inorder(node->left);
        cout << node->val << ' ';
        inorder(node->right);
    }
}
int main()
{
    BinarySearchTree<int>bst;
    bst.insert(50);
    bst.insert(70);
    bst.insert(80);
    bst.insert(30);
    bst.insert(520);
    bst.insert(20);
    bst.remove(20);
    bst.InorderTravelsal();
    cout << bst.search(520);
}
