//Topo sort (Kahn's Algorithm | BFS) 
//Intuition: A node with indegree=0 has no incoming edges, so it can be placed at the starting of topoSort


#include<bits/stdc++.h>
using namespace std;

class Solution {
  public: 
    //TC: O(N+E) for overall bfs of graph
    //SC: O(N)+O(N) for indegree array, for queue 
    vector<int> topoSort (int N, vector<int> adj[]) {
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
        //at least one node  will have indegree=0 as it is DAG 
        if(indegree[i]==0) q.push(i);
      }

      //take the node out of the queue, store in topo vector,  and reduce the indegree (i.e. remove the incoming edges) of adjacent nodes
      vector<int> topo;
      while(!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node); 
        
        for(auto it: adj[node]) {
          indegree[it]--; //node is the topo vector now, so remove it from the indegree of its adjacent nodes
          if(indegree[it]==0) q.push(it);
        }
      }
      return topo;
    }
};

int main () {
  int N=4;
  vector<int> adj[] ={{},{0},{0},{0}};  //Output: [1,2,3,0] => one of the possible topoSorts
  Solution obj;
  vector<int> topo = obj.topoSort(N, adj);
  for(int i=0;i<N;i++) {
    cout<<topo[i]<<" ";
  }
}
