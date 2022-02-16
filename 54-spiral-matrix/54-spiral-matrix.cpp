class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        
        vector<int> output;
        int n_rows = arr.size(), n_cols = arr[0].size();
        int left = 0, right = n_cols-1;
        int top = 0, bottom = n_rows-1;
        
        while(left <= right && top <= bottom) 
        {
            // top row
            for(int i = left; i <= right; i++) {
                output.push_back(arr[top][i]);
            }
            
            top++;
            
            // most right col
            for(int i = top; i <= bottom; i++) {
                output.push_back(arr[i][right]);
            }
            
            right--;
            
            // bottom row
            if(top <= bottom) {
                for(int i = right; i >= left; i--) {
                    output.push_back(arr[bottom][i]);
                 }
                bottom--;
            }
            
            // most left col
            if(left <= right) {
                for(int i = bottom; i >= top; i--) {
                    output.push_back(arr[i][left]);
                 }
                left++;
            }
        }
        
        return output;
    }
};