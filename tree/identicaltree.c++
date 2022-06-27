#include <iostream>
using namespace std;

struct Node{
  int val;
  Node* left;
  Node* right;
  Node(): val(0), left(nullptr), right(nullptr){}
  Node(int root1): val(root1), left(nullptr), right(nullptr){}
  Node(int root1, Node* left, Node* right): val(root1), left(left), right(right){}
};
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
int main()
{
    Node *root1 = new Node(1);
    Node *root2 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
 
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(7);
    root2->left->right = new Node(5);
    
    if(id(root1, root2)){
       cout <<"identical"  <<endl;
    }
    else{
        cout<<"not identical"<<endl;
    }
    return 0;
}

