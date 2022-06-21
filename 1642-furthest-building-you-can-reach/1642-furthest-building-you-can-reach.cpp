/********************************************************************************
  Algorithm: Use Heap "max heap"
      To get the max number of buildings, you have to use the ladders for the
      biggest differences between buildings to save as many bricks as possible.
      
  Time: O(N log N)
  Space: o(N)
********************************************************************************/
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> diffs;
        int diff = 0, i = 1;
        int n = heights.size();
        
        for(; i < n; i++) {
            diff = heights[i] - heights[i-1];
            if(diff > 0) {
                diffs.push(diff);
                bricks -= diff;
                //if there are available ladders but no bricks
                if(bricks < 0 && ladders) {
                    ladders--;
                    bricks += diffs.top();
                    diffs.pop();
                } else if(bricks < 0 && ladders <= 0) { // no way
                    break;
                }
            }
        }
        
        return --i;
    }
};