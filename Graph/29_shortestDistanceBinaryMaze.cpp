//shortest distance in a binary maze (using Dijkstra -> BFS queue)
// shortest Path between source cell and destination cell
//given grid is like a graph with unit weights (assume unit weights as its not given)

// DP won't work as the value on any cell is path-dependent, so it won't work. 
// It works in the maze which has two direction movements in the right and bottom, and the future cells would never be visited. 
// Think about it by taking some examples. 

#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
  bool isValidNeighbour(int newr, int newc, int n, int m) {
    return newr>=0 && newr<n && newc>=0 && newc<m;
  }

  public:
  int shortestDistance(vector<vector<int>>& grid, pair<int,int> src, pair<int,int> dest) {
    //edge cases
    if(src.first==dest.first && src.second==dest.second) {
      return 0;
    }
    if(grid[src.first][src.second] ==0 || grid[dest.first][dest.second]==0) {
      return -1; //path not possible
    }

    //initial configuration
    queue<pair<int,  pair<int,int>>> q; // {dist, {row,col}}
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[src.first][src.second] = 0;
    q.push({0,{src.first,src.second}});
    
    int dr[] = {-1,0,1,0};
    int dc[] = {0,1,0,-1};
    while(!q.empty()) {
      auto it = q.front();
      q.pop();
      int r = it.second.first;
      int c = it.second.second;
      int dis = it.first;
      
      for(int i=0;i<4;i++) {
        int newr = r + dr[i];
        int newc = c + dc[i];
        if(isValidNeighbour(newr, newc, n, m) && grid[newr][newc]==1 && dis+1<dist[newr][newc]) {
          dist[newr][newc] = dis + 1;
          if(newr == dest.first && newc==dest.second) return dis+1;
          q.push({dis+1, {newr,newc}});
        }
      }
    }
    return -1;
  }
};

int main() {
    // vector<vector<int>> grid = {{1, 1, 1, 1},
    //                             {1, 1, 0, 1},
    //                             {1, 1, 1, 1},
    //                             {1, 1, 0, 0},
    //                             {1, 0, 0, 1}};
    // pair<int,int> src = {0, 1};
    // pair<int, int> dest = {2, 2}; //Output: 3
    
    vector<vector<int>> grid = {{1, 1, 1, 1, 1},
                                {1, 1, 1, 1, 1},
                                {1, 1, 1, 1, 0},
                                {1, 0, 1, 0, 1}};
    pair<int,int> src = {0, 0};
    pair<int, int> dest = {3, 4}; //Output: -1
    
    Solution obj;
    cout<<obj.shortestDistance(grid, src, dest);
    return 0;
}
