#include <bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(): val(0),left(nullptr),right(nullptr){}
    Node(int x): val(x),left(nullptr),right(nullptr){}
    Node(int x, Node* left, Node* right) : val(x),left(left),right(right){}
};


    int transform (Node* x){
        if(x==nullptr){
            return 0;
        }
        int left = transform(x->left);
        int right = transform(x->right);
        int temp = x->val;
        x->val = left+right;
        return x->val+temp; 
    }
    


    void pror(Node* x){
        if(x==nullptr){
            return ;
        }
        cout << x->val <<" ";
        pror(x->left);
        pror(x->right);
    }
int main(){
    Node* x = new Node(1);
    x->left = new Node(2);
    x->right = new Node(3);
    x->left->right = new Node(4);
    x->right->left = new Node(5);
    x->right->right = new Node(6);
    x->right->left->left = new Node(7);
    x->right->left->right = new Node(8);
    // why?
    transform(x);
    pror(x);
    
}
