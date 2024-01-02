#include <bits/stdc++.h>
using namespace std;

void print_1_to_N (int i, int N){
    if(i>N) return;
    cout<<i<<" ";
    print_1_to_N(i+1, N);
}

void print_1_to_N_backtracking (int N){
    if(N==0) return;
    print_1_to_N_backtracking(N-1);
    cout<<N<<" ";
}

int main() {
    print_1_to_N(1,5);
    cout<<endl;
    print_1_to_N_backtracking(6);
    cout<<endl;
    return 0;
}
