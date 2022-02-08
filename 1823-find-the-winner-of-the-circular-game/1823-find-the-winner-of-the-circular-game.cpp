class Solution {
public:
    int findTheWinner(int n, int k) {
        
        queue<int> q;
        
        for(int i = 1; i <= n; i++)
            q.push(i);
            
        while(q.size() != 1)
        {
            int limit = k;
            while(--limit)
            {
                int element = q.front();
                q.pop();
                q.push(element);
            }
            q.pop();
        }
        
        return q.front();
    }
};