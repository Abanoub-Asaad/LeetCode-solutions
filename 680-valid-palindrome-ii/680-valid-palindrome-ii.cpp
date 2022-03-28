class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();
        int cntDiffsR = 0, cntDiffsL = 0;
        
        // remove from right
        for(int i = 0, j = n-1; i <= j; ) {
            if(s[i] == s[j])
                i++, j--;
            else 
                cntDiffsR++, j--;
        }
        
        // remove from left
        for(int i = 0, j = n-1; i <= j; ) {
            if(s[i] == s[j])
                i++, j--;
            else 
                cntDiffsL++, i++;
        }
        
        return (cntDiffsR < 2 || cntDiffsL < 2) ? 1 : 0;
    }
};

/******************************************
  Time: O(N)
  Space: O(1)
  ************************************
  
    After deleting at most one char

    I will ignore a char 
     one time from the right 
     another time from the left
     
    If there's more than one different char
     return false
     
******************************************/