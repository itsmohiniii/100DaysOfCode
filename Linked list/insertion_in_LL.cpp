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

Node* insertHead(Node* head, int val){   //O(1)
    return new Node(val, head);
}

Node* insertTail(Node* head, int val){   //O(N)
    Node * temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* newNode = new Node(val, nullptr);
    temp->next=newNode;
    return head;
}

Node* insertKthPosition(Node* head, int val, int k){  //worst case O(N) best case O(1) avg case O(N/2)
    if(k==1){
        return new Node(val, head);
    }
    if(head==NULL){ 
        // if(k==1){
        //     return new Node(val);
        // }
        return NULL;
    }
    Node* temp = head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(cnt==k-1){
            Node* newNode = new Node(val, temp->next);
            temp->next = newNode;
            return head;
        }
        temp=temp->next;
    }
    return head;
    
}

Node* insertBeforeElement(Node* head, int val, int el){  //worst case O(N) best case O(1) avg case O(N/2)
    if(head==NULL) return NULL;
    if(head->data==el){
        return new Node(val, head);
    }
    Node* temp = head;
    while(temp!=NULL){
        if(temp->next->data==el){
            Node* newNode = new Node(val, temp->next);
            temp->next = newNode;
            return head;
        }
        temp=temp->next;
    }
    return head;
    
}

int main() {
    vector<int> arr = {5, 8, 10, 14
    // vector<int> arr = {};
    Node* head = convertArrToLL(arr);
    printLL(head);
    
    // head = insertHead(head, 8);
    // cout<<endl<<"after deleting head:";
    // printLL(head);
    
    // head = insertTail(head, 78);
    // cout<<endl<<"after deleting tail:";
    // printLL(head);
    
    // head = insertKthPosition(head, 78, 1);
    // cout<<endl<<"after inserting at Kth position:";
    // printLL(head);
    
    // head = insertBeforeElement(head, 78, 10);
    // cout<<endl<<"after inserting before element:";
    // printLL(head);
    
}
