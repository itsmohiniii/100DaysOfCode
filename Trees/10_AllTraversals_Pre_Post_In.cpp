//All Traversals in one (Postorder, Preorder, Inorder)

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
  //TC: O(3*N) ~ linear TC. as we are iterating thrice for every node.
  //SC: O(4N) ~ linear SC. for stack, for pre vector, for in vector, for post vector
  vector<vector<int>> preInPostTraversal(TreeNode* root) {
    vector<vector<int>> traversals;
    if(root==NULL) return traversals;

    vector<int> pre, in, post ;
    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});
    
    while(!st.empty()) {
      auto it = st.top();
      st.pop();
      TreeNode* node = it.first;
      int num = it.second;
      
      //root left right (pre)
      if(num==1) {
        pre.push_back(node->data);
        it.second++; //increment from 1 to 2
        st.push(it);
        //push the left child of the node
        if(node->left != NULL) st.push({node->left, 1});
      }
      
      //left root right (in)
      else if(num==2) {
        in.push_back(node->data);
        it.second++; //increment from 2 to 3
        st.push(it);
        //push the right child of the node
        if(node->right !=NULL) st.push({node->right, 1});
      }
      
      //left right root (post)
      else { //num==3
        post.push_back(node->data);
      }
    }

    traversals.push_back(pre);
    traversals.push_back(in);
    traversals.push_back(post);
    return traversals;
  }
};

void printVec(vector<int>& v){
    for(auto it: v){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main() {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);   
  root->left->right = new TreeNode(5); 
  
  Solution obj;
  vector<vector<int>> traversals = obj.preInPostTraversal(root);
  
  vector<int> pre, in, post;
  pre = traversals[0];
  in = traversals[1];
  post = traversals[2];
  
  cout<<"preorder: ";
  printVec(pre);
  
  cout<<"inorder: ";
  printVec(in);

  cout<<"postorder: ";
  printVec(post);
  
//   Output:
//   preorder: 1 2 4 5 3 
//   inorder: 4 2 5 1 3 
//   postorder: 4 5 2 3 1 
  
  return 0;
}


