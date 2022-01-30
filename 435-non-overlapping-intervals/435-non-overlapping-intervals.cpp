class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int ans = 0, n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int l = 0, r = 1;
        
        while(r < n)
        {
            if(intervals[l][1] <= intervals[r][0]) //case 1
            {
                l = r;
                r++;
            }
            else if(intervals[l][1] <= intervals[r][1]) // case 2
            {
                ans++;
                r++;
            }
            else if(intervals[l][1] > intervals[r][1]) //case 3
            {
                ans++;
                l = r;
                r++;
            }
        }
        
        return ans;
    }
};


/*
  Case 1:-
   ------------------   -----------------
   |   Interval 1   |   |   Interval 2  |
   ------------------   -----------------

  Case 2:-
   ------------------
   |   Interval 1   |
   ------------------
              ------------------
              |    Interval 2  |
              ------------------

  Case 3:-
    --------------------
    |    Interval 1    |
    --------------------
      --------------
      | Interval 2 |
      --------------


*/