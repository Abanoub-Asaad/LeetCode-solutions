class Solution {
public:
    
    int bfs(vector<vector<int>>& grid, int s_x, int s_y) {
        
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
                    
                
                string key = to_string(x-1)+","+to_string(y-1);
                if(x-1 >= 0 && y-1 >= 0 && grid[x-1][y-1] == 0 && !visited.count(key))
                    q.push({x-1, y-1}), visited.insert(key);
                
                key = to_string(x-1)+","+to_string(y);
                if(x-1 >= 0 && grid[x-1][y] == 0 && !visited.count(key))
                    q.push({x-1, y}), visited.insert(key);
                
                key = to_string(x-1)+","+to_string(y+1);
                if(x-1 >= 0 && y+1 < n && grid[x-1][y+1] == 0 && !visited.count(key))
                    q.push({x-1, y+1}), visited.insert(key);
                
                key = to_string(x)+","+to_string(y-1);
                if(y-1 >= 0 && grid[x][y-1] == 0 && !visited.count(key))
                    q.push({x, y-1}), visited.insert(key);
                
                key = to_string(x)+","+to_string(y+1);
                if(y+1 < n && grid[x][y+1] == 0 && !visited.count(key))
                    q.push({x, y+1}), visited.insert(key);
                
                key = to_string(x+1)+","+to_string(y-1);
                if(x+1 < n && y-1 >= 0 && grid[x+1][y-1] == 0 && !visited.count(key))
                    q.push({x+1, y-1}), visited.insert(key);
                
                key = to_string(x+1)+","+to_string(y);
                if(x+1 < n && grid[x+1][y] == 0 && !visited.count(key))
                    q.push({x+1, y}), visited.insert(key);
                
                key = to_string(x+1)+","+to_string(y+1);
                if(x+1 < n && y+1 < n && grid[x+1][y+1] == 0 && !visited.count(key))
                    q.push({x+1, y+1}), visited.insert(key);
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