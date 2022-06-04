/*****************************
  Time Complexity: O(N^3)
  Space Complexity: O(N^3)
******************************/

class Solution {
public:
    
    //check if I can put a queen in this col or not
    bool isValidCol(int row, int col, vector<string> &board) {
        while(--row >= 0) {
            if(board[row][col] == 'Q')
                return false;
        }
        return true;
    }
    
    //check if the diagonal doesn't have a queen already
    bool isValidDiag(int row, int col, vector<string> &board) {
        
        int curRow = row, curCol = col;
        
        //go top left
        while(--row >= 0 && --col >= 0) {
            if(board[row][col] == 'Q')
                return false;
        }
        
        //go top right
        while(--curRow >= 0 && ++curCol >= 0) {
            if(board[curRow][curCol] == 'Q')
                return false;
        }
        
        return true;
    }
    
    void dfs(int row, vector<string> board, vector<vector<string>> &ans) {
        
        int n = board.size();
        
        //base case
        if(row == n){
            ans.push_back(board);
            return;
        }
        
        //iterate every possible position
        for(int col = 0; col < n; col++) {
            if(isValidCol(row, col, board) && isValidDiag(row, col, board)) {
                board[row][col] = 'Q';
                dfs(row+1, board, ans);
                board[row][col] = '.'; //backtrack
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));        
        dfs(0, board, ans);
        
        return ans;
    }
};