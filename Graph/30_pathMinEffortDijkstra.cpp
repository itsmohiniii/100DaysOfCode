//Path with minimum effort (using Dijkstra -> PQ)

#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
  bool isValidNeighbour(int newr, int newc, int n, int m) {
    return newr>=0 && newr<n && newc>=0 && newc<m;
  }

  public:
  int minimumEffort(vector<vector<int>>& heights, int n, int m) { //n=#rows, m=#columns
    //PQ -> {effort, {row,col}}
    priority_queue< pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
    vector<vector<int>> effort(n, vector<int>(m, 1e9)); //effort = max(all differences in the path)
    effort[0][0] = 0;
    pq.push({0,{0,0}});
    
    int dr[] = {-1,0,1,0}; 
    int dc[] = {0,1,0,-1};
    
    while(!pq.empty()) {
      auto it = pq.top();
      pq.pop();
      int eff = it.first;
      int r = it.second.first;
      int c = it.second.second;
      
      //as it is a min heap, so, when you are popping out the dest cell, the effort in it will always be minimum.
      //effort (the maximum of all differences in that path) will always be greater than or equal to the current effort.
      if(r == n-1 && c== m-1) return eff; 
       
      for(int i=0;i<4;i++) {
        int newr = r + dr[i];
        int newc = c + dc[i];
        if(isValidNeighbour(newr, newc, n, m))  {
          int newEffort = max(abs(heights[newr][newc] - heights[r][c]), eff);
          if(newEffort < effort[newr][newc]) {
            effort[newr][newc] = newEffort;
            pq.push({newEffort, {newr,newc}});
          }
        }
      }
    }
    
    return -1; //unreachable
  }
};

int main() {
    // int n= 2;
    // int m= 2; 
    // vector<vector<int>> heights = {{7,7},{7,7}}; //Output: 0
    
    int n= 3;
    int m= 3; 
    vector<vector<int>> heights = {{1,2,2},{3,8,2},{5,3,5}}; //Output: 2
    
    Solution obj;
    cout<<obj.minimumEffort(heights, n, m);
    return 0;
}
