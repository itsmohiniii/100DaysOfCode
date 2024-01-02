#include <bits/stdc++.h>
#include <typeinfo>
using namespace std;

//subsequence: contiguous or non-contiguous sequence, which follows the order
// no. of subsequences possible: 2^N

void print_subsequences(int index, vector<int>& sub, int arr[], int N){ //TC:O(2^N * N) SC:O(N) = depth of recursion tree
    if(index>=N){
        for(auto x:sub){ //TC: O(N)
            cout<<x<<" ";
        }
        // for (auto it = sub.begin(); it != sub.end(); it++) {
        //     cout << *it << endl;
        // }
        
        if(sub.size()==0){
            cout<<"{}";
        }
        cout<<endl;
        return;
    }
    
    //take or pick the particular index into the subsequence 
    sub.push_back(arr[index]);
    print_subsequences(index+1, sub, arr, N);
    
    //not pick ot not take condition : this element is not added to your subsequence
    sub.pop_back();
    print_subsequences(index+1, sub, arr, N);
}

int main() {
    int arr[]={3,1,2};
    int N=3;
    vector<int> sub;
    print_subsequences(0,sub, arr, N);
    return 0;
}
