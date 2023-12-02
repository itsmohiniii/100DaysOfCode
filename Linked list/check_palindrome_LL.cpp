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

Node* reverseLLIterative(Node* head){
    if(head== NULL || head->next==NULL ) return head;
    Node* prev = NULL;
    Node* front = head;
    while(front!=NULL){
        Node* temp = front->next; 
        front-> next = prev;
        prev = front;
        front = temp;
    }
    return prev;
}

Node* reverseLLRecursive(Node* head){
    if(head==NULL || head->next== NULL){
        return head;
    }
    Node* newHead = reverseLLRecursive(head->next);
    Node* front = head->next;
    front->next = head;
    head->next= NULL;
    return newHead;
}

// Brute force approach (checkPalindrome LL): 
// push all items of LL into stack, start comparing from top and of stack and beginning of LL to check for palindrome 
// TC: O(2N) SC: O(N)

bool checkPalindromeLL(Node* head){     //TC: O(2N) SC: O(1)
    Node* slow = head;  //step1: find middle Node (hare-tortoise algorithm) TC: O(N/2)
    Node* fast = head;     
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* newHead = reverseLLRecursive(slow->next); //step2: reverse second half of LL TC: O(N/2)
    Node* second = newHead;
    Node* first = head;
    while(second!=NULL){ //step3: compare values TC: O(N/2)
        if(first->data!=second->data){
            slow->next = reverseLLRecursive(newHead); //step4: reverse back the LL before returning TC: O(N/2)
            return false;
        }
        first=first->next;
        second=second->next;
    }
    slow->next = reverseLLIterative(newHead);
    return true;
}

int main(){
    vector<int> arr = {4, 6, 5, 6, 4};
    Node* head = prepareLLfromArr(arr);
    printLL(head);
    
    // Node* reverseHead = reverseLLIterative(head);
    // cout<<endl<<"reversed LL is ";
    // printLL(reverseHead);
    
    // Node* reverseHeadRecursive = reverseLLRecursive(head);
    // cout<<endl<<"reversed LL is ";
    // printLL(reverseHeadRecursive);
    
    cout<<endl<<"Palindrome: "<< checkPalindromeLL(head);
    
}
