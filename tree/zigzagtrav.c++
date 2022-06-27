#include <bits/stdc++.h>
using namespace std;
struct Node{
  int val;
  Node* right;
  Node* left;
  Node(): val(0),left(nullptr),right(nullptr){}
  Node(int root): val(root),left(nullptr),right(nullptr){}
  Node(int root, Node* left, Node* right): val(root),left(left),right(right){}
  
};
void ltrav(Node* root){
    if(root == NULL){
        return;
    }
    
    queue<Node*> V;
    V.push(root);
   int  cnt = 1;
    while(V.empty() == false){
        Node* node = V.front();
        cout << node->val <<" ";
        V.pop();
        if( cnt%2==0){
            if (node->left != NULL){
                V.push(node->left);
            }
            if (node->right != NULL){
                V.push(node->right);
            }
            cnt++;
        }
        else if(cnt%2!=0){
            if (node->right != NULL){
                V.push(node->right);
            }
            if (node->left != NULL){
                V.push(node->left);
            }
           cnt++; 
        }
    } 
    
}

int main(){
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
   
    root->right->left = new Node(15);
    root->right->right = new Node(7);
    ltrav(root);
}
