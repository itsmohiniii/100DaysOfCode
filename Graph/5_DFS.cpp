#include<bits/stdc++.h>
using namespace std;

//depth = Recursion
class Solution {
 private:
  // dfs() function is called once for every node TC:O(N)
  void dfs(int node, int vis[ ], vector<int>& res, vector<int> adj[ ]){
   vis[node]=1;
   res.push_back(node);
   //traverse all its neighbours TC:O(2E) i.e total degree of graph
   for(auto it: adj[node]){
    if(!vis[it]) {
     dfs(it, vis, res, adj);
    }
   }
  }

 public:
  //TC: O(N)+O(2E) for undirected graph
  //TC: O(N)+O(E) for directed graph
  //SC: O(N)+O(N)+O(N)=O(3N)~O(N) vis array, res vector to store dfs list, recursion stack space WC if graph is skewed, then O(N)
  vector<int> traverse_graph_dfs(int N, vector<int> adj[ ]) {
   int vis[N] = {0};
   int startNode = 0;
   vector<int> res;
   dfs(startNode, vis, res, adj);
   return res;
  }
};

void printVector(vector<int> vec) {
 for(int i=0;i<vec.size();i++) {
  cout<<vec[i]<<" ";
 }
}

int main () {
 int n, m;
 cin>>n>>m;
 vector<int> adj[n];
 for(int i=0;i<m;i++){
  int u,v;
  cin>>u>>v;
  adj[u].push_back(v);
  adj[v].push_back(u);
 }
 Solution obj;
 vector<int> res = obj.traverse_graph_dfs(n, adj);
 printVector(res);
 }

Sample Input: 
5 5
0 1
0 2
0 3
2 4
2 3

Sample Output:
0 1 2 4 3 
