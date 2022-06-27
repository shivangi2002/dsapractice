#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(): val(0), left(nullptr), right(nullptr){}
    Node(int root): val(root), left(nullptr), right(nullptr){}
    Node(int root, Node* left, Node* right): val(root), left(left), right(right){}
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
bool id(Node* root1, Node* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    if(root1 != NULL && root2 != NULL){
        if((root1->val == root2->val) && id(root1->left,root2->left)&&id(root2->right,root1->right)){
            return true;
        }
        
    }
    return false;
}
void symm(Node* root){
    mirrortree(root->left);
    
   if( id(root->left,root->right)){
       cout <<"symmetric";
   }
   else{
       cout<<"not symmetric";
   }
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);
 
	
    symm(root);
    
}
