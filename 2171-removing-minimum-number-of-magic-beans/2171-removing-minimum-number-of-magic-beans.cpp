class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        
        long long ans = LLONG_MAX, n = beans.size();
        long long sum = accumulate(beans.begin(), beans.end(), 0L);
        
        sort(beans.begin(), beans.end());
        
        for(int i = 0; i < beans.size(); i++, n--)
            ans = min(ans, sum - n*beans[i]);
        
        return ans;
    }
};


/*
    
    ------------------------------
    * Brute forces solution: Time: O(N^2)
    
    I will make two nested loops and loop to make each time all 
    of the elements in the array equal a specific num from the array
    and the elements will equal zero and then I will calculate the num
    of operations in all of them and get the min.
    
    * Example:
    
    [4,1,6,5]
    [4,0,4,4] #operations = 4
    [1,1,1,1] #operations = 12
    [0,0,6,0] #opeartions = 10
    [0,0,5,5] #operations = 6
    ------------------------------
    
    * Optimized solution: Time: O(n log n)
    
    nums = a, b, c, d ( a < b < c < d )
    if make nums [a, a, a, a] remove beans (b - a) + (c - a) + (d - a) == b + c + d - 3a
    if make nums [0, b, b, b] remove beans a + (c - b) + (d - b) == a + c + d - 2b
    if make nums [0, 0, c, d] remove beans a + b + (d - c) == a + b + d - c
    if make nums [0, 0, 0, d] remove beans a + b + c

    b + c + d - 3a == (a + b + c + d) - 4a
    a + c + d - 2b == (a + b + c + d) - 3b
    a + b + d -c == (a + b + c + d) - 2c
    a + b + c == (a + b + c + d) - d
*/