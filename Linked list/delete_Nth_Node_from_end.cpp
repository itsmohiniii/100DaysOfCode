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

Node* removeNthNodeFromEnd_BruteForce(Node* head, int N){ // TC: O(2len), SC: O(1)
    Node* temp = head;
    int cnt =0;
    while(temp!=NULL){  //TC:O(len)
        cnt++;
        temp=temp->next;
    }
    if(cnt==N){
        Node* newHead = head->next;
        free(head);
        return newHead;
    } 
    int k = cnt-N;
    temp = head;
    while(temp!=NULL){  //TC: O(len-N), worst cast TC: O(len) if N=1
        k--;
        if(k==0){
            Node* delNode = temp->next;
            temp->next = temp->next->next;
            free(delNode);
            break;
        }
        temp=temp->next;
    }
    return head;
}

Node* removeNthNodeFromEnd(Node* head, int N){  //TC: O(len) bcuz fast ptr traverses the length of LL in total, SC: O(1)
    Node* fast = head;
    Node* slow = head;
    for(int i=1; i<=N; i++){
        fast=fast->next;
    }
    if(fast==NULL){     //if N = length of LL
        Node* newHead = head->next;
        delete head;
        return newHead;
    }
    while(fast->next!=NULL){
        slow=slow->next;
        fast=fast->next;
    }
    Node* delNode =slow->next;
    slow->next=slow->next->next;
    delete delNode;
    return head;
}

int main(){
    vector<int> arr = {3, 7, 9, 10, 12};
    Node* head = createLLfromArr(arr);
    printLL(head);
    
    Node* newHead= removeNthNodeFromEnd(head, 2);
    printLL(newHead);
    
    Node* newHead= removeNthNodeFromEnd_BruteForce(head, 3);
    printLL(newHead);
    
}
