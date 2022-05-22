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
struct NodeInfo
{
    Node* node;
    int level;
    Node* parent;
};
void updateLevelandParent(Node* root, Node* parent, int level, NodeInfo &x, NodeInfo &y)
{
    
    if (root == nullptr) {
        return;
    }
 
    
    if (root == x.node)
    {
        x.level = level;
        x.parent = parent;
    }
 
    
    if (root == y.node)
    {
        y.level = level;
        y.parent = parent;
    }
    
    updateLevelandParent(root->left, root, level + 1, x, y);
    updateLevelandParent(root->right, root, level + 1, x, y);
}
 

bool checkCousins(Node* root, Node* node1, Node* node2)
{
    
    if (root == nullptr) {
        return false;
    }
 
    int level = 1;              
    Node* parent = nullptr;     
 
    NodeInfo x = {node1, level, parent};
    NodeInfo y = {node2, level, parent};
 
    
    updateLevelandParent(root, nullptr, 1, x, y);
 
    
    return x.level == y.level && x.parent != y.parent;
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
 
    if (checkCousins(root, root->left->right, root->right->left)) {
        cout << "Nodes are cousins of each other";
    }
    else {
        cout << "Nodes are not cousins of each other";
    }
 
    return 0;
}
