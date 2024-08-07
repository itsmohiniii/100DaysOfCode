//Post-order Traversal of Binary Tree (Iterative approach using 1 stack)

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
  //TC: O(2N) for traversing while storing N nodes into the stack, for traversing back while printing N nodes.
  //SC: O(N) for 1 stack.
  //Left Right Root
  vector<int> postOrderIterative(TreeNode* root) {
    vector<int> postorder;
    if(root == NULL) return postorder;
    
    stack<TreeNode*> st;
    TreeNode* curr = root;
    
    while(curr!=NULL || !st.empty()) {
      if(curr!=NULL) {
        st.push(curr);
        curr=curr->left;
      } 
      else {
        TreeNode* temp = st.top()->right;
        if(temp == NULL) {
          temp = st.top();
          st.pop();
          postorder.push_back(temp->data);
          while(!st.empty() && temp == st.top()->right) {
            temp = st.top();
            st.pop();
            postorder.push_back(temp->data);
          }
        }
        else {
          curr = temp;
        }
      }
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


