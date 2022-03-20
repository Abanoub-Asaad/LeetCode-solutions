class Solution {
public:
    
    void markCol(vector<vector<int>>& matrix, int x, int y) {
        int n = matrix.size();
        for(int i = 0; i < x; i++) {
            matrix[i][y] = 0;
        }
        for(int i = x; i < n; i++) {
            matrix[i][y] = 0;
        }
    }
    
    void markRow(vector<vector<int>>& matrix, int x, int y) {
        int m = matrix[0].size();
        for(int j = 0; j < y; j++) {
            matrix[x][j] = 0;
        }
        for(int j = y; j < m; j++) {
            matrix[x][j] = 0;
        }
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<string, vector<int>> markVect; //row: x,y  col: x,y
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == 0) {
                    string key = to_string(i)+"0"+"0"+to_string(j);
                    if(!markVect.count(key))
                        markVect[key] = {i, 0, 0, j};
                }
            }
        }
        
        for(auto i = markVect.begin(); i != markVect.end(); i++) {
            vector<int> curr = i->second;
            cout << curr[0] << " " << curr[1] << " " << curr[2] << " " << curr[3] << endl;
            markRow(matrix, curr[0], curr[1]);
            markCol(matrix, curr[2], curr[3]);
        }
    }
};


/*
    Time : O(N*M)
    Space: O(N*M)
    
    When I see a 0, I will mark all its neighbours as visited or make them zeroes
    
    111
    101
    111
    
    111
    100
    101
    
*/