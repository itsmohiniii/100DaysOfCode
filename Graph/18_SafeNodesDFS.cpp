// Eventual safe states (using Cycle detection technique DFS) 
// Directed Graph


#include<bits/stdc++.h>
using namespace std;

class Solution {
  private: 
    bool dfs(int node, vector<int> adj[], int vis[], int pathvis[], int check[]) {
      vis[node]=1;
      pathvis[node]=1;
      // check[node]=0 
      
      for(auto it: adj[node]) {
        //if the node is not visited
        if(!vis[it]) {
          if(dfs(it,adj,vis, pathvis, check)) {
            return true;  // check[node]=0
          }
        }
        //if the node has been previously visited
        // and also visited on the same path
        else if(pathvis[it]==1) { //vis[it]=1
          return true; // check[node]=0
        }
      }
      
      check[node]=1; 
      pathvis[node]=0;
      return false;
    }

  public: 
    //SC: O(N)+O(N)+O(N)+O(N) for vis array, for pathvis array, for check array, for recursion stack space
    //Space optimisation : O(N)+O(N) for vis array, for recursion stack space (How? maintain counters in vis array for different things, 
    // but for maintaining code quality, 3 different arrays are better)
    
    //TC: O(N)+O(N+E) for outer For loop, for overall dfs directed graph
    vector<int> eventualSafeNodes(int N, vector<int> adj []) {
      int vis[N]={0}; //0-based indexing 
      int pathvis[N] = {0};
      int check[N] = {0};
      vector<int> safeNodes;
      
      for(int i=0; i<N; i++) {
        if(!vis[i]) {
          dfs(i, adj, vis, pathvis, check);
        }
      }
      for(int i=0; i<N;i++) {
        if(check[i] == 1) safeNodes.push_back(i);
      }
      return safeNodes;
    }
};

int main() {
  int N = 8;
  vector<int> adj[N] = {{1,2},{2,3},{5},{0},{5},{},{},{1}}; //Output: [2,4,5,6]
  Solution obj;
  vector<int> res =  obj.eventualSafeNodes(N,adj);
  for(int i=0;i<res.size();i++) {
      cout<<res[i]<<" ";
  }
}

