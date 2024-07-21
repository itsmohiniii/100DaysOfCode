// Shortest Path in DAG (Toposort | using BFS or DFS)

#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
  void topoSortDFS(int node, vector<pair<int,int>> adj[], int vis[], stack<int>& st) {
    vis[node]=1;
    for(auto it: adj[node]) {
      int v = it.first;
      if(!vis[v]) topoSortDFS(v,adj,vis,st);
    }    
    st.push(node);
  }

  public:
  vector<int> shortestPath(int N, int M, vector<vector<int>>& edges, int src) {
    //create the graph
    vector<pair<int, int> > adj[N];
    for(int i=0;i<M;i++) {
      int u = edges[i][0];
      int v = edges[i][1];
      int wt = edges[i][2];
      adj[u].push_back({v,wt});                              
    }
    
    //find the toposort
    //TC:O(N+M) where N=#nodes, M=#edges 
    int vis[N]={0};
    stack<int> st;
    topoSortDFS(src,adj, vis, st);
    
    //do the distance thing
    vector<int> dist(N);
    for(int i=0;i<N;i++) {
      dist[i]=INT_MAX; 
    }
    dist[src]=0;

    //TC:O(N+M) where N=#nodes, M=#edges
    while(!st.empty()) {  //stack can have max N elements hence, TC:O(N)
      int node = st.top();
      st.pop();
      int distnode = dist[node]; //dist to reach from src to node
      
      for(auto it: adj[node]) { //in total for all nodes in stack, it will run for M times i.e. total no. of edges, hence, TC:O(M)
        int v = it.first;
        int wt = it.second; //dist to reach from node(u) to v
        dist[v] = min(dist[v], distnode + wt);
      }
    }   
    
    for(int i=0;i<N;i++){
        if(dist[i]==INT_MAX){
            dist[i]=-1;
        }
    }
    return dist;
    
  }
};

int main() {
    // int N=4;
    // int M=2;
    // int src=0;
    // vector<vector<int>> edges = {{0,1,2},{0,2,1}}; //Output: [0,2,1,-1]
    
    // int N=6;
    // int M=7;
    // int src=0;
    // vector<vector<int>> edges = {{0,1,2},{0,4,1},{4,5,4},{4,2,2},{1,2,3},{2,3,6},{5,3,1}}; //Output: [0,2,3,6,1,5]
    
    int N=7;
    int M=8;
    int src=5;
    vector<vector<int>> edges = {{0,1,2},{1,3,1},{2,3,3},{4,0,3},{4,2,1},{5,4,1},{6,4,2},{6,5,3}}; //Output: [4,6,2,5,1,0,-1]
    
    Solution obj;
    vector<int> dist = obj.shortestPath(N,M,edges, src);
    for(int i=0;i<N;i++){
        cout<<dist[i]<<" ";
    }
}



