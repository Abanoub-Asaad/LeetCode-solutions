class Solution {
public:
    bool isPalindrome(string s) {
        
        string cleanStr = "";
        
        for(auto i : s) 
        {
            char cur = tolower(i);
            if(isalnum(cur))
               cleanStr+=cur;
        }
        
        int n = cleanStr.size();
        for(int i = 0, j = n-1; i < j; i++, j--) {
            if(cleanStr[i] != cleanStr[j])
                return false;
        }
        
        return true;
    }
};