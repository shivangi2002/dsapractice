#include <bits/stdc++.h>
#include <stack>
using namespace std;
 
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(): val(0),left(nullptr), right(nullptr){}
    Node(int root): val(root), left(nullptr), right(nullptr){}
    Node(int root, Node* left, Node* right): val(root), left(left), right(right){}
};
void boundarytrav(Node* root){
    if(root == NULL){
        return;
    }
   stack<int> S;
   queue<Node*>V;
   V.push(root);
   while(V.empty() == false){
       int n = V.size();
       for(int i =0; i<n; i++){
           Node* node = V.front();
           V.pop();
           if(i==0 ){
           cout<<node->val<<" ";
           }
           if(i!=0 && i==n-1){
              S.push(node->val); 
           }
           if(i==0 && n == 1 && ((node->left)!=NULL || (node->right)!=NULL)){
               S.push(node->val);
           }
           if(i>0 && i<n-1 && (node->left)==NULL && (node->right)==NULL){
               cout<<node->val<<" ";
           }
           if(node->left!=NULL){
               V.push(node->left);
           }
            if(node->right!=NULL){
               V.push(node->right);
           }
        }
   }
   while (!S.empty()) {
        cout <<S.top() <<" ";
        S.pop();
    }
}

int main()
{
    Node *root =  new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    //root->right->left->right = new Node(8);
    root->right->left->left = new Node(6);
    root->right->left->left->left= new Node(7);
    boundarytrav( root);
    return 0;
}


