//Pre-order Traversal of Binary Tree (Iterative approach)

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
  //TC: O(N) as every node of the binary tree is visited exactly once.
  //SC: O(N) ~ O(H) where H-> height of BT. for stack WC: stack can store N nodes when every node always has a right child.
  //Root Left Right
  vector<int> preOrderIterative(TreeNode* root) {
    vector<int> preorder;
    if(root == NULL) return preorder;
    
    stack<TreeNode*> st; //LIFO
    st.push(root);
    
    while(!st.empty()) {
      TreeNode* node = st.top();
      st.pop();
      preorder.push_back(node->data);
      
      //push right child and then left child into the stack so that left is on the top of stack and printed frist. (Root Left Right)
      if(node->right != NULL) st.push(node->right);
      if(node->left != NULL) st.push(node->left);
    }
    
    return preorder;
  }
};

int main() {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);   
  root->left->right = new TreeNode(5); 
  
  Solution obj;
  vector<int> ans = obj.preOrderIterative(root);  //Output: 1 2 4 5 3
  for(int i=0; i<ans.size();i++){
      cout<<ans[i]<<" ";
  } 
  return 0;
}


