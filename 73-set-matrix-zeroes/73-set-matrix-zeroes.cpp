class Solution {
public:
    
    void markZeroes(vector<vector<int>>& matrix, int x, int y) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int j = 0; j < y; j++) {
            matrix[x][j] = 0;
        }
        for(int j = y+1; j < m; j++) {
            matrix[x][j] = 0;
        }
        for(int i = 0; i < x; i++) {
            matrix[i][y] = 0;
        }
        for(int i = x+1; i < n; i++) {
            matrix[i][y] = 0;
        }
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> helperArr = matrix;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == 0)
                    markZeroes(helperArr, i, j);
            }
        }
        matrix = helperArr;
    }
};


/*
    Time : O(N*M)
    Space: O(N*M)
    
    When I see a 0, I will mark all its neighbours as visited or make them zeroes
    
    111
    100
    100
    
*/