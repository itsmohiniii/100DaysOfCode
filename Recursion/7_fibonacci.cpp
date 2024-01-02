#include <bits/stdc++.h>
using namespace std;

int fibonacci_iterative(int N){ //  TC:O(N) SC:O(N)
    int f[N+1];
    f[0]=0;
    f[1]=1;
    for(int i=2;i<=N;i++){
        f[i] = f[i-1] +f[i-2];
    }
    return f[N];
}

int fibonacci_recursive(int N){ //TC:O(2^N) exponential SC:O(N) = height of tree
    if(N<=1)
        return N;
    return fibonacci_recursive(N-1) + fibonacci_recursive(N-2);
}

int main() {
    cout<<fibonacci_iterative(6)<<endl;
    cout<<fibonacci_recursive(6)<<endl;
    
    return 0;
}
