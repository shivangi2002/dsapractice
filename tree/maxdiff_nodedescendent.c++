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
int findMaxDifference(Node* root, int &diff)
{
    
    if (root == nullptr) {
        return INT_MAX;
    }
 
    int left = findMaxDifference(root->left, diff);
    int right = findMaxDifference(root->right, diff);
 
    
    int d = INT_MIN;
    if (min(left, right) != INT_MAX) {
        d = root->val - min(left, right);
    }
 
// can diff be min?    
    diff = max(diff, d);
 
    
    return min(min(left, right), root->val);
}
 

int findMaxDifference(Node* root)
{
    int diff = INT_MIN;
    findMaxDifference(root, diff);
 
    return diff;
}
 
int main()
{
    
 
    Node* root = new Node(6);
    root->left = new Node(3);
    root->right = new Node(8);
    root->right->left = new Node(2);
    root->right->right = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(7);
 
    cout << findMaxDifference(root);
 
    return 0;
}
