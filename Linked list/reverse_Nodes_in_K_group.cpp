#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        data=d;
        next = nullptr;
    }
    Node(int d, Node* n){
        data=d;
        next = n;
    }
};

Node* createLLfromArr(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
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
    cout<<endl;
}

Node* reverseLL(Node* head){
    Node* prev = NULL;
    Node* temp = head;
    while(temp!=NULL){
        Node* front = temp ->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}

Node* findKthNode(Node* temp, int k){
    k-=1;
    while(temp!=NULL && k>0){
        k--;
        temp=temp->next;
    }
    return temp;
}

Node* reverseNodesInKGroupSize(Node* head, int k){ //TC: O(2N) SC:O(1)
    Node* temp = head;
    Node* nextNode=NULL;
    Node* prevNode = NULL;
    
    while(temp!=NULL){
        Node* kthNode = findKthNode(temp, k);  // total TC (all iterations):O(N)
        if(kthNode==NULL){
            if(prevNode) prevNode->next=temp;
            break;
        }
        nextNode = kthNode->next;
        kthNode->next = NULL;
        Node* newHead = reverseLL(temp);  // total TC (all iterations):O(N)
        if(temp==head){
            head=kthNode;
        }
        else{
            prevNode->next = kthNode;
        }
        prevNode= temp;
        temp = nextNode;
    }
    return head;
}

int main(){
    vector<int> arr = {3, 7, 9, 10, 12};
    Node* head = createLLfromArr(arr);
    printLL(head);
    
    // Node* reversedHead = reverseLL(head);
    // printLL(reversedHead);
    
    Node* newHead= reverseNodesInKGroupSize(head, 2);
    printLL(newHead);
}
