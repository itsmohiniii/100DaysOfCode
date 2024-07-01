//Detect cycle in Undirected graph using BFS

#include<bits/stdc++.h>
using namespace std;

class Solution {
  private: 
    bool detectUsingBFS(vector<int> adj[], int startNode, int vis[]) {
      vis[startNode]=1;
      queue<pair<int,int>> q;
      q.push({startNode,-1});
      while(!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto it : adj[node]) {
          if(!vis[it]) {
            vis[it]=1;
            q.push({it,node});
          } else if (it!=parent) { //vis[it]==1
            return true;
          }
        }
      }
      return false;
    }
    
  public: 
    bool hasCycle(vector<int> adj[], int N) {
      int vis[N] = {0}; //0-based indexing
      for(int i=0;i<N;i++) { //Considering graph can have multiple connected components
          if(!vis[i]){
              if(detectUsingBFS(adj,i,vis)) return true;
          }
      }
      return false;
    }
 };

int main() {
  int N = 5;
  vector<int> adj[]= {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}} ; //Output: 1 (true)
  
//   int N = 4;
//   vector<int> adj[]=  {{}, {2}, {1, 3}, {2}} ; //Output: 0 (false)
  
//   int N = 4;
//   //Multiple connected components example
//   vector<int> adj[]=  {{}, {2,3}, {1, 3}, {1,2}} ; //Output: 1 (true)
  Solution obj;
  cout<<obj.hasCycle(adj, N);
  return 0;
}
