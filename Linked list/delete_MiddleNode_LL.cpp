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

// brute force approach (delete middleNode of LL): find out N, no. of nodes by traversing, then traverse till (N/2)th element to reach the node before the middleNode. 
// TC: O(N+N/2) SC: O(1) '2-pass solution'

Node* deleteMiddleNodeLL(Node* head){   //TC: O(N/2)  SC:O(1) 'one-pass solution'
    if(head== NULL || head->next== NULL) return NULL;
    Node* slow = head;
    Node* fast = head;
    fast = fast->next->next;    //find the node just before the middleNode
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast = fast->next->next;
    }
    Node* middleNode = slow->next;
    slow->next = slow->next->next;
    delete middleNode;
    return head;
}
    

int main(){
    vector<int> arr = {4, 6, 5, 4};
    Node* head = prepareLLfromArr(arr);
    printLL(head);
    
    head = deleteMiddleNodeLL(head);
    cout<<endl<<"LL after deleting middle node: ";
    printLL(head);
}
