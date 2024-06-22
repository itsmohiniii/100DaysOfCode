#include <bits/stdc++.h>
using namespace std;

class Solution {
 public: 
  vector<int> traverse_graph_bfs(int N, vector<int> adj[ ]) {
  int vis[N+1] = {0}; //1-based indexing
  vis[1]=1;
  queue<int> q;
  q.push(1);
  vector<int> bfs;
  while(!q.empty()) {
    int node = q.front();
    bfs.push_back(node);
    q.pop();
    for(auto it: adj[node]) {
     if(vis[it]==0) {
      q.push(it);
      vis[it]=1;
     }
    } 
  }
  return bfs;
  }
};


int main() {
    int n, m;
    cin>>n>>m;
    vector<int> adj[n+1]; //1-based indexing
    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
  
    Solution obj;
    vector<int> res = obj.traverse_graph_bfs(n,adj);
    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }
    return 0;
}
