class Solution {
public:
    int findMin(vector<int>& arr) {
        int minVal = INT_MAX;
        int l = 0, r = arr.size()-1, mid;  
        
        while(l <= r) {
            mid = (l+r)/2;
            minVal = min(arr[mid], minVal);
            if(arr[l] > arr[r] && arr[mid] > arr[r])
                l = mid + 1;
            else 
                r = mid - 1;
        }
        return minVal;
    }
};

/*
    Brute force approach: 
     - Loop over the array
     - Return the min value
     - Time: O(N)
    
    Optimized approach:
     - Time: O(log n)
     - I will think of binary search
    
    unique elements 
*/