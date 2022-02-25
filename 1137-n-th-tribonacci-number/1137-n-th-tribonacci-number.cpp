class Solution {
public:
    int tribonacci(int n) {
        
        if(!n) return 0;
        if(n <= 2) return 1;
        int a = 0, b = 1, c = 1, sum = 0;
        while(n-- > 2)
        {
            sum = a + b + c;
            a = b;
            b = c;
            c = sum;
        }
        
        return sum;
    }
};


/*
    - Recursive
    - Iterative: Time=O(N), Space=O(1)
    - DP (Top-Bottom)
    - DP (Bottom-Up)


    DP: solution in time: O(N), Space: O(1)
    
    public int tribonacci(int n) {
        int dp[] = {0, 1, 1};
        for (int i = 3; i <= n; ++i)
            dp[i % 3] = dp[0] + dp[1] + dp[2];
        return dp[n % 3];
    }

*/