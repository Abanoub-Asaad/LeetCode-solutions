class Solution {
public:
    
    //Time: O(N^2)
    //Space: O(N^2)
    
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    unordered_map<int, int> map; //key: islandID, value: islandSum
    
    int bfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>> &visited, int islandID) {
        int n = grid.size();
        int oneIslandSize = 0;
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = islandID;
        
        while(q.size()) 
        {
            int m = q.size();
            while(m--) 
            {
                pair<int, int> curr = q.front();
                q.pop();
                oneIslandSize++;
                int curX = curr.first;
                int curY = curr.second;
                
                for(auto &dir : directions) 
                {
                    int x = curX + dir[0];
                    int y = curY + dir[1];
                    if(min(x,y) >= 0 && max(x,y) < n && grid[x][y] == 1)
                        q.push({x,y}), grid[x][y] = islandID;
                }
            }
        }
        
        return oneIslandSize;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int islandID = 2;
        int mxIsland = 1;
        bool zeroFound = 0;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    int curSum = bfs(grid, i, j, visited, islandID);
                    map[islandID] = curSum;
                    islandID++;
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    unordered_set<int> uniIds;
                    zeroFound = 1;
                    int curSum = 1;
                    for(auto &dir : directions) {
                        int x = i + dir[0];
                        int y = j + dir[1];
                        
                        if(min(x,y) >= 0 && max(x,y) < n && !uniIds.count(grid[x][y]))
                            curSum += map[grid[x][y]], uniIds.insert(grid[x][y]);
                    }
                    mxIsland = max(mxIsland, curSum);
                }
            }
        }
        return (zeroFound) ? mxIsland : n*n;
    }
};

