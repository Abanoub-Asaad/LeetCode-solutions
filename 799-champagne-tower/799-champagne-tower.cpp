class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        
        double dp[101][101] = {0.0};
        dp[0][0] = poured; 
        for(int i = 0; i < 100; i++) {
            for(int j = 0; j <= i; j++) {
                if(dp[i][j] >= 1) {
                    dp[i+1][j] += (dp[i][j]-1)/2.0;
                    dp[i+1][j+1] += (dp[i][j]-1)/2.0;
                    dp[i][j] = 1;
                }
            }
        }
        return dp[query_row][query_glass];
    }
};

/*
    When I pour one cup 
    When I pour 2 cups
    When I pour 3 cups
    When I pour 4 cups
    When I pour 5 cups
    
    1 cup ->  first row-> 1
    2 cups->  first row-> 1, second row->.5, .5
    3 cups -> first row-> 1, second row-> 1, 1
    4 cups -> first row-> 1, second row-> 1, 1, third row->.25, .5, .25    
    5 cups -> first row-> 1, second row-> 1, 2, third row->.5, 1, .5
    
                   1
                  ---
                  1   1
                 --- --- 
              .5    1    .5
              --   ---    --
            -- -- -- -- -- --
    
    I wanna know, each row needs how many cups to be filled
*/