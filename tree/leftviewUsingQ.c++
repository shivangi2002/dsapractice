#include <bits/stdc++.h>
using namespace std;

 
 
 
struct Node 
{
int val;
Node * right;
Node * left;
Node ():val (0), left (nullptr), right (nullptr) { } 
Node (int root):val (root), left (nullptr), right (nullptr) { } 
Node (int root, Node * left, Node * right):val (root), left (left),right (right) { } 
};



void ltrav (Node * root) {
  
    if (root == NULL) {
        return;
    }
    
    queue < Node * >V;
    V.push (root);
    
    while (V.empty () == false){ 
        int n = V.size ();
        
        for (int i = 0; i < n; i++)	{
            Node * node = V.front ();
	        V.pop ();
	        if (i == 0){
	        cout << node->val << " ";
	        }
            if (node->left != NULL) {
	            V.push (node->left);
            }
	        if (node->right != NULL) {
	            V.push (node->right);
            }
	    }
    }
}


 
int main () 
{
    Node* root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(8);
    root->left->right = new Node(12);
    root->right->left = new Node(16);
    root->right->right = new Node(25);
    ltrav(root);
} 
