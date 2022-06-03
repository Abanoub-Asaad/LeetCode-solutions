/**************************************
Q: #queries, N: #rows, M: #cols
    
    Time: O(Q*N)
    Space: O(N*M)
**************************************/

class NumMatrix {
public:
    
    vector<vector<int>> oldArr;
    vector<vector<int>> newArr;
    
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        oldArr = matrix;
        newArr.resize(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = m-2; j >= 0; j--) {
                newArr[i][j] = newArr[i][j+1] + oldArr[i][j+1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        while(row1 <= row2) {
            sum += newArr[row1][col1] + oldArr[row1][col1] - newArr[row1][col2];   
            row1++;
        }
        
        return sum;
    }
};


/*********** Draft ************

  oldArr
    3 0 1 4 2 
    5 6 3 2 1
    1 2 0 1 5
    4 1 0 1 7
    1 0 3 0 5
  
  newArr 
    7  7  6 2 0  
    12 6  3 1 0   12-3=9
    8  6  6 5 0   8-6=2
    9  8  8 7 0  
    8  8  5 5 0
    
    each value in the newArr is
     the sum of all the elements in the row after this element
     
    Algorithm is to iterate from row1 to row2
     and calculate sum from newArr[row1][col1] to newArr[row1][col2]

*******************************/