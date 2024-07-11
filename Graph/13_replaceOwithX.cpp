// Surrounded regions
// Replace Os or set of Os (that are surrounded by X on all 4 sides) with Xs 

//Intution: set of Os connected to a boundary 'O' cant be surrounded by 'X', hence, cant be converted to 'X'
//Approach: start from boundary Os and traverse (using dfs/bfs) and mark all Os connected to a boundary 'O' as visited (not to be converted),
//          and convert the remainig Os to 'X'.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    bool isValidNeighbour(int nrow, int ncol, int n, int m) {
      return nrow>=0 && nrow<n && ncol>=0 && ncol<m;
    }

    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& mat, int n, int m, int delrow[ ], int delcol[ ]) {
      vis[row][col]=1;
      for(int i=0;i<4;i++) {
        int nrow = row+ delrow[i];
        int ncol = col + delcol[i];
        if(isValidNeighbour(nrow,ncol,n,m) && mat[nrow][ncol]=='O' && !vis[nrow][ncol]) {
          dfs(nrow,ncol,vis,mat,n,m, delrow, delcol);
        }
      }
    }

  public: 
    //TC: O(N)+O(M)+  O(N*M)*4 ~ O(N*M) ... WC: if all cells are 'O', dfs will run for (N*M) cells and *4, for 4 directions neighbours 
    //SC: O(N*M)+O(N*M)+O(4)+O(4) ~ O(N*M) ...for vis, for auxiliary stack space WC: if all cells are 'O', at one instance, stack space can be (N*M) maximum, for delrow, for delcol
    vector<vector<char>> replaceOwithX(int n, int m, vector<vector<char>> mat) {
      vector<vector<int>> vis(n, vector<int>(m,0));
      int delrow[ ] = {-1,0,1,0};
      int delcol[ ] = {0,1,0,-1};
      
      //traverse first and last rows
      //TC: O(M)
      for(int col=0;col<m;col++) {
        //firstrow
        if(mat[0][col]=='O' && !vis[0][col]){
          dfs(0,col,vis,mat,n,m, delrow, delcol);
        }
        //lastrow
        if(mat[n-1][col]=='O' && !vis[n-1][col]){
          dfs(n-1,col,vis,mat,n,m, delrow, delcol);
        }
      }
      
      //traverse first and last columns
      //TC: O(N)
      for(int row=0;row<n;row++) {
        // first column
        if(mat[row][0]=='O' && !vis[row][0]){
          dfs(row,0,vis,mat,n,m, delrow, delcol);
        }
        // last column
        if(mat[row][m-1]=='O' && !vis[row][m-1]){
          dfs(row,m-1,vis,mat,n,m, delrow, delcol);
        }
      } 

      //traverse 1st row, 1st column, last row, last column
      // for(int row=0;row<n;row++) {
      //   for(int col=0;col<m;col++) {
      //     if((row==0 || row==n-1 || col==0 || col==m-1) && mat[row][col]=='O' && !vis[row][col]) {
      //       dfs(row,col,vis,mat,n,m, delrow, delcol);
      //     }
      //   }
      // } 
      
      for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
          if(mat[i][j]=='O' && !vis[i][j]) {
            mat[i][j]='X';
          }
        }
      }
      return mat;
    }
};

int main() {
  vector<vector<char>> mat = 
    {{'X', 'O', 'X', 'X', 'X', 'X'},
    {'X', 'O', 'X', 'X', 'O', 'X'},
    {'X', 'X', 'X', 'O', 'O', 'X'},
    {'O', 'X', 'X', 'X', 'X', 'X'},
    {'X', 'X', 'X', 'O', 'X', 'O'},
    {'O', 'O', 'X', 'O', 'O', 'O'}};
  int n = mat.size();
  int m= mat[0].size();
  Solution obj;
  vector<vector<char>> res = obj.replaceOwithX(n, m, mat);
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) { 
      cout<<res[i][j]<<" ";
    }
    cout<<endl;
  }
  //Output:
  // X O X X X X 
  // X O X X X X 
  // X X X X X X 
  // O X X X X X 
  // X X X O X O 
  // O O X O O O 
}
