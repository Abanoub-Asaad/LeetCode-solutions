class Solution {
public:
    
    int doWork(vector<vector<int>>& grid) {
        
        int rows = grid.size(), cols = grid[0].size();
        int minMinutes = 0;
        queue<pair<int, int>> q;
        
        //push all fruits' indices that are rotten
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        
        //Do BFS to extend the rottenness
        while(q.size()) 
        {
            int n = q.size();
            int foundFresh = 0;
            while(n--) 
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                
                if(i-1 >= 0 && grid[i-1][j] == 1)
                    q.push({i-1, j}), grid[i-1][j] = 2, foundFresh = 1;
                if(i+1 < rows && grid[i+1][j] == 1)
                    q.push({i+1, j}), grid[i+1][j] = 2, foundFresh = 1;
                if(j-1 >= 0 && grid[i][j-1] == 1)
                    q.push({i, j-1}), grid[i][j-1] = 2, foundFresh = 1;
                if(j+1 < cols && grid[i][j+1] == 1)
                    q.push({i, j+1}), grid[i][j+1] = 2, foundFresh = 1;
            }
            minMinutes += foundFresh;
        }
        
        return minMinutes;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        int ans = doWork(grid);
        
        for(auto row : grid) {
            for(auto fruit : row) {
                if(fruit == 1)
                    return -1;
            }
        }
        
        return ans; 
    }
};


/*  
    Time: O(N*M)
    Space: O(N*M)
    
    BFS
    because I'll go level by level
    
    
    
    2 1 1 
    1 1 0
    0 1 2
    
    first level has the coordination of the rotten fruits
    
    Make a queue of pairs q
     [(0,0), (2,2)]
    
    n = q.size()
    
    while(n--)
    {
        ++minutes
        cur = q.front()
        q.pop
        // push all the valid pairs
        q.push((0,1), (1,0))
        // what i pushed, i should make its value 2
    }
    
    after doing my bfs, i will check the whole matrix if there's any ones
    if there, return -1
    else return minutes

*/