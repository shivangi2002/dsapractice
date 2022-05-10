# include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node *left, *right;
};

Node* newNode(int data){
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
int isidentical(struct Node* x, Node* y ){
    if(x == NULL && y == NULL ){
        return 1;
    }
    else if(x == NULL && y!=NULL){
        return 0;
    }
    else if(x != NULL && y == NULL){
        return 0;
    }
    else{
        if(x->data == y->data && isidentical(x->left,y->right) && isidentical(x->right,y->right)){
            return 1;
        }
        else{
            return 0;
        }
    }
    
}
int main(){
    struct Node* x = newNode(15);
    x->left = newNode(10);
    x->right = newNode(20);
    x->left->left = newNode(8);
    x->left->right = newNode(12);
    x->right->left = newNode(16);
    x->right->right = newNode(25);

    struct Node* y = newNode(15);
    y->left = newNode(10);
    y->right = newNode(20);
    y->left->left = newNode(8);
    y->left->right = newNode(12);
    y->right->left = newNode(16);
    y->right->right = newNode(25);
    
    if(isidentical(x,y)){
        cout << "trees are identical";
    }
    else{
        cout <<" trrees are not identical";
    }
    return 0;
}