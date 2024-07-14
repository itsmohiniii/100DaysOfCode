// Topological Sorting (DFS)

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
      st.push(node);
    }

  public:
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
