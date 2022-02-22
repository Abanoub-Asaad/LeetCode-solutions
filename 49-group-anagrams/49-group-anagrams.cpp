class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        
        for(auto i : strs) { // n
            string s = i;
            sort(s.begin(), s.end()); //mlogm
            mp[s].push_back(i);
        }
        
        for(auto i = mp.begin(); i != mp.end(); i++) 
            ans.push_back(i->second);
        
        return ans;
    }
};