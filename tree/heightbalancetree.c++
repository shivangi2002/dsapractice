#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node():  val(0), left(nullptr), right(nullptr){}
    Node(int root): val(root), left(nullptr), right(nullptr){}
    Node(int root, Node* left, Node* right): val(root), left(left), right(right){}
};
int height(Node* root){
    if(root==NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    if(left<right){
        return (right+1);
    }
    return (left+1);
}
bool balanc(Node* root){
    if(root == NULL){
        return true;
    }
    int lh = height(root->left);
    int rh = height(root->right);
   
        
    if(abs(rh-lh)<=1 && balanc(root->left) && balanc(root->right)){
        return true; 
    }
    return false;
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->left->left->left = new Node(7);
    if(balanc(root)){
        cout <<" balance";
    }
    else{
        cout <<"not balance";
    }
    return 0;
}
