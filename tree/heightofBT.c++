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
int heightt(Node* root){
    if(root == NULL){
        return 0;
    }
    else{
        int lh = heightt(root->left);
        int rh = heightt(root->right);
        if(lh<rh){
            return (rh+1);
        }
        return (lh+1);
    }
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    cout <<heightt(root)<<" ";
}