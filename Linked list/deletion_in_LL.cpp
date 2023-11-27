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
};

Node* convertArrToLL(vector<int> & arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void printLL(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

Node* deleteHead(Node* head){  //O(1)
    if(head == NULL) return head;
    Node* temp = head;
    head = head-> next;
    delete temp;
    return head;
}

Node* deleteTail(Node* head){  //O(N)
    if(head == NULL) return NULL; 
    if(head->next== NULL){
        delete head;
        return NULL;
    }
    Node* prev = head;
    while(prev->next->next != NULL){
        prev=prev->next;
    }
    delete prev->next;
    prev-> next = nullptr;
    return head;
}

Node* deleteKth(Node* head, int k){    //worst case O(N), Best case O(1), avg case O(N/2)
    if(head == NULL) return NULL; 
    if(k==1){
        Node* temp = head;
        head = head-> next;
        delete temp;
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(cnt== k){
            prev->next = prev-> next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp=temp->next;
    }
    
    return head;
}

Node* deleteEl(Node* head, int el){    //worst case O(N), Best case O(1), avg case O(N/2)
    if(head == NULL) return NULL; 
    if(head->data==el){
        Node* temp = head;
        head = head-> next;
        delete temp;
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp!=NULL){
        if(temp->data==el){
            prev->next = prev-> next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp=temp->next;
    }
    
    return head;
}

int main() {
    vector<int> arr = {4, 7, 8, 10};
    Node* head = convertArrToLL(arr);
    printLL(head);
    // head = deleteHead(head);
    // cout<<endl<<"after deleting head:";
    // printLL(head);
    
    // head = deleteTail(head);
    // cout<<endl<<"after deleting tail:";
    // printLL(head);
    
    // head = deleteKth(head, 5);
    // cout<<endl<<"after deleting kth element:";
    // printLL(head);
    
    // head = deleteEl(head,8);
    // cout<<endl<<"after deleting element with value:";
    // printLL(head);
    
}
