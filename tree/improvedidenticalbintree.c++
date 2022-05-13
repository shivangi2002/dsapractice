# include <bits/stdc++.h>
using namespace std;
// Use new method of creating constructor in struct: https://stackoverflow.com/questions/1127396/struct-constructor-in-c
struct Node {
      int val;
      Node *left;
      Node *right;
      Node() : val(0), left(nullptr), right(nullptr) {}
      Node(int x) : val(x), left(nullptr), right(nullptr) {}
      Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
  };
class Solution {
    
public:
    // it should return boolean not integer
    bool isidentical( Node* x, Node* y ){
    if(x == NULL && y == NULL ){
        return true;
    }
// simplify to one statement, no need of else, return se else ki zaroorat nhi hai
/*
    else if(x == NULL && y!=NULL){
        return 0;
    }
    else if(x != NULL && y == NULL){
        return 0;
    }
*/
if (x == NULL || y == NULL) {
    return false;
}

//    else{
        if(x->val == y->val && isidentical(x->left,y->left) && isidentical(x->right,y->right)){
            return true;
        }
       // else{
         //   return 0;
        //}
        
    //}
return false;
    
}
};


int main(){
    Node* x = new Node(15);
    x->left = new Node(10);
    x->right = new Node(20);
    x->left->left = new Node(8);
    x->left->right = new Node(12);
    x->right->left = new Node(16);
    x->right->right = new Node(25);

    struct Node* y = new Node(15);
    y->left = new Node(10);
    y->right = new Node(20);
    y->left->left = new Node(8);
    y->left->right = new Node(12);
    y->right->left = new Node(16);
    y->right->right = new Node(25);
    Solution s = Solution();
    if(s.isidentical(x,y)){
        cout << "trees are identical";
    }
    else{
        cout <<" trrees are not identical";
    }
    return 0;
}