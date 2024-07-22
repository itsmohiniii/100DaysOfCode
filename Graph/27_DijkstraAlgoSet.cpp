//shortest Path using Dijkstra Algorithm (using Set)
//Undirected graph with edge weights 

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    //Assuming a connected graph 
    //TC: O(ElogN) where E->#edges, N->#nodes
    vector<int> shortestPathDijkstra(int N, vector<vector<int>> adj[], int src) {
      vector<int> dist(N, 1e9);
      set<pair<int,int>> st; //declare a set storing {dist,node}

      dist[src]=0;
      st.insert({0,src});

      while(!st.empty()) {
        auto i = *(st.begin());
        int node = i.second;
        int dis = i.first;
        st.erase(i);
        
        for(auto it: adj[node]) {
          int adjNode=it[0];
          int edgeW = it[1];

          if(dis+ edgeW < dist[adjNode]) {
            if(dist[adjNode] != 1e9) {
                st.erase({dist[adjNode], adjNode});
            }
            dist[adjNode] = dis + edgeW;
            st.insert({dist[adjNode], adjNode});
          }
        }
      }
      return dist;
    }
};

int main() {
    int N = 2;
    int src = 0;
    vector<vector<int>> adj[] = {{{1, 9}}, {{0, 9}}}; //Output: [0,9]
    
    // int N = 3;
    // int src = 2;
    // vector<vector<int>> adj[] = {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}}; //Output: [4,3,0]
    
    Solution obj;
    vector<int> dist = obj.shortestPathDijkstra(N, adj, src);
    for(int i=0;i<N;i++){
        cout<<dist[i]<<" ";
    }
    return 0;
}
