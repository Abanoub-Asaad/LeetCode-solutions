class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        int a = 1, b = 2, sum = 0;
        while(n-- > 2) {
            sum = a + b;
            a = b;
            b = sum;
        }
        return sum;
    }
};


/*
  numOfStairs   numOfDistinctWays
      1              1
      2              2
      3              3
      4
    ----
    ----
    ----
    ----
        ^
    1,1,1,1
    1,2,1
    1,1,2
    2,1,1
    2,2

*/