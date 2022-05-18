#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(): val(0),left(nullptr),right(nullptr){}
    Node(int root): val(root),left(nullptr),right(nullptr){}
    Node(int root, Node* left, Node* right): val(root),left(left),right(right){}
};
void inorder(Node* root){
  if(root == NULL){
      return;
  }  
  inorder(root->left);
  cout << root->val <<" ";
  inorder(root->right);
}
void mirror(Node* root){
    if(root==NULL){
        return;
    }
    struct Node* temp;
    mirror(root->left);
    mirror(root->right);
    temp = root->left;
    root->left = root->right;
    root->right = temp;

}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    cout<<"inorder of orignal tree :  \n";
    inorder(root);

    mirror(root);
    cout<<"\ninorder of mirror tree :  \n";
    inorder(root);

}