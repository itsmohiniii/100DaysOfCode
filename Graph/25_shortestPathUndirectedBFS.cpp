// Shortest Path in Undirected graph with unit weights (using BFS)
//We used a queue as the graph has unit weights, so queue is already in sorted order as edge weights are increasing by 1.
// (so need of sorted data structure to sort them in distance)

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  //SC: O(N)+O(N)+O(N) for adj, for dist, for queue 
  //TC: O(N+2M) similar to BFS algorithm + O(M)+O(N) ~ O(N+2M)
  vector<int> shortestPath(int N, int M, vector<vector<int>>& edges, int src) {
    //create the undirected graph
    vector<int> adj[N];
    //TC:O(M)
    for(auto it: edges) {
      int u = it[0];
      int v = it[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    
    //BFS algorithm (dist array in place of vis array)
    vector<int> dist(N);
    for (int i=0;i<N;i++) {
      dist[i]=INT_MAX;
    }
    dist[src]=0;
    queue<int> q;  
    q.push(src);

    while(!q.empty()) {
      int node = q.front();
      q.pop();
      for (auto it: adj[node]) {
        if(dist[node]+1 < dist[it]) { //greedy algorithm
          dist[it]=dist[node]+1;
          q.push(it);
        }
      }
    }
    
    //TC:O(N)
    for(int i=0;i<N;i++) {
      if(dist[i]==INT_MAX) {
        dist[i]=-1;
      }
    }
    return dist;
    
  }
};

int main() {
    int N=4;
    int M=4;
    int src=3;
    vector<vector<int>> edges = {{0,0},{1,1},{1,3},{3,0}}; //Output: [1, 1, -1, 0]
    
    // int N=9;
    // int M=10;
    // int src=0;
    // vector<vector<int>> edges = {{0,1},{0,3},{3,4},{4,5},{5,6},{1,2},{2,6},{6,7},{7,8},{6,8}}; //Output: [0, 1, 2, 1, 2, 3, 3, 4, 4]
    
    Solution obj;
    vector<int> dist = obj.shortestPath(N,M,edges, src);
    for(int i=0;i<N;i++){
        cout<<dist[i]<<" ";
    }
    return 0;
}



