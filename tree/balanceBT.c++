#include <bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
    Node():val(0),left(nullptr),right(nullptr){}
    Node(int root): val(root),left(nullptr),right(nullptr){}
    Node(int root,Node* left, Node* right): val(root),left(left),right(right){}

};
int heightt(Node* root){
    if(root == NULL){
        return 0;
    }
    
    if(heightt(root->left)<heightt(root->right)){
        return (heightt(root->right)+1);
    }
    return (heightt(root->left)+1);
}
bool isbal(Node* root){
    int lh;
    int rh;
    if(root == NULL){
        return true;
    }
    lh = heightt(root->left);
    rh = heightt(root->right);
    if(abs(lh-rh)<=1 && isbal(root->left) && isbal(root->right)){
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
    root->left->left->left = new Node(8);
    

    if(isbal(root)){
        cout << "tree is balanced" <<endl;
    }
    cout <<"tree is not balanced"<< endl;
}