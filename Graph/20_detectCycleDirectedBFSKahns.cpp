//Detect cycle in Directed graph (Topo sort | Kahn's Algorithm | BFS) 
//Approach: if toposort has N elements, it is DAG as toposort is only possible for DAG.
         // if toposort has <N elements, it has a cycle.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public: 
    //TC: O(N+E) for overall bfs of graph
    //SC: O(N)+O(N) for indegree array, for queue 
    bool isCyclic (int N, vector<int> adj[]) {
      //find the indegree of all nodes
      int indegree[N] = {0};
      for(int i=0;i<N;i++) {
        for(auto it: adj[i]) {
          indegree[it]++;
        }
      }

      //insert all the nodes with indegree 0 into the queue
      queue<int> q;
      for(int i=0;i<N;i++) {
        if(indegree[i]==0) q.push(i);
      }

      //take the node out of the queue, increase the topoSort count, and reduce the indegree of adjacent nodes
      int topocnt = 0;
      while(!q.empty()) {
        int node = q.front();
        q.pop();
        topocnt++;
        
        for(auto it: adj[node]) {
          indegree[it]--;
          if(indegree[it]==0) q.push(it);
        }
      }
      
      if(topocnt ==N) return false;
      return true;
    }
};

int main () {
//   int N=4;
//   vector<int> adj[] ={{},{0},{0},{0}};  //Output: 0 (false)

  int N=4;
  vector<int> adj[] ={{1},{2},{3},{3}};  //Output: 1 (true)
  Solution obj;
  cout<<obj.isCyclic(N, adj);
}
