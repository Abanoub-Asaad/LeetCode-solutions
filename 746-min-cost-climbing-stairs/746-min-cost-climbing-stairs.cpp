class Solution {
public:
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, 0);    
        for(int i = 0; i < n; i++) {
            if(i < 2) dp[i] = cost[i];
            else dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }
        
        return min(dp[n-1], dp[n-2]);
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
        From exponential time to linear.
    ------------------------------------------------
    Optimization 2 - Bottom Up - convert recursion to iteration, to get rid of the recursive stack          "Tabulation"
    ------------------------------------------------
    
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