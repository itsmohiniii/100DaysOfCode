//Find eventual safe states (BFS | Kahn's Algo | Topo sort)

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findSafeNodes(int N, vector<int> adj[]) {
      vector<int> adjRev[N];
      for(int i=0;i<N;i++) {
        for(auto it: adj[i]) {  // i→it
          adjRev[it].push_back(i);  // it→i
        }
      }

      int indegree[N] = {0};
      for(int i=0;i<N;i++) {
        for(auto it: adjRev[i]) {
          indegree[it]++;
        }
      }
      
      queue<int> q;
      for(int i=0;i<N;i++) {
        if(indegree[i]==0) q.push(i);
      }
      
      vector<int> safeNodes;
      while(!q.empty()) {
        int node = q.front();
        q.pop();
        safeNodes.push_back(node);
        for(auto it: adjRev[node]) {
          indegree[it]--;
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
