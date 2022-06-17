#include<bits/stdc++.h>
using namespace std;
int x;
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(): val(0), left(nullptr), right(nullptr){ }
    Node(int root): val(root),left(nullptr),right(nullptr){ }
    Node(int root, Node* left, Node* right): val(root), left(left), right(right){ }
    
};
void left(Node* root){
    if (root == NULL){
        return;
    }
    if((root->left) != NULL){
        cout<< root->val <<" ";
        left(root->left);
    }
    if((root->left) == NULL && (root->right) != NULL){
         cout<< root->val <<" ";
         left(root->right);
    }
}
void  printLeafNodes(Node* root){
   if(root == NULL){
       return;
   }
   if((root->left)== NULL && (root->right)==NULL){
       cout << root->val << " ";
   }
   if ((root->left) != NULL){
       printLeafNodes(root->left);
   }
         
   
    if  ((root->right) != NULL){
       printLeafNodes(root->right);
    }
}
void rights(Node* root){
    
   queue<Node*>q ;
    if(root == NULL){
        return;
    }
    if((root->right) != NULL){
       rights(root->right);
       if((root->val)!= x){
           cout << root->val<<" ";
       }
    }
    if((root->right) == NULL && (root->left) != NULL){
         rights(root->left);
         if((root->val)!= x){
           cout << root->val<<" ";
       }
    }
      
}
void boundary(Node* root){
    x = root->val;
    if(root == NULL){
        return;
    }
    left(root);
    printLeafNodes(root);
    rights(root);
}

int main(){
    
    struct Node* root = new Node(1); 
    root->left = new Node(2); 
    root->left->left = new Node(4); 
    root->left->left->right = new Node(7);
    root->right = new Node(3); 
    root->right->right = new Node(6); 
    root->right->left = new Node(5); 
    boundary(root);
}