/***********************
Time: O(N+M)
Space: O(1)
************************/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i = m + n - 1;
        m--, n--;
        
        while(m >= 0 && n >= 0) {
            if(nums1[m] > nums2[n]) {
                nums1[i--] = nums1[m--];
            } else {
                nums1[i--] = nums2[n--];
            }   
        }
        while(n >= 0) {
            nums1[i--] = nums2[n--];
        }
    }
};


/***************************************************************************
 Another Solution
  Time: O((n+m)log(n+m))
  Space: O(1)
****************************************************************************
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = m, j = 0; i < n+m, j < n; i++, j++) {
            nums1[i] = nums2[j];
        }
        sort(nums1.begin(), nums1.end());
    }
};
****************************************************************************/