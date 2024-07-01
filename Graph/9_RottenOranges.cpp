//Rotten Oranges

#include<bits/stdc++.h>
using namespace std;

class Solution {
  private: 
    int bfs( queue <pair<pair<int,int>,int>> q, vector<vector<int>> vis, int n, int m, int cntFresh) {
      int tm=0;
      int cntFreshtoRotten = 0;
      int delrow [ ] = {-1,0,1,0};
      int delcol [ ] = {0,1,0,-1};
      while(!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int t = q.front().second;
        tm = max(tm,t);
        q.pop();
        for(int i=0; i<4;i++){
          int nrow= row + delrow[i];
          int ncol = col + delcol[i];
          if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==1) {       
            vis[nrow][ncol] = 2;
            q.push({{nrow,ncol},t+1});
            cntFreshtoRotten++;
          }
        }
      }
      if(cntFreshtoRotten!=cntFresh) return -1;
      return tm;
    }

  public:
    int rottingOranges(vector<vector<int>>& grid) {
      int n= grid.size();
      int m = grid[0].size();
      vector<vector<int>> vis = grid; //do not alter the data given to you, instead make a copy
      queue <pair< pair<int,int>, int>> q;  //{{r, c}, t}
      int cntFresh = 0;
      for(int i=0; i<n;i++) {
        for(int j=0;j<m;j++) {
          if(vis[i][j]==2) {
            q.push({{i,j},0}); //push all the rotten oranges in the queue with time=0 
          }
         if(vis[i][j]==1) { 
           cntFresh ++;
         }
        }
      }       return bfs(q,vis,n,m, cntFresh);
    }
};

int main() {
//   vector<vector<int>> grid = {{0,1,2},{0,1,2},{2,1,1}}; //Output: 1
  vector<vector<int>> grid = {{2,1,1},{1,1,0},{0 ,1,1}}; //Output: 4
//   vector<vector<int>> grid = {{1,2,1},{1,1,0},{0 ,0,1}}; //Output: -1
  Solution obj;
  cout<<obj.rottingOranges(grid);
  return 0;
}
