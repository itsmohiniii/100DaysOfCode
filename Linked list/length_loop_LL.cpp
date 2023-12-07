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


int lengthLoopLL_Brute (Node* head){    //TC: O(N*2*1) or O(N*2*logN)  SC:O(N)
    Node* temp = head;
    int timer = 1;
    unordered_map<Node*, int> len;
    while(temp!=NULL){
        len[temp]=timer;    //TC: O(1) or log(N)
        timer++;
        temp=temp->next;
        if(len.find(temp) != len.end()) return timer-len[temp];     //TC: O(1) or O(logN)
    }
    return 0;
}

int calcLengthLoopLL(Node* slow, Node* fast){
    slow=slow->next;
    int cnt=1;
    while(slow!=fast){
        cnt++;
        slow=slow->next;
    }
    return cnt;
}

int lengthLoopLL (Node* head){  //SC:O(1), TC: O(N)?? as we can break instead of calling calcLengthLoopLL() and write it outside the loop
    Node* slow= head; 
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow= slow->next;
        fast =fast ->next->next;
        if(slow == fast) return calcLengthLoopLL(slow, fast);
    }
    return 0;
}
    

int main(){
    vector<int> arr = {4, 6, 5, 6, 4};
    Node* head = prepareLLfromArr(arr);
    printLL(head);
    
    cout<<"LL has a loop of length: "<< lengthLoopLL_Brute(head);
    cout<<endl<<"LL has a loop of length: "<< lengthLoopLL(head);
}
