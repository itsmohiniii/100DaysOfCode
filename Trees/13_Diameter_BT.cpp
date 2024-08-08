//Diameter of Binary Tree

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
  int maxDepth(TreeNode* root, int& diameter) {
    if(root == NULL) return 0;
    
    int lh = maxDepth(root->left, diameter);
    int rh = maxDepth(root->right, diameter);
    
    diameter = max(diameter, lh+rh);

    return 1+max(lh,rh);
  }
  
  public:
  //TC: O(N) as we traverse all nodes.
  //SC: O(N) => it takes O(H) for recursive auxiliary stack space WC: if skewed tree, height of binary tree will be N, hence, SC = O(N).
  int  (TreeNode* root) {
    int diameter = 0;
    maxDepth(root, diameter);
    return diameter;
  }
};

int main() {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);   
  root->left->right = new TreeNode(5); 
  root->left->left->left = new TreeNode(6); 
  
  Solution obj;
  cout<<obj.diameterBT(root);  //Output: 4

  return 0;
}


