//Maximum Depth or Height of Binary Tree (using Level Order Traversal - Iterative Approach)
//Hint: Use a variable 'level', which increases by 1 on going left or right, and the highest level will always be the answer.

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
  int data;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int val) {
    data = val;
    left = nullptr;
    right = nullptr;
  }
 }; 

class Solution {
  public:
  //TC: O(N) as we traverse all nodes.
  //SC: O(N) => for queue WC: if complete BT & last level is completely filled, queue will end up storing almost all N nodes.
  int maxDepth(TreeNode* root) {
    int levels = 0;
    if(root == NULL) return levels;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty()) {
      int size = q.size();
      for(int i=0;i<size;i++) {
        TreeNode* node = q.front();
        q.pop();
        if(node->left != NULL) q.push(node->left);
        if(node->right != NULL) q.push(node->right);
      }
      levels++;
    }
    
    return levels;
  }
};

int main() {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);   
  root->left->right = new TreeNode(5); 
  
  Solution obj;
  cout<<obj.maxDepth(root);  //Output: 3

  return 0;
}
