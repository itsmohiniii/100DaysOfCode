//Represent Binary Tree in C++

#include<bits/stdc++.h>
using namespace std;

class Node {
  public:    
  int data;
  Node* left;
  Node* right;
  Node(int val) { //constructor 
    data = val;
    left = nullptr;
    right = NULL;
  }
};

int main() {
  //dynamic memory allocation
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->right = new Node(4);   
  
  return 0;
}

