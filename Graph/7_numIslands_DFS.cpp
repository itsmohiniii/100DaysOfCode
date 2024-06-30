#include<bits/stdc++.h>
using namespace std;

class Solution {
 private: 
  void dfs(int n, int m, int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid) {
   vis[row][col] = 1;
   //traverse in the neighbours and mark them if its a land and not visited
   for(int delRow=-1; delRow<=1; delRow++) { 
     for(int delCol=-1; delCol<=1; delCol++) {  
      int neighRow = row + delRow;  
      int neighCol = col + delCol; 
      if(neighRow>=0 && neighRow<n && neighCol>=0 && neighCol<m && grid[neighRow][neighCol] == '1' && vis[neighRow][neighCol]==0) {
       dfs(n,m, neighRow, neighCol, vis, grid);      
      }
     }
    }  
  }
 public:
  int numIslands(vector<vector<char>>& grid) {
   int n= grid.size(); //#rows
   int m = grid[0].size(); //#cols
   vector<vector<int>> vis(n, vector<int>(m,0));
   int cnt = 0;
   for(int row=0; row<n; row++) {
    for(int col=0; col<m; col++) {
     if(grid[row][col]=='1' && !vis[row][col]) {
      cnt++;
      dfs(n,m, row, col, vis, grid);
     }   
    }
   }
  return cnt;
  }
};


int main () {
 vector<vector<char>> grid1 = {{'0','1','1','1','0','0','0'},{'0','0','1','1','0','1','0'}};
 vector<vector<char>> grid2 = {{'0','1'},{'1','0'},{'1','1'},{'1','0'}};
 Solution obj;
 cout<<obj.numIslands(grid1)<<endl; //Output: 2
 cout<<obj.numIslands(grid2)<<endl; //Output: 1
}
