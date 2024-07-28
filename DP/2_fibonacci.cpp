// Fibonacci no. : 0 1 1 2 3 5 8 13 21... 
// 0-based indexing
// Recurrence relation: f(n) = f(n-1) + f(n-2)

//3 steps for converting a recursive soltion to DP solution (using Memoization) 

#include <bits/stdc++.h>
using namespace std;

// Memoization (recursion way - top down) 
// TC:O(N) as it takes linear time bcuz for every value of n, one call is made and all other calls are for prviously stored values which take O(1) constant time.
// SC:O(N)+O(N) recursion stack space + dp array
int fib(int n, vector<int> &dp){  //call by reference
    if(n<=1) return n;
    //Step3: check whether the subproblem has been previouly solved    
    if(dp[n] != -1) return dp[n];
    //Step2: store the answer to subproblem in dp array
    return dp[n] = fib(n-1, dp) +fib(n-2, dp);
}

int main() {
    int n = 5;

    //Step1: declare a dp array or vector (size -> maximum no. of subproblems)
    vector<int> dp(n+1, -1); //size=n+1 (index  from 0 to n)
    // if array is used instead of vector
    // int dp[n+1];
    // memset(dp, -1, sizeof dp);
    
    cout<<fib(n, dp);
    
    return 0;
}
