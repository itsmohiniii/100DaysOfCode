// print shortest Path from node 1 to n (using Dijkstra)
// Weighted Undirected graph (1-based indexing)
// Intuition: Remember where I am coming from (caching/memoization)

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public: 
  vector<int> printShortestPath(int n, int m, vector<vector<int>>& edges) {
    //create the graph
    vector<pair<int,int>> adj[n+1]; 
    for(auto it: edges) { //edges -> [[u,v,wt],...   ]
      int u = it[0];
      int v = it[1];
      int wt = it[2];
      adj[u].push_back({v,wt});
      adj[v].push_back({u,wt});
    }
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; //{dist,node}
    vector<int> dist(n+1, 1e9);
    vector<int> parent(n+1); //for memoization
    for(int i=1;i<=n;i++) {
      parent[i]=i;
    }
     
    dist[1]=0;
    pq.push({0,1});
    
    while(!pq.empty()) {
      auto it = pq.top();
      int node = it.second;
      int dis = it.first;
      pq.pop();
      
      for(auto it: adj[node]) {
        int adjNode = it.first;
        int edgeW = it.second;
        if(dis+edgeW < dist[adjNode]) {
          dist[adjNode] = dis + edgeW;
          pq.push({dist[adjNode], adjNode});
          parent[adjNode]= node;
        }
      }
    }
    
    if(dist[n]==1e9) return {-1};
    vector<int> path; //path-> [dist, ...path]
    int node = n;
    while(parent[node]!=node) {
      path.push_back(node);
      node = parent[node];
    }
    path.push_back(1);
    path.push_back(dist[n]); //dist from node 1 to n
    reverse(path.begin(), path.end());
    return path;
  }
};

int main() {
  int n = 5;
  int m = 6;
  vector<vector<int>> edges = {{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, {3, 5, 1}}; //Output: [5, 1,4,3,5]
  
  Solution obj;
  vector<int> path = obj.printShortestPath(n, m, edges);
  for(int i=0;i<path.size();i++) {
    cout<<path[i]<<" ";
  }
}
