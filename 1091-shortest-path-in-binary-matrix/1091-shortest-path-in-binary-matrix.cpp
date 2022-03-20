class Solution {
public:
    
    int bfs(vector<vector<int>>& grid, int s_x, int s_y) {
        
        vector<vector<int>> directions = {{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};
        int n = grid.size();
        int depth = 0;
        queue<pair<int, int>> q;
        unordered_set<string> visited;
        q.push({s_x, s_y});
        
        while(q.size()) 
        {
            int m = q.size();
            depth++;
            while(m--)
            {
                pair<int, int> curr = q.front();
                q.pop();
                int x = curr.first, y = curr.second;
                if(x == n-1 && y == n-1)
                    return depth;
                    
                for(auto dir : directions) 
                {
                    int cur_x = x + dir[0];
                    int cur_y = y + dir[1];
                    
                    string key = to_string(cur_x)+","+to_string(cur_y);
                    if(min(cur_x, cur_y) >= 0 && max(cur_x, cur_y) < n && grid[cur_x][cur_y] == 0 && !visited.count(key))
                        q.push({cur_x, cur_y}), visited.insert(key);
                }   
            }
        }
        
        return -1;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] || grid[n-1][n-1])
            return -1;
        return bfs(grid, 0, 0);
    }
};

/*
    Return the length of the "shortest clear path"
    if there's no clear path, return -1
    I can only visit cills that have 0's
    I can move 8-directionally
    
    100
    110
    110
    
    BFS
    start is (0,0), target is (n-1,n-1)
    
    queue<pair<int, int>> q;
    q.push({0,0});
    
    I don't need to have a visited array
*/