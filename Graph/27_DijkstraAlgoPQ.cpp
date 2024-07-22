//shortest Path using Dijkstra Algorithm (using Priority Queue - minHeap)
//Undirected graph with edge weights 

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    //Assuming a connected graph 
    vector<int> shortestPathDijkstra(int N, vector<vector<int>> adj[], int src) {
      vector<int> dist(N);
      for(int i=0;i<N;i++) dist[i]=1e9; //marked as infinite
      priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; //declare a min-heap

      dist[src]=0;
      pq.push({0,src});
      
      while(!pq.empty()) {
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();
        
        for(auto it: adj[node]) {
          int adjNode=it[0];
          int edgeWeight = it[1];

          if(dis+ edgeWeight < dist[adjNode]) {
            dist[adjNode] = dis + edgeWeight;
            pq.push({dist[adjNode], adjNode});
          }
        }
      }
      return dist;
    }
};

int main() {
    // int N = 2;
    // int src = 0;
    // vector<vector<int>> adj[] = {{{1, 9}}, {{0, 9}}}; //Output: [0,9]
    
    int N = 3;
    int src = 2;
    vector<vector<int>> adj[] = {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}}; //Output: [4,3,0]
    
    Solution obj;
    vector<int> dist = obj.shortestPathDijkstra(N, adj, src);
    for(int i=0;i<N;i++){
        cout<<dist[i]<<" ";
    }
    return 0;
}
