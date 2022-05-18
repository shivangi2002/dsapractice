#include <bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(): val(0),left(nullptr),right(nullptr){}
    Node(int root): val(root),left(nullptr),right(nullptr){}
    Node(int root,Node* left, Node* right): val(root),left(left),right(right){}
};
void leftviewfun(struct Node* root,int level,int *maxlevel){
    if(root == NULL){
        return;
    }
    if(*maxlevel < level){
        cout << root->val << " ";
        *maxlevel = level;
    }
    leftviewfun(root->left,level+1,maxlevel);
    leftviewfun(root->right,level+1,maxlevel);
}
void leftview(struct Node* root){
    int maxlevel = 0;
    leftviewfun(root,1,&maxlevel);
}
int main(){
    Node* root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(7);
    root->left->right = new Node(8);
    root->right->left = new Node(12);
    root->right->right = new Node(15);
    root->right->right->left = new Node(14);
    
    leftview(root);
    return 0;
    
}