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

Node* createLLfromArr(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void printLL(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

//iterative approach:
Node* reverseLL(Node* head){
    Node* prev = NULL;
    Node* temp = head;
    
    while(temp!=NULL){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

Node* add_1_to_LL(Node* head){  // TC:O(3N)  SC:O(1)
    Node* newHead = reverseLL(head); //O(N)
    
    Node* temp = newHead;
    int carry = 1;
    while(temp!=NULL){  //O(N)
        temp->data = temp->data + carry;
        if(temp->data<10){
            carry =0;
            break;
        } else{
            temp->data = 0;
            carry =1;
        }
        temp=temp->next;
    }
    
    newHead = reverseLL(newHead); //O(N)
    if(carry==1){
        Node* newNode = new Node(1);
        newNode->next = newHead;
        return newNode;
    }
    return newHead;
}

// recursive approach: without reversing the LL (using recursion and backtracking)
int helper(Node* temp){
    if(temp==NULL)  return 1;
    
    int carry = helper(temp->next);
    
    temp->data = temp->data + carry;
    if(temp->data < 10) return 0;
    temp->data=0;
    return 1;
}

Node* add_1_to_LL_backtracking(Node* head){  // TC:O(N), SC:O(N) due to recursive stack space
    int carry = helper(head);
    if(carry==1){
        Node* newHead = new Node(1);
        newHead->next = head;
        return newHead;
    }
    return head;
}

int main() {
    vector<int> arr = {9, 9, 9, 9};
    Node* head = createLLfromArr(arr);
    printLL(head);
    cout<<endl;
    
    // Node* newHead = add_1_to_LL(head);
    // printLL(newHead);
    
    Node* newHead = add_1_to_LL_backtracking(head);
    printLL(newHead);
}
