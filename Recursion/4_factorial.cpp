#include <bits/stdc++.h>
using namespace std;

int fact_N_nos_functional(int N){    //functional recursion  //TC:O(N) SC:O(N)
    if(N==1) return 1;
    return N * fact_N_nos_functional(N-1);
}

void fact_N_nos_parameterized(int N, int fact){   //parameterized recursion  //TC:O(N) SC:O(N)
    if(N==1){
        cout<<fact; 
        return;
    }
    fact_N_nos_parameterized(N-1, fact*N);
}


int main() {
    cout<<fact_N_nos_functional(5)<<endl;
    fact_N_nos_parameterized(5, 1);
    cout<<endl;
    return 0;
}
