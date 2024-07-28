// Fibonacci no. : 0 1 1 2 3 5 8 13 21... 
// 0-based indexing
// Recurrence relation: f(n) = f(n-1) + f(n-2)

//3 steps for converting a recursive soltion to DP solution (using Memoization and using Tabulation) 

#include <bits/stdc++.h>
using namespace std;

// Memoization (recursion way - top down) 
// TC:O(N) as it takes linear time bcuz for every value of n, one call is made which is computed 
// and all other calls are for previously stored values which take O(1) constant time.
// SC:O(N)+O(N) recursion stack space + dp array
int fib_Memoization(int n, vector<int> &dp){  //call by reference
    if(n<=1) return n;
    //Step3: check whether the subproblem has been previouly solved    
    if(dp[n] != -1) return dp[n];
    //Step2: store the answer to subproblem in dp array
    return dp[n] = fib_Memoization(n-1, dp) + fib_Memoization(n-2, dp);
}

// Tabulation (bottom up) 
// TC:O(N) 
// SC:O(N) for dp array
int fib_Tabulation(int n){
    //Step1: declare a dp array or vector 
    int dp[n+1];
    //Step2: initialise Base case values
    dp[0] = 0;
    dp[1] = 1;
    //Step3: recursion relation : f(n) = f(n-1) + f(n-2). Replace f by dp.
    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

// Space optimisation (Tabulation) 
// we see that for any i, we do need only the last two values in the array. So is there a need to maintain a whole array for it? No.
// TC:O(N) 
// SC:O(1) as no need of dp array
int fib_SO(int n){
    //Step1: initialise Base case values
    int prev2 = 0;
    int prev = 1;
    //Step2: 
    for(int i=2; i<=n; i++) {
        int curi = prev + prev2;
        prev2 = prev;
        prev = curi;
    }
    return prev;
}

int main() {
    int n = 5;

    //Step1: declare a dp array or vector (size -> maximum no. of subproblems)
    vector<int> dp(n+1, -1); //size=n+1 (index  from 0 to n)
    // if array is used instead of vector
    // int dp[n+1];
    // memset(dp, -1, sizeof dp);
    cout<<fib_Memoization(n, dp)<<endl; //Ouput: 5
    
    cout<<fib_Tabulation(n)<<endl; //Ouput: 5
    
    cout<<fib_SO(n)<<endl; //Ouput: 5
    
    return 0;
}
