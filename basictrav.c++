# include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node *left, *right;
};
Node* newNode(int data){
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp; 
}

void printPreor(struct Node* node){
    if(node==NULL){
        return ;
    }
    cout << node->data <<" ";
    printPreor(node->left);
    printPreor(node->right);
}
void printInor(struct Node* node){
    if(node == NULL){
        return;
    }
    printInor(node->left);
    cout << node->data <<" ";
    printInor(node->right);
}
void printPostor(struct Node* node){
    if(node==NULL){
        return;
    }
    printPostor(node->left);
    printPostor(node->right);
    cout << node->data <<" ";
}
int main(){
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
   cout <<"\n preorder:  \n";
   printPreor(root);
   cout <<"\n inorder : \n";
   printInor(root);
   cout << "\n postorder: \n";
   printPostor(root);
   return 0;

}