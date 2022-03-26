class Solution {
public:
    
    vector<vector<int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    
    void bfs(vector<vector<int>>& heights, int i, int j, vector<vector<int>> &ocean, vector<vector<int>> &visited) {
        int m = heights.size();
        int n = heights[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = 1;
        
        while(q.size()) {
            int q_size = q.size();
            while(q_size--) {
                pair<int, int> curr = q.front();
                q.pop();
                int curX = curr.first;
                int curY = curr.second;
                
                ocean[curX][curY] = 1;
                
                for(auto dir : directions) {
                    int x = curX + dir[0];
                    int y = curY + dir[1];
                    
                    if(x < m && y < n && min(x,y) >= 0 && heights[x][y] >= heights[curX][curY] && !visited[x][y])
                        q.push({x,y}), visited[x][y] = 1;
                }
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> pacificAtlanticArr;
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));
        vector<vector<int>> visitedPacific(m, vector<int>(n, 0));
        vector<vector<int>> visitedAtlantic(m, vector<int>(n, 0));
        
        //first row, pacific
        for(int col = 0; col < n; col++) {
            bfs(heights, 0, col, pacific, visitedPacific);
        }
        
        //first col, pacific
        for(int row = 0; row < m; row++) {
            bfs(heights, row, 0, pacific, visitedPacific);
        }
        
        //last row, atlantic
        for(int col = 0; col < n; col++) {
            bfs(heights, m-1, col, atlantic, visitedAtlantic);
        }
        
        //last col, atlantic
        for(int row = 0; row < m; row++) {
            bfs(heights, row, n-1, atlantic, visitedAtlantic);
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(pacific[i][j] == 1 && atlantic[i][j] == 1)
                    pacificAtlanticArr.push_back({i,j});
            }
        }
        
        return pacificAtlanticArr;
    }
};

/**************************
    Brute force approach
     Time: O(M^2 * N^2)
     Space: O(M*N)
    --------------------  
    Optimized approach
     Time: O(M*N)
     Space: O(M*N)

***************************/