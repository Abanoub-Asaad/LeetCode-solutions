/****************************
 Time: O(N)
 Space: O(N)
****************************/
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> binCodes;
        int n = s.size(); 
        for(int i = 0; i <= n-k; i++) {
            string cur = s.substr(i, k);
            binCodes.insert(cur);
        }
        
        return binCodes.size() == pow(2, k);
    }
};