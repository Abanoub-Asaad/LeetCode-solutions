class Solution {
public:
    //------------ Time: O(log x)
    int mySqrt(int x) {
        if(!x)
            return 0;
        int left = 1, right = x, mid;
        while(true) {
            mid = left + (right - left)/2;
            if(mid > x/mid)
                right = mid - 1;
            else 
            {
                if(mid+1 > x/(mid+1))
                    return mid;
                left = mid + 1;
            }
        }
        return 0;
    }
};

/*------------------------------------------------
    Time: O(x)
--------------------------------
    class Solution {
public:
    int mySqrt(int x) {
        for(int i = 1; i <= x; i++) {
            if(i == x/i)
                return i;
            else if(i > x/i)
                return i-1;
        }
        
        return 0;
    }
};
------------------------------------------------*/