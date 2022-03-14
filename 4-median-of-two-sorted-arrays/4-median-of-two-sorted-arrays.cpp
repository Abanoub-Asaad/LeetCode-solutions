class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int sz = nums1.size()+nums2.size();
        bool medianIsEven = (sz & 1) ? 0 : 1;
        int p1 = 0, p2 = 0, cnt = -1;
        int ind1 = sz/2; 
        int ind2 = (medianIsEven) ? sz/2-1 : -1;  
        int val1 = 0, val2 = 0;
        
        while(p1 < nums1.size() && p2 < nums2.size()) 
        {
            cnt++;  
            if(nums1[p1] < nums2[p2]) 
            {
                if(ind1 == cnt)
                    val1 = nums1[p1]; 
                else if(ind2 == cnt)
                    val2 = nums1[p1];
                p1++;
            } 
            else 
            {
                if(ind1 == cnt)
                    val1 = nums2[p2]; 
                else if(ind2 == cnt)
                    val2 = nums2[p2];
                p2++;
            }
        }
        
        while(p1 == nums1.size() && p2 < nums2.size())
        {
            cnt++; 
            if(ind1 == cnt)
                val1 = nums2[p2]; 
            else if(ind2 == cnt)
                val2 = nums2[p2];
            p2++;
        }
        
        while(p2 == nums2.size() && p1 < nums1.size())
        {
            cnt++;
            if(ind1 == cnt)
                val1 = nums1[p1]; 
            else if(ind2 == cnt)
                val2 = nums1[p1];
            p1++;
        }
        
        return (medianIsEven) ? (val1+val2)/2.0 : val1; 
    }
};


/*--------------------------------------------------
    Time: O(m+n)
    Space: O(1)

    Since the two arrays are sorted, we can use 2 pointers through both of the arrays
     and compare nums1[p1] to nums2[p2] and then increase the pointers based on that.
     
    The implementation is above.
--------------------------------------------------*/



/*----------------------------------------------------------------------------
    Time: O(m+n)log(m+n)
    Space: O(m+n)
    
    - put all the elements into a new array 
    - sort the new array
    - get the median
    
    The implementation is below.
    ----------------------------------------------------------------------------
    class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mergedArr;
        for(auto i : nums1)
            mergedArr.push_back(i);
        for(auto i : nums2)
            mergedArr.push_back(i);
        
        int sz = mergedArr.size();
        sort(mergedArr.begin(), mergedArr.end());
        bool medianIsEven = (sz & 1) ? 0 : 1;
        
        return (medianIsEven) ? (mergedArr[sz/2]+mergedArr[sz/2-1])/2.0 : mergedArr[sz/2]; 
    }
};
----------------------------------------------------------------------------*/