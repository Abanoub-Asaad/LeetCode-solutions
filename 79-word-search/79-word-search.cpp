class Solution {
public:
    
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int w_ind) {
    
        // Base cases
        if(min(i, j) < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[w_ind])
            return false;
        if(w_ind == word.size()-1)
            return true;

        char c = board[i][j];
        board[i][j] = '.';
        
        //directions: up, down, left, right
        bool ans = dfs(board, word, i-1, j, w_ind+1) || 
                   dfs(board, word, i+1, j, w_ind+1) || 
                   dfs(board, word, i, j-1, w_ind+1) || 
                   dfs(board, word, i, j+1, w_ind+1);
        
        board[i][j] = c;
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(dfs(board, word, i, j, 0))
                    return true;
             }
        }
    
        return false;
    }
};

/*
    Time: O(n * m * 4^N), N is the len of word
    Space: O(len(word)) which is O(N)
        
    base case: check if the curr pos is valid
    base case: if curr char in the board doesn't equal to the corresponding one in word
    base case: i reached my goal "target word"
    
    
    In the below lines, we are doing back tracking not to be in a finite loop
     char c = board[i][j];
     board[i][j] = '.';
    
    
    -----
    |A|B|
    -----
    |C|D|
    -----   word = "AC"
    Recursive problem
    
    [["A","B","C","E"],
     ["S","F","E","S"],
     ["A","D","E","E"]]

    "ABCESEEEFS" true
*/