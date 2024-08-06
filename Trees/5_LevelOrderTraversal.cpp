//Level order Traversal of Binary Tree

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
  //TC: O(N) as we traverse for N nodes.
  //SC: O(N) for queue WC: queue can store N nodes at a time
  vector<vector<int>> levelOrder(TreeNode* root) {
    //we do not consider SC for 'ans' data structure as we are storing the answer and returning it. 
    vector<vector<int>> ans;
    if(root == nullptr) return ans;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty()) {
      int size = q.size();
      vector<int> level;
      for(int i=0;i<size;i++) {
        TreeNode* node = q.front();
        q.pop();
        if(node->left != NULL) q.push(node->left);
        if(node->right != NULL) q.push(node->right);
        level.push_back(node->data);
      }
      ans.push_back(level);
    }
    
    return ans;
  }
};

int main() {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);   
  root->left->right = new TreeNode(5); 
  
  Solution obj;
  vector<vector<int>> ans = obj.levelOrder(root);
  for(int i=0; i<ans.size();i++){
      for(auto j: ans[i]){
          cout<<j<<" ";
      }
      cout<<endl;
  }
  //Output: 
  // 1
  // 2 3
  // 4 5
  
  return 0;
}
