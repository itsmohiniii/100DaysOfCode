//Detect a cycle in Directed Graph (using DFS) 
// Intuition: On the same path, node has to be visited again.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  private: 
    bool dfs(int node, vector<int> adj[], int vis[], int pathvis[]) {
      vis[node]=1;
      pathvis[node]=1;
      
      for(auto it: adj[node]) {
        //if the node is not visited
        if(!vis[it]) {
          if(dfs(it,adj,vis, pathvis)) return true;
        }
        //if the node has been previously visited
        // and also visited on the same path
        else if(pathvis[it]==1) { //vis[it]=1
          return true;
        }
      }
      
      pathvis[node]=0;
      return false;
    }

  public: 
    //SC: O(N)+O(N)+O(N) for vis array, for pathvis array, for recursion stack space
    //Space optimisation : O(N)+O(N) for vis array, for recursion stack space (How? mark vis as 1 and to mark pathvis, mark vis as 2)
    
    //TC: O(N)+O(N+E) for outer For loop, for overall dfs directed graph
    bool isCyclic(int N, vector<int> adj []) {
      int vis[N]={0}; //0-based indexing 
      int pathvis[N] = {0};
      
      for(int i=0; i<N; i++) {
        if(!vis[i]) {
          if(dfs(i, adj, vis, pathvis)) return true;
        }
      }
      return false;
    }
};

int main() {
//   int N = 4;
//   vector<int> adj[N] = {{1},{2},{3},{3}}; //Output: 1(true)
  
  int N = 3;
  vector<int> adj[N] = {{1},{2},{}}; //Output: 0(false)
  Solution obj;
  cout<<obj.isCyclic(N,adj);
}
