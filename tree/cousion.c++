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
void findLevel(Node* root, Node* x, int index, int &level)
{
   
    if (root == nullptr || level) {
        return;
    }
 
    
    if (root == x) {
        level = index;
    }
 
    
    findLevel(root->left, x, index + 1, level);
    findLevel(root->right, x, index + 1, level);
}
 
void printLevel(Node* root, Node* node, int level)
{
    if (root == nullptr) {
        return;
    }
 
    
    if (level == 1)
    {
        cout << root->val << " ";
        return;
    }
 
    
    if (!(root->left && root->left == node || root->right && root->right == node))
    {
        printLevel(root->left, node, level - 1);
        printLevel(root->right, node, level - 1);
    }
}
 

void printAllCousins(Node* root, Node* node)
{
    
    if (root == nullptr || root == node) {
        return;
    }
 
    int level = 0;
 
    
    findLevel(root, node, 1, level);
 
   
    printLevel(root, node, level);
}
 
int main()
{
    
 // wont work
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
 
    printAllCousins(root, root->right->left);
 
    return 0;
}
