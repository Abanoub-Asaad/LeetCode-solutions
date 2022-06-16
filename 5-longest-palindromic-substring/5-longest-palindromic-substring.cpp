/*****************************************************************
 - Algorithm: 2 Pointers, for each character expand from it to 
    the right and left, and calculate longest palindrome possible.
    
 - Time: O(N^2)
 - Space: O(1)
*****************************************************************/
class Solution {
public:
    
    void checkPalind(string s, int &l, int &r) {
        int n = s.size();
        while(l >= 0 && r < n && s[l] == s[r]){
                l--, r++;
        }
    }
    
    string longestPalindrome(string s) {        
        int n = s.size();
        string result = "";
        result += s[0];
        
        for(int i = 0; i < n; i++){
            // odd palindrome substrings
            int l = i-1, r = i+1;
            checkPalind(s, l, r);
            if(result.size() < (r-l-1))
                result = s.substr(l+1, r-l-1);
            
            //even palindrome substrings
            l = i, r = i+1;
            checkPalind(s, l, r);
            if(result.size() < (r-l-1))
                result = s.substr(l+1, r-l-1);
        }
        
        return result;
    }
};

/*********************************************************************
 - Solution: Brute force -> TLE 
 - Time: O(N^3)
 - Space: O(1)
 - Algorithm: Get all the substrings and check the longest palindrome. 
***********************************************************************
class Solution {
public:
    
    bool isPalind(string s) {
        int n = s.size();
        int i = 0, j = n-1;
        while(i < n && j >= 0) {
            if(s[i] != s[j])
                return false;
            i++, j--;
        }
        return true;
    }
    
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        for(int i = 0; i < n; i++) {
            string cur = "";
            for(int j = i; j < n; j++) {
                cur += s[j];
                if(isPalind(cur) && cur.size() > ans.size())
                    ans = cur;
            }
        }
        
        return ans;
    }
}
***********************************************************************/