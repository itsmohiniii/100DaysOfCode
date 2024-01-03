#include<bits/stdc++.h>
using namespace std;

bool print_sumK_subsequence_1(int index, vector<int>& sub, int arr[], int N, int sum, int K){   //TC??:O(2^N + N),  SC:O(N)
    if(index>=N){
        if(sum==K){
            for(auto x:sub) //TC:O(N)
                cout<<x<<" ";
            cout<<endl;
            return true; //condition satisfied 
        }
        return false; //condition not satisfied
    }
    
    sub.push_back(arr[index]);
    if(print_sumK_subsequence_1(index+1, sub, arr, N, arr[index]+sum, K)==true) return true; //avoid future recursion calls if you get true
    
    sub.pop_back();
    if(print_sumK_subsequence_1(index+1, sub, arr, N, sum, K)==true) return true; //avoid future recursion calls if you get true
    
    return false;
}

int main(){
    int arr[]={1,2,1};
    int N=3;
    int K=2;
    vector<int> sub;
    print_sumK_subsequence_1(0,sub, arr, N, 0, K);
    cout<<endl;
}
