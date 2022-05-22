#include <bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(): val(0),left(nullptr),right(nullptr){}
    Node(int root): val(root),left(nullptr),right(nullptr){}
    Node(int root, Node* left, Node* right) : val(root),left(left),right(right){}
};
bool isLeaf(Node* node) {
    return (node->left == nullptr && node->right == nullptr);
}
 

void printPath(vector<int> const &path)
{
    for (int i = path.size() - 1; i > 0; i--) {
        // why path path.at(i) and not path[i]?
        cout << path.at(i) << " —> ";
    }
 
    cout << path.at(0) << endl;
}
 

void printLeafToRootPaths(Node* node, vector<int> &path)
{
    if (node == nullptr) {
        return;
    }
 
    
    path.push_back(node->val);
 
    
    if (isLeaf(node)) {
        printPath(path);
    }
 
    
    printLeafToRootPaths(node->left, path);
    printLeafToRootPaths(node->right, path);
 
    
    path.pop_back();
}
 

void printLeafToRootPaths(Node* node)
{
    
    vector<int> path;
 
    printLeafToRootPaths(node, path);
}
 
int main()
{
    
 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->left = new Node(8);
    root->right->left->right = new Node(9);
 
    
    printLeafToRootPaths(root);
 
    return 0;
}
