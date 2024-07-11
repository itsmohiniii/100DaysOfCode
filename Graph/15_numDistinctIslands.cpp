//Number of distinct islands (use BFS or DFS)

#include<bits/stdc++.h>
using namespace std;

class Solution { 
  private:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid, int n, int m, int row0, int col0, int delrow[], int delcol[], vector<pair<int,int>>& vec) {
      vis[row][col]=1;
      vec.push_back({row-row0, col- col0});
      for(int i=0;i<4;i++) {
        int nrow= row + delrow[i];
        int ncol = col + delcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
          dfs(nrow,ncol,vis,grid,n, m,row0,col0, delrow, delcol, vec);
        }
      }
    }

  public: 
    //TC:O(N*M*log(N*M))+O(N*M*4)
    //SC:O(N*M)+O(N*M) 
    int numDistinctIslands(vector<vector<int>>& grid) {
      int n = grid.size();
      int m = grid[0].size();
      vector<vector<int>> vis(n, vector<int>(m,0)); //SC:O(N*M) 
      set<vector<pair<int,int>>> st; //SC:O(N*M) WC:set is storing all the coordinates
      int delrow[ ] = {-1,0,1,0};
      int delcol[ ] = {0,1,0,-1};

      //TC:O(N*M)
      for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
          if(grid[i][j]==1 && !vis[i][j]) {
            vector<pair<int,int>> vec;
            dfs(i,j,vis,grid,n, m,i,j, delrow, delcol, vec); //TC: O(N*M*4) for all dfs calls
            st.insert(vec); //TC: O(log(N*M)) where N*M is the length of set, WC: set will store all the coordinates
          }
        }
      }
      return st.size();
    }
};

int main() {
//   vector<vector<int>> grid = {{1, 1, 0, 0, 0}, {1, 1, 0, 0, 0}, {0, 0, 0, 1, 1}, {0, 0, 0, 1, 1}}; //Output:1
  vector<vector<int>> grid = {{1, 1, 0, 1, 1}, {1, 0, 0, 0, 0}, {0, 0, 0, 0, 1}, {1, 1, 0, 1, 1}}; //Output:3
  Solution obj;
  cout<<obj.numDistinctIslands(grid);
}
