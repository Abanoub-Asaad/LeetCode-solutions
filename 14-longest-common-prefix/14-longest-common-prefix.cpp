class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int n = strs.size();
        if(strs.size() == 1) return strs[0];
        sort(strs.begin(), strs.end());
        string s = strs[0], e = strs[n-1];
        string ans = "";
        
        for(int i = 0; i < min(s.size(), e.size()); i++) 
        {
            if(s[i] == e[i])
                ans += s[i];
            else 
                return ans;
        }
        
        return ans;
    }
};

/*
    Brute force solution:
      Time: O(n log n) 
    
*/