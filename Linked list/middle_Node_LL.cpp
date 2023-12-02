#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* prepareLLfromArr(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next= temp;
        mover= temp;
    }
    return head;
}

void printLL(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

// brute force approach (middle of LL): find out N, no. of nodes by traversing, then traverse till (N/2)+1 element to reach the middle node 
// TC: O(N+N/2) SC: O(1)

Node* middleofLL(Node* head){  // TC: 0(N/2) SC: 0(1)
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

int main(){
    vector<int> arr = {4, 6, 5, 6, 4};
    Node* head = prepareLLfromArr(arr);
    printLL(head);
    
    Node* middleNode = middleofLL(head);
    cout<<endl<<"Middle element is " << middleNode->data;
}
