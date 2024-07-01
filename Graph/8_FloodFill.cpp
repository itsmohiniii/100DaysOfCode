//Flood fill Algorithm

#include <bits/stdc++.h>
using namespace std;

class Solution {
  private: 
    void dfs(int row, int col, vector<vector<int>>& ans, int iniColor, int newColor, int n, int m) {
      ans[row][col] = newColor;
      int delRow [ ] = {-1, 0, +1, 0};
      int delCol [ ] = {0,+1,0,-1};
      for(int i=0; i<4; i++) { 
        int nRow = row + delRow[i];
        int nCol = col + delCol[i];
        if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && ans[nRow][nCol] == iniColor && ans[nRow][nCol] != newColor) {
          dfs(nRow, nCol, ans, iniColor, newColor, n, m);
        }
      }
    }

  public:
    //TC: O(N*M) + O(N*M*4) ~ O(N*M)
    //TC: WC=> If all nodes are connected and have same iniColor, dfs call will be made (N*M) times and for every call, we are traversing for 4 neighbours. 
    //SC: O(N*M) + O(N*M) + O(4) + O(4) for 'ans' matrix and for recursion stack space WC: all nodes have iniColor and for delRow O(4) and for delCol O(4). 
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
      int iniColor = image[sr][sc];
      int n = image.size(); //#rows
      int m = image[0].size(); //#cols
      //we should not tamper given data, hence, using another matrix 'ans' to store the result. 
      vector<vector<int>> ans = image;
      if(iniColor != newColor) {
        dfs(sr, sc, ans, iniColor, newColor, n, m);
      }
      return ans;
    }
    
    void printMatrix (vector<vector<int>>& matrix) {
      int n=matrix.size(); //#rows
      int m=matrix[0].size(); //#cols
      for(int i=0;i<n;i++) {
        for(int j=0; j<m; j++) {
          cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
      }
    }

};


int main () {
  vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
  int sr = 1;
  int sc= 1;
  int newColor = 2;
  Solution obj;
  vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
  obj.printMatrix(ans); //Output: {{2,2,2},{2,2,0},{2,0,1}}

}
