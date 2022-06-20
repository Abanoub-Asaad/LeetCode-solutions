/***********************************************************************************
 Algorithm: using Trie and DFS
 Steps: 1. sort the input words descendingly based on their lengths
        2. reverse the strings, to be easier to check prefixes instead of suffixes
        3. build a trie "prefix tree" using the result words from the prev steps,
           and if there's a word that's not found in the trie, I will add it to 
           the tire and consider its length in the answer.
           
  Time: O(M), M is the total num of characters in used words while building the trie
  Space: O(26 * N), N is the num of nodes, 26 is the alphabet size.
***********************************************************************************/
struct Trie {
    vector<Trie*> children;
    
    Trie() {
        children = vector<Trie*>(26, NULL);
    }
    
    void add(string word, int begin, bool &isNewWord) {
        if(begin < word.size()) {
            int curInd = word[begin] - 'a';
            if(!children[curInd]) {
                children[curInd] = new Trie();
                isNewWord = true;
            }
            children[curInd] -> add(word, begin+1, isNewWord);
        }
    }
};

class Solution {
public:
    
    Trie *trie = new Trie();
    
    static bool comp(string s1, string s2) {
        return (s1.size() > s2.size());
    }
    
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        for(auto &w : words) {
            reverse(w.begin(), w.end());
        }
        
        int ans = 0;
        for(auto w : words) {
            bool isNewWord = false;
            trie -> add(w, 0, isNewWord);
            if(isNewWord)
                ans += w.size() + 1;
        }
        
        return ans;
    }
};