//Word Ladder - 1 (using BFS)

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public: 
  //TC: O(N*wordLength*26*logN)
  //SC: O(N) for set
  int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
    queue<pair<string,int>> q;
    q.push({startWord,1});
    // set<string> st(wordList.begin(),wordList.end()); //find()=> TC:O(logN)
    unordered_set<string> st(wordList.begin(),wordList.end()); //find() => amortized TC: O(1), WC TC : O(N)
    st.erase(startWord);
    
    //TC: O(N) where N is the # words in wordList
    // WC =>  # of words in wordList is the no. of times it will go into the queue (bcuz if it is not in the set of wordList, it never goes into the queue). 
    while(!q.empty()) {
      string word = q.front().first;
      int steps = q.front().second; 
      q.pop();
      if(word==targetWord) return steps; 

      //TC: O(wordLength*26*logN) 
      //loop for every character of word 
      // eg,word = hat
      for(int i=0;i<word.size();i++) {
        char original = word[i]; //eg, word[i]='h'
        for(char ch = 'a'; ch<='z';ch++) {
          word[i]=ch; //eg, word becomes aat, bat, cat and so on.
          if(st.find(word) != st.end()) { //if word exists in the set
            q.push({word,steps+1});
            st.erase(word);
          }
        }
        word[i]=original;
      }
    }
    
    return 0;
  }
};

int main() {
    // string startWord = "der";
    // string targetWord= "dfs";
    // vector<string> wordList = {"des","der","dfr","dgt","dfs"}; //Output: 3
    
    string startWord = "toon";
    string targetWord= "plea";
    vector<string> wordList = {"poon", "plee", "same", "poie","plea","plie","poin"}; //Output: 7
    
    Solution obj;
    cout<<obj.wordLadderLength(startWord, targetWord, wordList);
    
    return 0;
}
