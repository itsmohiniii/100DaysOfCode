#include <bits/stdc++.h>
using namespace std;

class Solution {
 public: 
  //TC: O(N) + O(2E) 
  //SC: O(3N)~O(N) queue,vis array,bfs vector
  vector<int> traverse_graph_bfs(int N, vector<int> adj[]) {
  int vis[N+1] = {0}; //1-based indexing
  vis[1]=1;
  queue<int> q;
  q.push(1);
  vector<int> bfs;
   
  //TC: O(N)
  while(!q.empty()) {
    int node = q.front();
    q.pop();
    bfs.push_back(node);
   
    //TC: runs for all degrees (neighbours) for a node = For all nodes, runs for total degree of the graph = O(2E)
    for(auto it: adj[node]) {
     if(!vis[it]) { //vis[it]==0
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

Sample Input : 
9 9
1 2
1 6
2 3
2 4
6 7
6 9
4 5
7 8
5 8

Sample Output: 
1 2 6 3 4 7 9 5 8 

