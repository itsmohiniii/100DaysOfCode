//Alien Dictionary (Toposort using DFS or BFS)

#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
  void dfs(int node, vector<int> adj[], int vis[], stack<int>& st) {
    vis[node]=1;
    for(auto it: adj[node]) {
      if(!vis[it]) dfs(it, adj,vis,st);
    }
    st.push(node);
  }

  vector<int> topoSortDFS(int N, vector<int> adj[]) {
    int vis[N] = {0};
    stack<int> st;
    for(int i=0;i<N;i++) {
      if(!vis[i]) dfs(i, adj, vis, st);
    }
    vector<int> ans;
    while(!st.empty()) {
      int node = st.top();
      st.pop();
      ans.push_back(node);
    }
    return ans;
  }

  public:
  string findOrderOfAlphabets (int N, int K, string dict[]) {
    vector<int> adj[K];
    for(int i=0;i<N-1;i++) { //iterate till second last string
      //pair of strings to compare characters
      string s1=dict[i];
      string s2=dict[i+1];
      int len = min(s1.size(), s2.size());
      for(int j=0;j<len;j++) { 
        //if characters are different
        if(s1[j]!=s2[j]) {
          adj[s1[j]-'a'].push_back(s2[j]-'a'); // - 'a' to convert string to integer 
          break;
        }
      }
    }
    
    string ans = "";
    vector<int>topo = topoSortDFS(K, adj); //no. of vertices = K
    for(auto it: topo) {
      ans+=char(it +'a');
    }
    return ans;
  }
};

int main () {
  int N= 5;
  int K = 4;
  string dict [N] = {"baa","abcd","abca","cab","cad"}; //Output: bdac
  Solution obj;
  cout<<obj.findOrderOfAlphabets(N, K,dict);
  return 0;
}
