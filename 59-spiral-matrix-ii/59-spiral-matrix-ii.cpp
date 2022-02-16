class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> arr(n, vector<int> (n, 0));
        int cnt = 1;
        int n_rows = n, n_cols = n;
        int left = 0, right = n_cols-1;
        int top = 0, bottom = n_rows-1;
        
        while(left <= right && top <= bottom) 
        {
            // top row
            for(int i = left; i <= right; i++) {
                arr[top][i] = cnt, ++cnt;
            }
            
            top++;
            
            // most right col
            for(int i = top; i <= bottom; i++) {
                arr[i][right] = cnt, ++cnt;
            }
            
            right--;
            
            // bottom row
            if(top <= bottom) {
                for(int i = right; i >= left; i--) {
                    arr[bottom][i] = cnt, ++cnt;
                 }
                bottom--;
            }
            
            // most left col
            if(left <= right) {
                for(int i = bottom; i >= top; i--) {
                    arr[i][left] = cnt, ++cnt;
                 }
                left++;
            }
        }
        
        return arr;
    }
};



/*

    input: n = 3
    output: matrix of n*n = 1 to 9
        
    Output: [[1,2,3]
            ,[8,9,4]
            ,[7,6,5]]

    Go Right
    0,0 to 0,2
    1 to 3 
    
    Go Down
    0,2 to 2,2
    3 to 5
    
    Go Left 
    2,2 to 2,0
    5 to 7
    
    Go Up
    2,0 to 1,0
    7 to 8
    
    Go Right
    8 to 9

*/
