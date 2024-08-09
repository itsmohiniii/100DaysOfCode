//Zig-Zag or Spiral Traversal in Binary Tree

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
  int data;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
 }; 

class Solution {
  public: 
  //TC: O(N), SC:O(N) => both similar to Level Order Traversal
  vector<vector<int>> zigzagLevelOrder (TreeNode* root) {
    vector<vector<int>> res;
    if(root == nullptr) {
      return res;
    }
    
    queue<TreeNode*> nodesQueue;
    nodesQueue.push(root);
    bool leftToRight = true;
    
    while(!nodesQueue.empty()) {
      int size = nodesQueue.size();
      vector<int> row(size);

      for(int i =0;i<size;i++) {
        TreeNode* node = nodesQueue.front();
        nodesQueue.pop();

        //find position to fill node's value (whether to insert in 'row' vector from leftToRight or rightToLeft)
        int index = leftToRight ? i : (size-1-i);
        row[index] = node->data;
        
        if(node->left != nullptr) {
          nodesQueue.push(node->left);
        }
        if(node->right != nullptr) {
          nodesQueue.push(node->right);
        }
      }

      //after this level
      leftToRight = !leftToRight;
      res.push_back(row);
    } 
    
    return res;
  }
};

int main() {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);   
  root->left->right = new TreeNode(5); 
  root->left->left->left = new TreeNode(6); 
  root->left->left->right = new TreeNode(7);   
  
  Solution obj;
  vector<vector<int>> zigzagOrder = obj.zigzagLevelOrder(root);  
  for(int i=0; i<zigzagOrder.size(); i++) {
    for(auto it: zigzagOrder[i]) {
      cout<<it<<" ";
    }
    cout<<endl;
  }
//   Output: 
//   1 
//   3 2 
//   4 5 
//   7 6 

  return 0;
}


