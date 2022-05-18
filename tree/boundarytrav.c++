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
void printLeftbou(Node* root){
    if(root==nullptr){
        return;
    }
    if(root->left){
        cout<<root->val<<" ";
        printLeftbou(root->left);
    }
    if(root->right){
        cout <<root->val<<" ";
        printLeftbou(root->right);
    }
    
}
void printleav(Node* root){
    if(root==nullptr){
        return;
    }
    printleav(root->left);
    if(!(root->left)&&!(root->right)){
        cout << root->val<<" ";
    }
    printleav(root->right);
}
void printRightbou(Node* root){
    if(root== nullptr){
        return;
    }
    if(root->right){
        printRightbou(root->right);
        cout << root->val <<" ";
    }
    if(root->left){
        printRightbou(root->left);
        cout << root->left<<" ";
    }
}
void printBounday(Node* root){
    if(root==nullptr){
        return;
    }
    cout << root->val<<" ";
    printLeftbou(root->left);
    printleav(root->left);
    printleav(root->right);
    printRightbou(root->right);
}
int main(){
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->right->right = new Node(25);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    printBounday(root);

}