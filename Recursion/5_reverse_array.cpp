#include <bits/stdc++.h>
using namespace std;

//arrays are called by reference, by default.
//reverse array using 2 ptrs
void reverse_arr(int arr[], int i, int j){  //TC:O(N/2) SC:O(N/2) 
    if(i>=j) return;
    swap(arr[i], arr[j]);
    reverse_arr(arr, i+1, j-1);
}

//reverse array using 1 ptr
void reverse_arr_1_pointer(int arr[], int N, int i){  //TC:O(N/2) SC:O(N/2) 
    if(i>=N/2) return;
    swap(arr[i], arr[N-i-1]);
    reverse_arr_1_pointer(arr,N, i+1);
}

//reverse array and return the reversed array
int* reverse_arr_return(int* arr, int i, int j){
    if(i>=j) return arr;
    swap(arr[i], arr[j]);
    return reverse_arr_return(arr, i+1, j-1);
}


//reverse vector
void reverse_vector(vector<int>& vec, int i, int j){    //TC:O(N/2) SC:O(N/2)
    if(i>=j) return;
    swap(vec[i], vec[j]);
    reverse_vector(vec, i+1, j-1);
}

int main() {
    int arr[] ={5,3,4,7,8};
    int N=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<N;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    reverse_arr_1_pointer(arr,N,0);
    // reverse_arr(arr,0,N-1);
    for(int i=0;i<N;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;
    
    
    vector<int> vec ={5,3,4,7,8,9};
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    reverse_vector(vec,0,vec.size()-1);
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl<<endl;

    
    int arr[]= {1, 2, 3, 4, 5};
    int N=sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<N;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int * ans = reverse_arr_return(arr, 0, N-1);
    for(int i=0; i<N;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}
