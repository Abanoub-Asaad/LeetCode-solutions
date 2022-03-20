class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> arr(n, vector<int>(n,0));
        int x = n-1, y = 0;
        int i = 0, j = 0;
        
        while(i < n) {
            while(j < n) {
                arr[i][j] = matrix[x][y];
                x--;
                j++;
            }
            i++, y++;
            x = n-1, j = 0;
        }
        matrix=arr;
    }
};

/*

    Time: O(N^2), Space: O(N^2)
    
    1 2 3 
 ^  4 5 6
 |  7 8 9
         
  
  -->
    7 4 1 
    8 5 2 
    9 6 3
    
    
    i = 0, j = 0
    j++;
    
    --> i++
    
    
    int x = n-1, y = 0;
    x--;
    
    --> y++
    
    
    int x = n-1, y = 0;
    int i = 0, j = 0;
    while(i < n && y < n) 
    {
        while(j < n && x > -1) 
        {
            arr[i][j] = matrix[x][y];
            x--;
            j++;
        }
        i++;
        y++;
        x = n-1, j = 0;
    }
    
*/