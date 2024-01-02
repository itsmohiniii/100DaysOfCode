#include <bits/stdc++.h>
using namespace std;

//using 2 pointers
bool check_palindrome(string str, int i, int j){  //TC:O(N/2) SC:O(N/2) 
    if(i>=j) {
        return true;
    }
    if(str[i]!=str[j]) return false;
    return check_palindrome(str, i+1, j-1);
}

//using 1 pointer
bool check_palindrome_1_ptr(string str, int N, int i){  //TC:O(N/2) SC:O(N/2) 
    if(i>=N/2) {
        return true;
    }
    if(str[i]!=str[N-i-1]) return false;
    return check_palindrome_1_ptr(str, N, i+1);
}

int main() {
    string str="madam";
    cout<<check_palindrome(str, 0, str.length()-1)<<endl;
    cout<<check_palindrome_1_ptr(str, str.length(), 0)<<endl;
    
    return 0;
}
