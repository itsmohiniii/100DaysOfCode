//Check for Balanced Binary Tree

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
  private:
  int maxDepth(TreeNode* root) {
    if(root == NULL) return 0;
    
    int lh = maxDepth(root->left);
    if(lh==-1) return -1;
    
    int rh = maxDepth(root->right);
    if(rh==-1) return -1;
    
    if(abs(lh-rh) > 1) return -1;

    return 1 + max(lh,rh);
  }
  
  public:
  //TC: O(N) as we traverse all nodes using recursion.
  //SC: O(N) => it takes O(H) for recursive auxiliary stack space WC: if skewed tree, height of binary tree will be N, hence, SC = O(N).
  bool isBalanced(TreeNode* root) {
    return maxDepth(root)!=-1;
  }
};

int main() {
//   //Output: 0
//   TreeNode* root = new TreeNode(1);
//   root->left = new TreeNode(2);
//   root->right = new TreeNode(3);
//   root->left->left = new TreeNode(4);   
//   root->left->right = new TreeNode(5); 
//   root->left->left->left = new TreeNode(6);  
  
  //Output: 1
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);   
  root->left->right = new TreeNode(5); 

  Solution obj;
  cout<<obj.isBalanced(root);

  return 0;
}
