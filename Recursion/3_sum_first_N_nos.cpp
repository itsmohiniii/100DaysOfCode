#include <bits/stdc++.h>
using namespace std;

int sum_N_nos_functional(int N){    //functional recursion  //TC:O(N) SC:O(N)
    if(N==0) return 0;
    return N + sum_N_nos_functional(N-1);
}

void sum_N_nos_parameterized(int N, int sum){   //parameterized recursion  //TC:O(N) SC:O(N)
    if(N==0){
        cout<<sum; 
        return;
    }
    sum_N_nos_parameterized(N-1, sum+N);
}


int main() {
    cout<<sum_N_nos_functional(5)<<endl;
    sum_N_nos_parameterized(5, 0);
    cout<<endl;
    return 0;
}
