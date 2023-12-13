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
// traverse the LL by 2 steps and store the odd vales in the array. Traverse the LL again by 2 steps and store the even vales in the same array. Iterate through the LL and array simultaneously to rpelace the values in LL.
// TC: O(N/2 + N/2 + N) SC:O(1) 

Node* arrange_odd_even_LL(Node* head){ //TC:O(N) SC:O(1) 
    if(head == NULL || head->next == NULL) return head;
    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = head->next;
    
    while(even!=NULL && even->next!=NULL){ //even will always be ahead of odd   // TC: O(N/2)*2 bcuz odd and even both are getting updated in a single loop
        odd->next = odd->next->next;
        even->next = even->next->next;
        
        odd= odd->next;
        even=even->next;
    }
    odd->next=evenHead;
    return head;
}

int main(){
    vector<int> arr = {3, 4, 5, 7, 9, 8};
    Node* head = createLLfromArr(arr);
    printLL(head);
    
    Node* newHead= arrange_odd_even_LL(head);
    printLL(newHead);
    
}
