// Topological Sorting (DFS)
// Intuition: when we complete the dfs for a node, we put it in the stack 
// and every dfs call (for all neighbours of that node) would be stacked below
// so when we start popping out of the stack, we get the linear ordering

#include<bits/stdc++.h>
using namespace std;

class Solution {
  private: 
    void dfs(int node, vector<int> adj[], int vis[], stack<int>& st) {
      vis[node]=1;
      for(auto it: adj[node]) {
        if(!vis[it]) {
          dfs(it, adj, vis, st);
        }
      }
      st.push(node); //when the dfs call for a node is over, push it into the stack
    }

  public:
    //SC: O(N)+O(N)+O(N) for vis array, for recursion stack space, for st stack
    //TC: O(N)+O(N+E) for outer For loop, for overall dfs directed graph
    vector<int> topoSort(int N, vector<int> adj[]) {
      int vis[N]={0};
      stack<int> st;
      for(int i=0;i<N;i++) {
        if(!vis[i]) {
          dfs(i,adj,vis,st);
        }
      }
      vector<int> res;
      while(!st.empty()) {
        res.push_back(st.top());
        st.pop();
      }
      return res;
    }  
};

int main() {
  int N=4;
  vector<int> adj[] ={{},{0},{0},{0}};  //Output: [3,2,1,0]
  Solution obj;
  vector<int> res = obj.topoSort(N, adj);
  for(int i=0;i<res.size();i++){
    cout<<res[i]<<" ";
  }
}
