/***************************************************
 Iterative solution without using additional memory
****************************************************/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for(int i = n-1; i > 0; i--) {
            for(int j = 0; j < i; j++) {
                triangle[i-1][j] += min(triangle[i][j], triangle[i][j+1]);
            }
        }
    
        return triangle[0][0];
    }
};


/***************************************
 Recursion: TLE
****************************************
class Solution {
public:
    
    int dfs(vector<vector<int>>& triangle, int i, int j) {
        if(i >= triangle.size() || j >= triangle[i].size())
            return 0;
        return triangle[i][j] + min(dfs(triangle, i+1, j), dfs(triangle, i+1, j+1));
    }    

    int minimumTotal(vector<vector<int>>& triangle) {
        return dfs(triangle, 0, 0);
    }
};


****************************************
 Recursion + Memoization
****************************************
class Solution {
public:
    
    int dfs(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if(i >= triangle.size() || j >= triangle[i].size())
            return 0;

        if(dp[i][j] != -1) 
            return dp[i][j]; 
        return dp[i][j] = triangle[i][j] + min(dfs(i+1, j, triangle, dp), dfs(i+1, j+1, triangle, dp));
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {   
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return dfs(0, 0, triangle, dp); 
    }
};
****************************************/