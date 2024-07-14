//Course Schedule I (Pre requisite tasks)
//Problem link : https://www.geeksforgeeks.org/problems/prerequisite-tasks/1

//Possible Approaches: 1. Cycle Detection in Directed graph (Topo sort | Kahn's Algorithm | BFS) 
                    // 2. Cycle detection in Directed graph (DFS)

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public: 
    bool isPossibleFinishTasks(int N, vector<pair<int,int>>& prerequisites) {
      //form the graph
      vector<int> adj[N];
      for(auto it: prerequisites){
          adj[it.first].push_back(it.second);
      }
      
      int indegree[N] = {0};
      for(int i=0;i<N;i++) {
        for(auto it: adj[i]) {
          indegree[it]++;
        }
      }

      queue<int> q;
      for(int i=0;i<N;i++) {
        if(indegree[i]==0) q.push(i);
      }

      vector<int> topo;
      while(!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node); 
        
        for(auto it: adj[node]) {
          indegree[it]--; 
          if(indegree[it]==0) q.push(it);
        }
      }
       
      if(topo.size()==N) return true; //toposort possible => no cycle => possible to finish tasks
      return false; //toposort not possible => has a cycle => not possible to finish tasks
    }
};

int main () {
//   int N=4;
//   vector<pair<int,int>> prerequisites = {{1,0},{2,1},{3,2}}; //Output: 1

  int N=2;
  vector<pair<int,int>> prerequisites = {{1,0},{0,1}}; //Output: 0
  
  Solution obj;
  cout<<obj.isPossibleFinishTasks(N, prerequisites);
}
