#include<bits/stdc++.h>
using namespace std;

void combination_sum(int index, vector<int>& sub, int arr[], int N, int target){    //TC: O(2^T *k) exponential, SC:O(k*X) where, T->target, k->average length of every combination generated, X->no. of combinations
    if(target==0){   
        for(auto x:sub){
            cout<<x<<" ";
        }
        cout<<endl;
        return;
    }
    if(index>=N){
        // if(target==0 ){
        //     for(auto x:sub){
        //         cout<<x<<" ";
        //     }
        //     cout<<endl;
        // }
        return;
    }
    if(arr[index]<=target){
    sub.push_back(arr[index]);
    
        combination_sum(index,sub,arr,N,target-arr[index]);
    
    sub.pop_back();
    }
    combination_sum(index+1,sub,arr,N,target);
    
}

int main(){
    int arr[]={2,3,6,7};
    int N=4;
    int target=7;
    vector<int> sub;
    combination_sum(0, sub, arr, N, target);
    cout<<endl;
}
