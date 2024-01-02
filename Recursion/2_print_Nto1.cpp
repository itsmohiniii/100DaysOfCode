#include <bits/stdc++.h>
using namespace std;

void print_N_to_1 (int N){    //TC:O(N) SC:O(N)
    if(N==0) return;
    cout<<N<<" ";
    print_N_to_1(N-1);
}

void print_N_to_1_backtracking (int i, int N){    //TC:O(N) SC:O(N)
    if(i>N) return;
    print_N_to_1_backtracking(i+1, N);
    cout<<i<<" ";
    
}

int main() {
    print_N_to_1(7);
    cout<<endl;
    print_N_to_1_backtracking(1, 8);
    cout<<endl;
    return 0;
}
