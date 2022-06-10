/**********************************************
 Optimized Solution: Sliding Window and hash set
   Time: O(N)
   Space: O(N)
**********************************************/
class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, res = 0; 
        unordered_set<char> unique;
        for(int r = 0; r < n; r++) {
            if(unique.count(s[r])) {  
                while (s[l] != s[r]) {
                    unique.erase(s[l++]); 
                }
                l++;
            } else {
                unique.insert(s[r]);
                res = max(res, r-l+1);
            }
        }
        
        return res;
    }
};


/******************************************************************
 Another Solution: Get all valid substrings, and return max size
   Time: O(N^3)
   Space: O(N)
*******************************************************************   
     class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int mx = 0;
        for(int i = 0; i < n; i++) {
            string cur = "";
            for(int j = i; j < n; j++) {
                int freq = count(cur.begin(), cur.end(), s[j]);
                if(freq) {
                    break;   
                } else {
                    cur += s[j];
                    int cur_sz = cur.size();
                    mx = max(mx, cur_sz);
                }
            }
        }
    
        return mx;
    }
};
*******************************************************************/