#include<bits/stdc++.h>
using namespace std;

class Solution {
  private: void dfs(int startNode, vector < int > adjLs[], int vis[]) {
    vis[startNode] = 1;
    for (auto it: adjLs[startNode]) {
      if (!vis[it]) {
        dfs(it, adjLs, vis);
      }
    }
  }

  //SC: O(N) + O(N) for recursion stack space, vis array
  //TC: O(N) + O(N+2E) ~ O(N) if E=0  => O(N) for outer For loop, O(N+2E) for entire dfs of graph
  public: int numProvinces(int N, vector < vector < int >> adjMtx) {
    //convert adjacency Matrix to Adjacency List
    vector < int > adjLs[N];
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (adjMtx[i][j] == 1 && i != j) { //no self nodes 
          adjLs[i].push_back(j);
        }
      }
    }

    int vis[N] = {0}; //0-based indexing
    int cnt = 0;
    //TC: O(N) for outer For loop
    for (int i = 0; i < N; i++) {
      if (vis[i] == 0) {
        cnt++;
        dfs(i, adjLs, vis);
      }
    }
    return cnt;
  }
};

int main() {
  int N = 3;
  vector<vector<int>> adjMtx = { {1,0,1},
				 {0,1,0},
				 {1,0,1} };
  Solution obj;
  cout << obj.numProvinces(N, adjMtx);
  return 0;

}
