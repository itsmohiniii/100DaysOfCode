//Detect cycle in Undirected graph using BFS

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public: 
    bool hasCycle(vector<int> adj[], int N) {
      queue<pair<int,int>> q;
      int vis[N] = {0}; //0-based indexing
      q.push({0,-1});
      while(!q.empty()) {
        int node = q.front().first;
        int prevnode = q.front().second;
        q.pop();
        for(auto it : adj[node]) {
          if (vis[it] && it!=prevnode) return true;
          if(!vis[it]) {
            vis[it]=1;
            q.push({it,node});
          }
        }
      }
      return false;
    }
 };

int main() {
//   int N = 5;
//   vector<int> adj[]= {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}} ; //Output: 1 (true)
  
  int N = 4;
  vector<int> adj[]=  {{}, {2}, {1, 3}, {2}} ; //Output: 0 (false)
  Solution obj;
  cout<<obj.hasCycle(adj, N);
  return 0;
}
