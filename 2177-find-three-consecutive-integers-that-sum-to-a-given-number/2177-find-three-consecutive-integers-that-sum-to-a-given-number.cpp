class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        
        long long n = ((num-3)/3);
        if((3*n)+3 == num)
                return {n, n+1, n+2};
        
        return {};
    }
};

/*
    we know that we should get three number their sum = num
    so we can consider that:
    
    n + (n+1) +(n+2) = num
    3*n + 3 = num
    3*n = num-3
    n = (nums-3)/3
    
*/