class Solution {
public:
    
    void dfs(vector<vector<int>>& grid, int i, int j) {
        
        if(min(i, j) < 0 || max(i, j) == grid.size() || grid[i][j] != 1)
            return;
        
        grid[i][j] = 2;
        
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
    }
    
    bool expand(vector<vector<int>>& grid, int i, int j, int cl) {
        if(min(i, j) < 0 || max(i, j) == grid.size())
            return false;
        
        grid[i][j] = grid[i][j] == 0 ? cl+1 : grid[i][j];
        
        return grid[i][j] == 1;
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        
        for(int i = 0, found = 0; !found && i < grid.size(); i++) {
            for(int j = 0; !found && j < grid[i].size(); j++) {
                if(grid[i][j] == 1) {
                    dfs(grid, i, j);
                    found = 1;
                }
            }
        }  
        
        for(int cl = 2; ; ++cl) 
        {
            for(int i = 0; i < grid.size(); i++) 
            {
                for(int j = 0; j < grid[i].size(); j++) 
                {
                    if(grid[i][j] == cl) 
                    {
                        if(expand(grid, i-1, j, cl) || expand(grid, i+1, j, cl) ||
                           expand(grid, i, j-1, cl) || expand(grid, i, j+1, cl))
                            return cl-2;
                    }   
                }
            }      
        }
        
        return {};
    }
};


/*

    Make the first component of 2's 

    0 -> water
    1 -> land
    
    0->1
 
    2 connected components in the graph
      of 1's 
    
    Get the shortest path between the two connected components
    From source to target  
    
    
    
    0 1 
    1 0
    
    0 2 0
    0 0 0
    0 0 1

    1 1 1 1 1 
    1 0 0 0 1
    1 0 1 0 1
    1 0 0 0 1
    1 1 1 1 1

*/