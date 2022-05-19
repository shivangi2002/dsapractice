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

// name should be descriptive, should start with verb, get, set stc.
int getTreeHeight(Node* root){
    if(root == NULL){
        return 0;
    }
// for code readability, always have space between operators
    if(getTreeHeight(root->left) < getTreeHeight(root->right)){
        return (getTreeHeight(root->right) + 1);
    }
    return (getTreeHeight(root->left)+1);
}

// abbey genz pure naam likh
bool isTreeBalanced(Node* root){
    int leftHeight;
    int rightHeight;
    if(root == NULL){
        return true;
    }
    leftHeight = getTreeHeight(root->left);
    rightHeight = getTreeHeight(root->right);
    if(abs(leftHeight-rightHeight)<=1 && isTreeBalanced(root->left) && isTreeBalanced(root->right)){
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


    if(isTreeBalanced(root)){
        cout << "tree is balanced" <<endl;
    }
    cout <<"tree is not balanced"<< endl;
}
