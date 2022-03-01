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
        
        vector<vector<int>> ans;
        n = board.size();
        m = board[0].size();
        
        for(int i = 0; i < n; i++) 
        {
            vector<int> oneLine;
            for(int j = 0; j < m; j++) 
            {
                if(!board[i][j]) 
                {
                    if(getSumAround(board, i, j) == 3)
                        oneLine.push_back(1);
                    else
                        oneLine.push_back(0);
                } 
                else 
                {
                    if(getSumAround(board, i, j) < 2 || getSumAround(board, i, j) > 3)
                        oneLine.push_back(0);
                    else 
                        oneLine.push_back(1);
                }
            }
            ans.push_back(oneLine);
        }
        
        board = ans;
    }
};


/*

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