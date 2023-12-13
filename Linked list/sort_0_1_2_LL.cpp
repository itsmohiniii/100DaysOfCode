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

// Brute force approach: (data-replacement)
// traverse the LL and store the count of 0s, 1s, and 2s in 3 different variables. Traverse through the LL again and replace the zeros first, then ones and lastly twos, simultaneously reducing the count of the variables.
// TC: O(2N) SC:O(1) 'two-pass solution'

Node* sort_0_1_2_LL(Node* head){ //TC:O(N) SC:O(1) 'one-pass solution'
    if(head == NULL || head->next == NULL) return head; 
    
    Node* temp = head;
    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);
    Node* zero = zeroHead;
    Node* one = oneHead;
    Node* two = twoHead;
    
    while(temp!=NULL){
        if(temp->data==0){
            zero->next = temp;
            zero= temp;
        }
        else if(temp->data==1){
            one->next = temp;
            one= temp;
        }
        else {
            two->next = temp;
            two= temp;
        }
        temp=temp->next;
    }
    
    zero->next = oneHead->next ? oneHead->next : twoHead->next;
    one->next = twoHead->next;
    two->next = NULL;
    
    Node* newHead = zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return newHead;
}

int main(){
    vector<int> arr = {0,0,1,0,2,1,2,0,0,1};
    Node* head = createLLfromArr(arr);
    printLL(head);
    
    Node* newHead= sort_0_1_2_LL(head);
    printLL(newHead);
    
}
