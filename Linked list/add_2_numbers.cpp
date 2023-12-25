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

Node* add_2_numbers(Node* head1, Node* head2){ //TC:O(max(N1,N2)),  SC:O(max(N1,N2)) this space can't be optimised bcuz it is used to store the new LL contaning sum.
    //N1-> length of LL1, N2-> length of LL2
    Node* temp1= head1;
    Node* temp2 = head2;
    int carry = 0;
    
    Node* dummyNode = new Node(-1);  //make a 'dummyNode' whenever you to make or return a new LL (for code simplification)
    Node* curr = dummyNode;
    
    while(temp1!=NULL || temp2!=NULL){
        int sum = carry;
        if(temp1) sum+=temp1->data;
        if(temp2) sum+=temp2->data;
        
        Node* newNode = new Node(sum%10);
        carry = sum/10;
        curr->next = newNode;
        curr = curr->next;
        
        if(temp1) temp1=temp1->next;
        if(temp2) temp2=temp2->next;
    }
    
    if(carry){
        Node* newHead = new Node(carry);
        curr->next = newHead;
    }
    return dummyNode->next;
}

int main() {
    vector<int> arr1 = {4, 9, 9};
    Node* head1 = createLLfromArr(arr1);
    printLL(head1);
    cout<<endl;
    
    vector<int> arr2 = {4, 9, 9, 9};
    Node* head2 = createLLfromArr(arr2);
    printLL(head2);
    cout<<endl;
    
    Node* newHead = add_2_numbers(head1, head2);
    printLL(newHead);
}
