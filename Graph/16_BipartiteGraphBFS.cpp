//Bipartite Graph (using BFS)

#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    bool bfs(int node, vector<int>adj[], int color[]) {
      color[node]=0;
      queue<int> q;
      q.push(node);
       
      while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(auto it: adj[node]) {
          //if the adjacent node is yet not colored, we will give the opposite color of the node
          if(color[it]==-1) {
            q.push(it);
            color[it]=!color[node];
          } 
          //if the adjacent node having the same color as of node, 
          //that means someone colored it on some other path, hence, Not Bipartite
          else if (color[it]==color[node]) {
            return false;
          }
        }
      }
      return true;
    }
    
  public: 
    //TC and SC are similar to BFS of a graph.
    //SC: O(N) + O(N) for color array, queue
    //TC: O(N) + O(N+2E) => O(N) for outer For loop, O(N+2E) for overall bfs of graph
    bool isBipartite(int N, vector<int>adj[ ]) {
      //1-based indexing
      int color[N+1]; 
      for (int i=0;i<N+1;i++) color[i]=-1; //two colors : 0 and 1
      
      //assuming there can be  multiple connected components
      for(int i=1;i<N+1;i++){
          if(color[i]==-1) {
              if(!bfs(i, adj, color)){
                  return false;
              }
          }
      }
      return true;
    }
    
};

int main() {
  int N= 8;
  vector<int> adj[N+1] = {{},{2}, {1,3,6}, {2,4}, {3,5,7}, {4,6}, {2,5}, {4,8}, {7}}; //Output: 0 (false)
  
//   int N= 5;
//   vector<int> adj[N+1] = {{},{2,3}, {1,4}, {1,4}, {2,3,5}, {4}}; //Output: 1 (true)
  
  Solution obj;
  cout<<obj.isBipartite(N,adj);
}
