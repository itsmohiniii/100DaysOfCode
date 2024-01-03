#include<bits/stdc++.h>
using namespace std;

int print_sumK_subsequences_count(int index, int arr[], int N, int sum, int K){  //TC:O(2^N) worst case,  SC:O(N)
    //condition not satisfied
    //strictly done if array contains positives only
    if(sum>K) return 0;
    
    if(index>=N){
        if(sum==K)  return 1; //condition satisfies 
        return 0; //condition not satisfied
    }
    
    int l = print_sumK_subsequences_count(index+1, arr, N, arr[index]+sum, K);
    int r = print_sumK_subsequences_count(index+1, arr, N, sum, K);
    
    return l+r; //add all recursive function calls and return 
}

int main(){
    int arr[]={1,2,1};
    int N=3;
    int K=2;
    cout<<print_sumK_subsequences_count(0,arr, N, 0, K)<<endl;
}
