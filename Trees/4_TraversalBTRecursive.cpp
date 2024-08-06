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
// Print Left Right
void preOrder(Node* root) {
  if(root==nullptr) { //base case: leaf node
    return;
  }
  cout<<root->data<<" ";
  preOrder(root->left);
  preOrder(root->right);
}

//Left Print Right
void inOrder(Node* root) {
  if(root==nullptr) {
    return;
  }
  inOrder(root->left);
  cout<<root->data<<" ";
  inOrder(root->right);
}

int main() {
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);   
  root->left->right = new Node(5);   
  
  preOrder(root); //Output: 1 2 4 5 3
  cout<<endl;
  
  inOrder(root); //Output: 4 2 5 1 3 
  cout<<endl;
  
  return 0;
}
