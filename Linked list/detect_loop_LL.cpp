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

bool detectLoopLL_Brute (Node* head){   //TC: O(N*2*1) or O(N*2*logN)  SC:O(N)
    Node* temp = head;
    unordered_map<Node*, int> vis;  //hashing
    while(temp!=NULL){
        if(vis.find(temp) != vis.end()) return true;    //TC: O(1) or O(logN)
        vis[temp]=1;    //TC: O(1) or log(N)
        temp=temp->next;
    }
    return false;
}

bool detectLoopLL (Node* head){     //TC: O(N)  SC:O(1)
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) return true;
    }
    return false;
}

int main(){
    vector<int> arr = {4, 6, 5, 6, 4};
    Node* head = prepareLLfromArr(arr);
    printLL(head);
    
    cout<<endl<<"LL has a loop: "<< detectLoopLL_Brute(head);
    cout<<endl<<"LL has a loop: "<< detectLoopLL(head);
}
