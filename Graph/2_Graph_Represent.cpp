Directed or Undirected graph?

Input:
n, m (#nodes, #edges)
m lines (representing edges)

Store:
1. Adjacency matrix 
2. Adjacency List

0 or 1 based indexing?
1-based -> adj[n+1][n+1]
0-based => adj[n][n] 

ADJACENCY MATRIX WAY (undirected graph):
//TC: O(M) SC:O(N*N) there is lot of unused space in matrix
int main {
 int n, m;
 cin>>n>>m;
 int adj[n+1][n+1]; //1-based indexing graph
 for (int i=0; i<m; i++) {
  int u,v;
  cin>>u>>v;
  adj[u][v]=1;
  adj[v][u]=1;
 }
}




