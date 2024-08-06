//Post-order Traversal of Binary Tree (Iterative approach using 2 stacks)

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
  //SC: O(2N) for 2 stacks.
  //Left Right Root
  vector<int> postOrderIterative(TreeNode* root) {
    vector<int> postorder;
    if(root == NULL) return postorder;
    
    stack<TreeNode*> st1, st2;
    st1.push(root);
    
    while(!st1.empty()) {
      TreeNode* node = st1.top();
      st1.pop();
      st2.push(node);
      if(node->left != NULL) st1.push(node->left);
      if(node->right != NULL) st1.push(node->right);
    }
    
    while(!st2.empty()) {
      postorder.push_back(st2.top()->data);
      st2.pop();
    }

    return postorder;
  }
};

int main() {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);   
  root->left->right = new TreeNode(5); 
  
  Solution obj;
  vector<int> ans = obj.postOrderIterative(root);  //Output: 4 5 2 3 1
  for(int i=0; i<ans.size();i++){
      cout<<ans[i]<<" ";
  } 
  
  return 0;
}


