class Solution {
public:
    int numSquares(int n) {
        queue<int> q;
        q.push(n);
        int depth = 0;
        
        while(q.size()) 
        {
            depth++;
            int n = q.size();
            while(n--) 
            {
                int cur = q.front();
                q.pop();
                for(int i = 1; i <= cur; i++) 
                {
                    if(cur - (i*i) == 0)
                        return depth;
                    if(cur - (i*i) > 0)
                        q.push(cur - (i*i));
                    else 
                        break;
                }
            }
        }
        
        return depth;
    }
};

/*
    Push toReach each time after deleting perfect squares from it :)
*/