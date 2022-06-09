/************************************************************
  Time: O(N)
  Space: O(1)
************************************************************/
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int total = accumulate(begin(arr), end(arr), 0);
        int nPartitions = 0, partitionVal = total/3;
        int curPartSum = 0;
        int n = arr.size();
        
        if(total % 3 != 0)
            return false;
        
        for(int i = 0; i < n; i++) {
            curPartSum += arr[i];
            if(curPartSum == partitionVal) {
                nPartitions++;
                curPartSum = 0;
            }
            if(nPartitions == 3)
                return true;
        }
        
        return false;
    }
};