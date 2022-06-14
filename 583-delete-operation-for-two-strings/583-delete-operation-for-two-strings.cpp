/* The idea is to get the longest common subsequence (lcs) 
    and from here we can compute the min distance.
    minDistance = text1.size()+text2.size()-(2*lcs) */
    
/*******************************************************
 Algorithm: DP + Tabulation
  Time: O(N*M)
  Space: O(N*M)
*******************************************************/
class Solution {
public:
    int minDistance(string text1, string text2) {
        int n = text1.size()+1, m = text2.size()+1;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int row = 1; row < m; row++) {
            for(int col = 1; col < n; col++) {
                if(text1[col-1] == text2[row-1])
                    dp[row][col] = 1 + dp[row-1][col-1];
                else 
                    dp[row][col] = max(dp[row-1][col], dp[row][col-1]);
            }
        }
        
        int lcs = dp[m-1][n-1];
        int minDistance = text1.size()+text2.size()-(2*lcs);
        return minDistance;
    }
};


/******************************************************
 Algorithm: Recursion -> TLE
  Time: O(2^max(N,M))
  Space: O(max(N,M))
*******************************************************
class Solution {
public:
    
    int lcs(string str1, string str2, int i, int j) {
        //base case
        if(i < 0 || j < 0)
            return 0;
        
        if(str1[i] == str2[j])
            return 1 + lcs(str1, str2, i-1, j-1);
        return max(lcs(str1, str2, i-1, j), lcs(str1, str2, i, j-1));
    }
    
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        int lcsVal = lcs(word1, word2, n-1, m-1);
        int minDistance = n + m - (2*lcsVal);
        return minDistance;
    }
};


/******************************************************
 Algorithm: DP + Memoization
  Time: O(N*M)
  Space: O(N*M)
*******************************************************
class Solution {
public:
    
    vector<vector<int>> dp;
    
    int lcs(string str1, string str2, int i, int j) {
        //base case
        if(i < 0 || j < 0)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(str1[i] == str2[j])
            return dp[i][j] = 1 + lcs(str1, str2, i-1, j-1);
        return dp[i][j] = max(lcs(str1, str2, i-1, j), lcs(str1, str2, i, j-1));
    }
    
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        dp.resize(n, vector<int>(m, -1));
        int lcsVal = lcs(word1, word2, n-1, m-1);
        int minDistance = n + m - (2*lcsVal);
        return minDistance;
    }
};
***********************************************************/