# include <bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(): val(0), left(nullptr),right(nullptr){}
    Node(int root): val(root),left(nullptr),right(nullptr){}
    Node(int root, Node* left, Node* right): val(root),left(left), right(right){}
};
vector<int>topview(Node *root){
       deque<int> v;
        vector<int> a;
        if(root == NULL){
            return a;
        }
        queue<pair<Node*,int>> q; 
        q.push({root,0});    
		
		
        v.push_back(root->val);    
		
	
        int l=0;      
        int r=0;
        while(q.size() != 0){
            Node *t = q.front().first;
            int vh = q.front().second;
            q.pop();
            
            if(vh>r) {
                r=vh;
                v.push_back(t->val);
            }
          
            if(vh<l) {
                l=vh;
                v.push_front(t->val);
            }
			
            if(t->left) q.push({t->left,vh-1});   
            if(t->right) q.push({t->right,vh+1});

        }
        while(v.size()){
            a.push_back(v.front());
            v.pop_front();
        }
        
        return a;
 
}
int main(){
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> right = new Node(4);
    root -> left -> right -> right = new Node(5);
    root -> left -> right -> right -> right = new Node(6);
    vector<int> x = topview(root);
    for (int i = 0; i < x.size(); i++){
        cout << x[i] << " ";
    }
}
