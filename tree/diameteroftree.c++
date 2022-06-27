#include <bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* right;
    Node* left;
    Node(): val(0), left(nullptr),right(nullptr){}
    Node(int root): val(0), left(nullptr), right(nullptr){}
    Node(int root, Node* left, Node* right): val(root), left(left), right(right){}
};
int height(Node* root){
    if(root == NULL){
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    if(lh<rh){
        return (rh+1);
    }
    return (lh+1);
}
void dia(Node* root){
    if(root == NULL){
        return;
    }
    int lefttreeheight = height(root->left);
    int righttreeheight = height(root->right);
    int diameter = lefttreeheight+righttreeheight+1;
    cout <<diameter;
}
int main(){
    Node *root =  new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->left->right = new Node(8);
    root->right->left->left = new Node(6);
    root->right->left->left->left= new Node(7);
    dia(root);
    return 0;
}
