//Alien Dictionary (Toposort using BFS)

#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
   vector<int> topoSortBFS (int N, vector<int> adj[]) {
       //find the indegree of all nodes
      int indegree[N] = {0};
      for(int i=0;i<N;i++) {
        for(auto it: adj[i]) {
          indegree[it]++;
        }
      }

      //insert all the nodes with indegree 0 into the queue
      queue<int> q;
      for(int i=0;i<N;i++) {
        //at least one node  will have indegree=0 as it is DAG 
        if(indegree[i]==0) q.push(i);
      }

      //take the node out of the queue, store in topo vector, and reduce the indegree (i.e. remove the incoming edges) of adjacent nodes
      vector<int> topo;
      while(!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node); 
        
        for(auto it: adj[node]) {
          indegree[it]--; //node is the topo vector now, so remove it from the indegree of its adjacent nodes
          if(indegree[it]==0) q.push(it);
        }
      }
      return topo;
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
        if(j==len-1 && s1.size()>s2.size()){
          return "false"; //all the characters match and the larger string is before the shorter string, hence order not possible
      }
      }
    }
    
    string ans = "";
    vector<int>topo = topoSortBFS(K, adj); //no. of vertices = K
    if(topo.size() <K){
        return "false"; //cyclic dependency, hence, order not possible
    }
    for(auto it: topo) {
      ans+=char(it +'a');
    }
    return ans;
  }
};

int main () {
//   int N= 5;
//   int K = 4;
//   string dict [N] = {"baa","abcd","abca","cab","cad"}; //Output: bdac

  int N= 2;
  int K = 4;
  string dict [N] = {"abcd","abc"}; //Output: false

//   int N= 3;
//   int K = 4;
//   string dict [N] = {"abc","bad", "ad"}; //Output: false

  Solution obj;
  cout<<obj.findOrderOfAlphabets(N, K,dict);
  return 0;
}
