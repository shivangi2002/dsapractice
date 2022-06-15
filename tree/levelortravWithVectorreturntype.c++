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
vector<int> ltrav(Node* root){
     vector<int>f;
    if(root == NULL){
        return f;
    }
    vector<Node*> V;
    V.push_back(root);
    while(V.empty() == false){
        Node* node = V.front();
        f.push_back(node->val);
        
        V.erase(V.begin());
        if (node->left != NULL){
            V.push_back(node->left);
        }
        if (node->right != NULL){
            V.push_back(node->right);
        }
    } 
    return f;
    
}
int main(){
    vector<int>mor;
    Node* root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(8);
    root->left->right = new Node(12);
    root->right->left = new Node(16);
    root->right->right = new Node(25);
    mor=ltrav(root);
     for (int i=0; i<mor.size();i++)
      {
          cout<<mor[i]<<" ";
      }
      return 0;
}