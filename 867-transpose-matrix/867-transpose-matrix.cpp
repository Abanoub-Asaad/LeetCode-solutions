class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> transMatrix;
        for(int col = 0; col < m; col++) {
            vector<int> arr;
            for(int row = 0; row < n; row++) {
                arr.push_back(matrix[row][col]);
            }
            transMatrix.push_back(arr);
        }
        
        return transMatrix;
    }
};

/*******************
    Time: O(N*M)
    Space: O(N*M)

*********************/