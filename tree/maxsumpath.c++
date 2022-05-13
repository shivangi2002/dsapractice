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
int findMaxSumPath(Node* root, int &max_sum)
{
   
    if (root == nullptr) {
        return 0;
    }
 
    
    int left = findMaxSumPath(root->left, max_sum);
 
    
    int right = findMaxSumPath(root->right, max_sum);
 
    
    if (root->left == nullptr) {
        return right + root->val;
    }
 
    
    if (root->right == nullptr) {
        return left + root->val;
    }
 
    
    int cur_sum = left + right + root->val;
 
    
 
    max_sum = max(cur_sum, max_sum);
 
    
    return max(left, right) + root->val;
}
 

int findMaxSumPath(Node* root)
{
    int max_sum = INT_MIN;
    findMaxSumPath(root, max_sum);
 
    return max_sum;
}
 
int main()
{
    
 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(-4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
 
    cout << findMaxSumPath(root) << endl;
 
    return 0;
}