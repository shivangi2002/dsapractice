#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(): val(0),left(nullptr),right(nullptr){}
    Node(int root):val(root),left(nullptr),right(nullptr){}
    Node(int root, Node* left, Node* right): val(root),left(left),right(right){}
};
void mirrortree(Node* root){
    if(root==NULL){
        return;
    }
    Node* node;
    mirrortree(root->left);
    mirrortree(root->right);
    node = root->left;
    root->left = root->right;
    root->right = node;
}
void preorder(Node* root){
    if(root== NULL){
        return;
    }
    cout<<root->val <<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    Node *root = new Node(6);
    root->left = new Node(2);
    root->right = new Node(9);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left  = new Node(8);
    preorder(root);
    mirrortree(root);
    cout<<endl;
    preorder(root);
}
