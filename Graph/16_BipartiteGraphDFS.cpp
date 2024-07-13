//Bipartite Graph (using DFS)

#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    bool dfs(int node, int col, vector<int>adj[], int color[]) {
      color[node]=col;
      for(auto it: adj[node]) {
        if(color[it]==-1) {
          if(dfs(it, !col, adj, color) == false) return false;
        } 
        else if(color[it]==col) {
          return false;
        }
      }
      return true;
    }
    
  public: 
    //TC and SC are similar to DFS of a graph.
    //SC: O(N) + O(N) for color array, recursion stack space
    //TC: O(N) + O(N+2E) => O(N) for outer For loop, O(N+2E) for overall dfs of graph
    bool isBipartite(int N, vector<int>adj[ ]) {
      //0-based indexing
      int color[N]; 
      for (int i=0;i<N;i++) color[i]=-1; //two colors : 0 and 1
      
      //assuming there can be  multiple connected components
      for(int i=0;i<N+1;i++){
          if(color[i]==-1) {
              if(!dfs(i, 0, adj, color)){
                  return false;
              }
          }
      }
      return true;
    }
    
};

int main() {
//   int N= 8;
//   vector<int> adj[N+1] = {{},{2}, {1,3,6}, {2,4}, {3,5,7}, {4,6}, {2,5}, {4,8}, {7}}; //Output: 0 (false)
  
  int N= 5;
  vector<int> adj[N+1] = {{},{2,3}, {1,4}, {1,4}, {2,3,5}, {4}}; //Output: 1 (true)
  
  Solution obj;
  cout<<obj.isBipartite(N,adj);
}


