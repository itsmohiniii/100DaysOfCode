#include <bits/stdc++.h>
using namespace std;

// Memoization (recursion way - top down) 
// TC:O(N) SC:O(N)+O(N) recursion stack space + dp array
int fib(int n, vector<int> &dp){  //call by reference
    if(n<=1) return n;
    if(dp[n] != -1) return dp[n];
    return dp[n] = fib(n-1, dp) +fib(n-2, dp);
}

int main() {
    int n = 5;
    
    vector<int> dp(n+1, -1);
    // if array is used instead of vector
    // int dp[n+1];
    // memset(dp, -1, sizeof dp);
    
    cout<<fib(n, dp);
    
    return 0;
}
