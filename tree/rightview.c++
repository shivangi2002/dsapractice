#include <bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(): val(0),left(nullptr),right(nullptr){}
    Node(int root): val(root),left(nullptr),right(nullptr){}
    Node(int root, Node* left, Node* right): val(root),left(left),right(right){}
};
void rightviewfun(struct Node* root,int level, int *maxlevel){
    if(root == NULL){
        return;
    }
    if(*maxlevel <level){
        cout << root->val <<" ";
        *maxlevel = level;
    }
    rightviewfun(root->right,level+1,maxlevel);
    rightviewfun(root->left,level+1,maxlevel);
}
void rightview(struct Node* root){
    int maxlevel = 0;
    rightviewfun(root, 1 , &maxlevel);
}
int main(){
     Node* root = new Node(1);
     root->left = new Node(2);
     root->right = new Node(3);
     root->left->left = new Node(4);
     root->left->right = new Node(5);
     root->right->left = new Node(6);
     root->right->right = new Node(7);
     root->right->right->right = new Node(8);
     rightview(root);
}