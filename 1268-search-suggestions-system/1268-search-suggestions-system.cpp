/***********************************************************************************
 Algorithm: using Trie and DFS
  Time: O(M), M is the total num of characters in products while building the trie
  Space: O(26 * N), N is the num of nodes, 26 is the alphabet size.
***********************************************************************************/
struct Trie {
    vector<int> wordsIndexs; 
    vector<Trie*> children;
    
    Trie() {
        children = vector<Trie*>(26, NULL);
    }
    
    void add(string word, int begin, int wordInd) {
        wordsIndexs.push_back(wordInd);
        if(begin < word.size()) {
            int curInd = word[begin] - 'a';
            if(!children[curInd]) {
                children[curInd] = new Trie();
            }
            children[curInd] -> add(word, begin+1, wordInd);
        }
    }
    
    vector<int> search(string prefix, int begin) {
        if(begin == prefix.size()) {
            return wordsIndexs;
        } else {
            int curInd = prefix[begin] - 'a';
            if(!children[curInd]){
                return {};
            } else {
                return children[curInd] -> search(prefix, begin+1);   
            }
        } 
    }
};

class Solution {
public:
    
    Trie* trie = new Trie();
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        //result vector
        vector<vector<string>> suggestedProducts;
        
        //sort the products to be lexicographically minimums
        sort(products.begin(), products.end());
        
        //build Trie
        int n = products.size();
        for(int i = 0; i < n; i++) {
            string word = products[i];
            trie -> add(word, 0, i);
        }
        
        //go through the prefixes of the searchWord
        string prefix = "";
        for(int i = 0; i < searchWord.size(); i++) {
            prefix += searchWord[i];
            vector<int> indices = trie -> search(prefix, 0);
            vector<string> words;
            int n = (indices.size() <= 3) ? indices.size() : 3;
            for(int i = 0; i < n; i++) {
                int j = indices[i];
                words.push_back(products[j]);
            }
            suggestedProducts.push_back(words);
        }
        
        return suggestedProducts;
    }
};