/********************************************************************************************
 Algorithm: Greedy approach using Max Heap
 Steps: 1. sort courses on basis of last day 
        2. iterate to sum up the durations
        3. if sumDays + dur <= lastDay, use this course and add its duration to the max heap
        4. if i can't take the current course but its duration is less than a previous 
           course that i've taken, so i will update the current sum and the heap.
        
 Time: O(N log N)
 Space: O(N)
********************************************************************************************/
class Solution {
public:
    
    static bool comp(vector<int> &course1, vector<int> &course2) {
        return course1[1] < course2[1];
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), comp);
        int n = courses.size();
        int sumDays = 0;
        priority_queue<int> durations;
        for(int i = 0; i < n; i++) {
            int dur = courses[i][0];
            int lastDay = courses[i][1];
            if(sumDays + dur <= lastDay) {
                sumDays += dur;
                durations.push(dur);
            } else if(durations.size() && dur < durations.top()) {
                sumDays -= durations.top();
                durations.pop();
                sumDays += dur;
                durations.push(dur);
            }
        }
        
        return durations.size();
    }
};