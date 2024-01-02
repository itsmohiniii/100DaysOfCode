#include <bits/stdc++.h>
#include <typeinfo>
using namespace std;

//subsequence: contiguous or non-contiguous sequence, which follows the order
// no. of subsequences possible: 2^N

void print_sumK_subsequences(int index, vector<int>& sub, int arr[], int N, int K,int sum){ //TC:O(2^N * N) SC:O(N) = depth of recursion tree
    if(index>=N){
        if(sum==K){
            for(auto x:sub){ //TC: O(N)
                cout<<x<<" ";
            }
            cout<<endl;
        }
        return;
    }
    
    //take or pick the particular index into the subsequence 
    sub.push_back(arr[index]);
    print_sumK_subsequences(index+1, sub, arr, N, K, arr[index]+sum);
    
    //not pick ot not take condition : this element is not added to your subsequence
    sub.pop_back();
    print_sumK_subsequences(index+1, sub, arr, N, K, sum);
}

int main() {
    int arr[]={1,2, 1};
    int N=3;
    int K=2;
    vector<int> sub;
    print_sumK_subsequences(0,sub, arr, N, K, 0);
    return 0;
}
