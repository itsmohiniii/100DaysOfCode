//Course Schedule II (Pre requisite tasks)
//Problem link : https://www.geeksforgeeks.org/problems/course-schedule/1

//Possible Approach: Cycle Detection in Directed graph (Topo sort | Kahn's Algorithm | BFS) 

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public: 
    vector<int> findOrderOfTasks(int N, int M, vector<vector<int>> prerequisites) {
      //form the graph
      vector<int> adj[N];
      for(auto it: prerequisites){
          adj[it[1]].push_back(it[0]); //opposite order 
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
       
      if(topo.size()==N) return topo; //toposort possible => no cycle => possible to finish tasks => return order of tasks
      return {}; //toposort not possible => has a cycle => not possible to finish tasks => return empty vector
    }
};

int main () {
  int N=4;
  int M=4;
  vector<vector<int>> prerequisites = {{1, 0},{2, 0},{3, 1},{3, 2}}; //Output: [0, 1, 2, 3]

//   int N=2;
//   int M=1;
//   vector<vector<int>> prerequisites = {{1, 0}}; //Output: [0,1]
  
  Solution obj;
  vector<int> ans = obj.findOrderOfTasks(N, M, prerequisites);
  for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
  }
}
