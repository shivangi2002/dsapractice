#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(): val(0), left(nullptr), right(nullptr){}
    Node(int root): val(root),  left(nullptr), right(nullptr){}
    Node(int root, Node* left, Node* right): val(root), left(left), right(right){}
};
int sumtree(Node* root){
    if(root == NULL){
        return 0;
    }
    int oriroot = root->val;
    int leftsum = sumtree(root->left);
    int rightsum = sumtree(root->right);
    root->val = leftsum + rightsum;
    return leftsum+rightsum+oriroot;
}

void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(6);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);
    root->right->left = new Node(7);
    root->right->right = new Node(5);
    preorder(root);
    sumtree(root);
    cout <<endl;
    preorder(root);
}
