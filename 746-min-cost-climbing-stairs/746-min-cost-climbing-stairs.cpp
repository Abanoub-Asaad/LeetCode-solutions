class Solution {
public:
    
    vector<int> dp;
    
    int dfs(vector<int>& cost, int n) {
        if(!n || n == 1)
            return cost[n];
        if(dp[n])
            return dp[n];
        
        dp[n] = cost[n] + min(dfs(cost, n-1), dfs(cost, n-2));
        return dp[n];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        dp.resize(n, 0);
        return min(dfs(cost, n-1), dfs(cost, n-2));
    }
};


/*

    Solution with Recursion, TLE
    
    ->  Time = O(2 ^ N), Space = O(N)
    ->  Recurrence Relation:
           mincost(i) = cost[i]+min(mincost(i-1), mincost(i-2))
    ->  base case here are
           mincost(0) = cost[0]
           mincost(1) = cost[1]
    ------------------------------------------------       
    Optimization 1 - Top Down - add memoization to recursion
        From exponential to linear.
        
    [10,15,20]
           ^
    [0,1,2]
    
    10,20
    10,15,20
    15,20
    15
              n = 3
                 
            /       \
         0             1              
      /     \       /     \
     1       2     2       3
    / \     / \   / \       
   2   3   3   4 3   4   
  / \ 
 3   4
 
 
    
*/