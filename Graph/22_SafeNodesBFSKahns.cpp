//Find eventual safe states (BFS | Kahn's Algo | Topo sort)
// Intuition: All terminal nodes (with outdegree=0) are safe Nodes.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    //TC: same as Toposort + O(NlogN) for sorting the safeNodes WC -> O(NlogN)
    //SC: same as Toposort + O(N) for adjRev
    vector<int> findSafeNodes(int N, vector<int> adj[]) {
      
      //reverse the edges of graph and hence, outdegree of graph = indegree of reversed graph
      vector<int> adjRev[N];
      int indegree[N] = {0};
      for(int i=0;i<N;i++) {
        for(auto it: adj[i]) {  // i→it
          adjRev[it].push_back(i);  // it→i
          indegree[i]++; //store the indegree of reversed graph
        }
      }

      //identify the terminal nodes and push into queue. 
      queue<int> q;
      for(int i=0;i<N;i++) {
        if(indegree[i]==0) q.push(i);
      }
      
      vector<int> safeNodes;
      while(!q.empty()) {
        int node = q.front();
        q.pop();
        safeNodes.push_back(node); //queue has only safeNodes 
        for(auto it: adjRev[node]) {
          indegree[it]--; //do a removal of edges on adjacent nodes
          if(indegree[it]==0) q.push(it);
        }
      }

      sort(safeNodes.begin(), safeNodes.end());
      return safeNodes;
    }
};

int main() {
  int N= 8;
  vector<int> adj [] = {{1,2},{2,3},{5},{0},{5},{},{},{1}}; //Output: [2,4,5,6]
  Solution obj;
  vector<int> safeNodes = obj.findSafeNodes(N, adj);
  for(int i=0;i<safeNodes.size();i++) {
    cout<<safeNodes[i]<<" ";
  }
}
