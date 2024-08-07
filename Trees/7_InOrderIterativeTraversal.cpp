//In-order Traversal of Binary Tree (Iterative approach)

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
  int data;
  TreeNode* left;
  TreeNode* right;

  TreeNode() {
    data = 0;
    left = nullptr;
    right = nullptr;
  }

  TreeNode(int val) {
    data = val;
    left = nullptr;
    right = nullptr;
  }
  
  TreeNode(int val, TreeNode* le, TreeNode* ri) {
    data = val;
    left = le;
    right = ri;
  }
}; 

class Solution {
public:
  //TC: O(N) as we traverse N nodes.
  //SC: O(N) ~ O(H) where H-> height of BT. for stack WC: stack will store N nodes if the tree just has left children. (i.e. skewed tree)
  //Left Root Right
  vector<int> inOrderIterative(TreeNode* root) {
    vector<int> inorder;
    if(root == NULL) return inorder;
    
    stack<TreeNode*> st; //LIFO
    TreeNode* curr = root; //current node
    
    while(true) {
      if(curr !=  NULL) {
        st.push(curr); //created auxiliary stack space using stack DS 
        curr = curr->left;
      } 
      else { // node is NULL
        if(st.empty()) break;
        curr = st.top();
        st.pop();
        inorder.push_back(curr->data);
        curr = curr->right;
      }
    }
    
    return inorder;
  }
};

int main() {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);   
  root->left->right = new TreeNode(5); 
  
  Solution obj;
  vector<int> ans = obj.inOrderIterative(root);  //Output: 4 2 5 1 3
  for(int i=0; i<ans.size();i++){
      cout<<ans[i]<<" ";
  } 
  return 0;
}
