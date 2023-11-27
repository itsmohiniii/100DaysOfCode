#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        data = d;
        next = nullptr;
    }
    Node(int d, Node* n){
        data = d;
        next = n;
    }
};

Node* convertArrToLL(vector<int> & arr){ //O(N)
    if(arr.size()==0) return NULL;
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void printLL(Node* head){ //O(N)
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

// reverse LL (brute force approach): store data of LL in stack and then start traversing the LL and change data of LL with the top of stack
// TC: O(2N), SC: O(N)

Node* reverseLLIterative(Node* head){ //TC=O(N) SC=O(1)
    Node* temp = head;
    Node* prev = NULL;
    while(temp!=NULL){
        Node* front = temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}

Node* reverseLLRecursive(Node* head){ //TC=O(N) SC=O(N)
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* newHead = reverseLLRecursive(head->next);
    Node* front = head->next;
    front->next=head;
    head->next=NULL;
    
    return newHead;
}



int main() {
    vector<int> arr = {5, 8, 10, 14};
    // vector<int> arr = {};
    Node* head = convertArrToLL(arr);
    printLL(head);
    
    // head = reverseLLIterative(head);
    // cout<<endl<<"after reversal (iterative):";
    // printLL(head);
    
    // head = reverseLLRecursive(head);
    // cout<<endl<<"after reversal (recursive):";
    // printLL(head);
    
    
}
