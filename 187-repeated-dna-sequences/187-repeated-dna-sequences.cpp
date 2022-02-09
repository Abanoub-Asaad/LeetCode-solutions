class Solution {
public:
    
    vector<string> findRepeatedDnaSequences(string s) {
        
        vector<string> repeatedSubsequences;
        unordered_map<string, int> seen;
        int i = 0;
        
        while(i + 10 <= s.size()) {
            string subStr = s.substr(i++, 10);
            seen[subStr]++;
        }
        
        for(auto i = seen.begin(); i != seen.end(); i++) {
            if(i -> second >= 2)
                repeatedSubsequences.push_back(i->first);
        } 
        
        return repeatedSubsequences;
    }
};


/*
     Use hash map to store all the substrings with their frequencies
     Check if there's a map has a repeated string, so print it.
*/