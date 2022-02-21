class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};


/*

    ---------
    | * |   |
    ---------
    |   |   |
    ---------
    |   | - |
    ---------
    
    - Get all possible unique paths 

    - Go either right or down
    
    I feel it could be solved with recursion / dfs
    
    
    
// 1.backtracking - TLE - 37 / 62 test cases passed.
    class Solution {
public:
    
    int dfs(int i, int j, int m, int n) {
        
        //base case
        if(i >= m || j >= n) return 0;
        if(i == m-1 && j == n-1) return 1;
            
        //recursive
        int n1 = dfs(i+1, j, m, n);
        int n2 = dfs(i, j+1, m, n);
        return n1+n2;
    }
    
    int uniquePaths(int m, int n) {
        return dfs(0,0, m, n);
    }
};
*/