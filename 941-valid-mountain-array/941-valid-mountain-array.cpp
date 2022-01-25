class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        
        int n = arr.size();
        bool peakReached = false;
       
        for(int i = 1; i < n; i++)
        {
            if(!peakReached)
            {
                if(i+1 < n && arr[i] > arr[i-1] && arr[i] > arr[i+1])
                    peakReached = true;
                else if(arr[i] <= arr[i-1])
                    return false;
            }
            else 
            {
                if(arr[i] >= arr[i-1])
                    return false;
            }
        }
        
        return peakReached;
    }
};

/*
    Approach:- 
     Time: O(n), Space: O(1)
    
    - If the size of the array < 3, return false
    - Loop over the whole array from 1
        
        [2,0,2]
        
        If(!peakReached)
              If indNext < array size and curr > before and curr > next 
                peakReached = true
              Else if(curr == before)
                return false
        Else 
            if (cur >= before)
              return false
              
              
        return peakReached;
            
             
        

*/