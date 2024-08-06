//Pre-order Traversal in Binary Tree
//Root Left Right

#include<bits/stdc++.h>
using namespace std;

class Node {
  public:    
  int data;
  Node* left;
  Node* right;
  Node(int val) { 
    data = val;
    left = right = nullptr;
  }
};

//TC: O(N) where n->#nodes as each node of the binary tree is visited exactly once.
//SC: O(N) for auxiliary stack space in recursion -> WC: height of tree = N (if skewed tree)
void preOrder(Node* root) {
  if(root==nullptr) { //base case: leaf node
    return;
  }
  cout<<root->data<<" ";
  preOrder(root->left);
  preOrder(root->right);
}

int main() {
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);   
  root->left->right = new Node(5);   
  
  preOrder(root); //Output: 1 2 4 5 3
  
  return 0;
}


