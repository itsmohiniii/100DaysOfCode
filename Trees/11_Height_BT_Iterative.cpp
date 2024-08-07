//Maximum Depth or Height of Binary Tree (using Level Order Traversal - Iterative Approach)
//Approach: Use a variable 'level', which increases by 1 on going left or right, and the highest level will always be the answer.

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
  //SC: O(N) => it takes O(H) for recursive stack space WC: if skewed tree, height of binary tree will be N, hence, SC = O(N).
  int maxDepth(TreeNode* root) {
    
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
