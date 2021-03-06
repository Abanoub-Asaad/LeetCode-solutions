class Solution {
public:
    
    //  000
    //  010
    //  000
        
    int n, m;
    
    int getSumAround(vector<vector<int>>& board, int i, int j) {
        
        int cnt = 0;
        
        if(i-1 >= 0 && j-1 >= 0 && board[i-1][j-1])
            ++cnt;
        if(i-1 >= 0 && board[i-1][j])
            ++cnt;
        if(i-1 >= 0 && j+1 < m && board[i-1][j+1])
            ++cnt;
        if(j-1 >= 0 && board[i][j-1])
            ++cnt;
        if(j+1 < m && board[i][j+1])
            ++cnt;
        if(i+1 < n && j-1 >= 0 && board[i+1][j-1])
            ++cnt;
        if(i+1 < n && board[i+1][j])
            ++cnt;
        if(i+1 < n && j+1 < m && board[i+1][j+1])
            ++cnt;
        
        return cnt;
    } 
    
    void gameOfLife(vector<vector<int>>& board) {
        
        vector<vector<int>> ans = board;
        n = board.size();
        m = board[0].size();
        
        for(int i = 0; i < n; i++) 
        {
            for(int j = 0; j < m; j++) 
            {
                int around = getSumAround(board, i, j);
                if(!board[i][j]) 
                {
                    if(around == 3)
                        ans[i][j] = 1;
                } 
                else 
                {
                    if(around < 2 || around > 3)
                        ans[i][j] = 0;
                }
            }
        }
        
        board = ans;
    }
};


/*

    The Brute force solution:
        Time: O(N*M)
        Space: O(N*m)
        
    I need to optimize the space to change the given array in place
        
    Caring about boundaries is important in this problem

    DRAFT
    
    live -> 1
    dead -> 0
    
    rules:
    - any live cell with < 2 live neighbours, it dies
    - any live cell with 2 or 3 live neighbours, it lives on the next gene
    - any live cell with > 3 live neighbours, it dies
    - any dead cell with 3 live neighbours, it lives
    
    010     000
    001 ->  101 
    111 ->  011
    000     01
    

*/