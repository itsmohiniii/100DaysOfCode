// Distance of Nearest cell having 1 
// 0/1 matrix

#include <bits/stdc++.h>
using namespace std;

class Solution {
  private: 
    bool isvalidNeighbour (int nrow, int ncol, int n, int m) {
      return nrow>=0 && nrow<n && ncol>=0 && ncol<m;
    }
    
  public: 
    vector<vector<int>> distanceNearest1 (vector<vector<int>> grid) {
      int n = grid.size();
      int m = grid[0].size();
      vector<vector<int>> vis(n, vector<int>(m,0));
      vector<vector<int>> dist(n, vector<int>(m,0));
      queue<pair<pair<int,int>,int>> q;
      
      //push initial 1s in the queue and mark them  as visited
      for(int i=0;i<n;i++) {
        for(int j=0; j<m;j++) {
          if(grid[i][j]==1) {
            q.push({{i,j},0});
            vis[i][j]=1;
          }
        } 
      }
      
      int delrow[] = {-1,0,1,0};
      int delcol[] = {0,1,0,-1};
      
      //traverse till the queue is non-empty
      while(!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        
        //pop and mark the steps in dist vector  
        q.pop();
        dist[row][col] = steps;
        
        // if not visited, push the neighbours in the queue and mark them as visited
        for(int i=0;i<4;i++) {
          int nrow = row + delrow[i];
          int ncol = col + delcol[i];
          if(isvalidNeighbour(nrow, ncol, n, m) && !vis[nrow][ncol]) {
            q.push({{nrow,ncol},steps+1});
            vis[nrow][ncol] =1;
          }
        }
      }
      return dist;
    }
};

int main () {
  vector<vector<int>> grid = { {0,0,0}, {0,1,0}, {1,0,1}};
  Solution obj;
  vector<vector<int>> res = obj.distanceNearest1(grid); 
  for(int i=0; i<res.size(); i++ ) { 
    for(int j=0;j<res[0].size();j++ ) {
      cout<<res[i][j]<<" ";
    }
    cout<<endl;
  }
   //Output:2 1 2 
         // 1 0 1 
         // 0 1 0 
}


