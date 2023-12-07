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

Node* findNthNode(Node* temp, int N){// worst case TC: O(N)
    int cnt=1;
    while(temp!=NULL){
        if(cnt==N) return temp;
        cnt++;
        temp=temp->next;
    }
    return NULL;
    
}

Node* rotateLL(Node* head, int k){  //TC: O(2N) SC:O(1)
    if(head==NULL || k==0) return head;
    Node* tail = head;
    int len =1 ;
    while(tail->next!=NULL){    //TC: O(N)
     tail=tail->next;
     len++;
    }
    if(k%len==0) return head;
    k=k%len;
    tail->next= head; 
    Node* newLastNode = findNthNode(head, len-k);   //worst case: k=1
    head=newLastNode->next;
    newLastNode->next=NULL;
    return head;
}
    

int main(){
    vector<int> arr = {4, 6, 5, 7};
    Node* head = prepareLLfromArr(arr);
    printLL(head);
    
    head = rotateLL(head, 2);
    cout<<endl<<"LL after rotating: ";
    printLL(head);
}
