class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n = matrix.size(), ans; 
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;
        
        for (int r = 0; r < min(n, k); ++r)
            minHeap.push({matrix[r][0], r, 0});

        for (int i = 1; i <= k; ++i) 
        {
            auto top = minHeap.top(); 
            minHeap.pop();
            int r = top[1], c = top[2];
            ans = top[0];
            
            if (c + 1 < n) 
                minHeap.push({matrix[r][c + 1], r, c + 1});
        }
        
        return ans;
    }
};

/*
    1st Approach:- Time: O(n^2), Space: O(n^2)
    
     - Loop over the whole matrix
     - Store all the elements in a one d array
     - Sort the new array 
     - Find the required element easily.
      
      
      class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        vector<int> arr;
        int n = matrix.size();
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                arr.push_back(matrix[i][j]);
            
        sort(arr.begin(), arr.end());
        
        return arr[k-1];
    }
};
      
      
      
--------------------------------------
    2nd Approach:- Time: O(n^2 log k), Space: O(k)
    
      - Loop over the whole matrix 
      - Create a maxHeap to store the elements
         If maxHeap.size > k, maxHeap.pop
      - Reture maxHeap.top
         

          matrix = [[1,5,9],
                    [2,11,13],
                    [12,13,15]],     

          maxHeap = [13,13,12,11,9,5,2,1]

                heap.size = 8
                k = 8
                
                
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        vector<int> arr;
        int n = matrix.size();
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                arr.push_back(matrix[i][j]);
            
        sort(arr.begin(), arr.end());
        
        return arr[k-1];
    }
};
                
                
                
--------------------------------------
    3rd Approach:- Time: O(k log k), Space: O(k)
    
      - Use Min Heap
            
    matrix = [[1,5,9],
              [10,11,13],
              [12,13,15]],   n = 3, k = 8
              
    minHeap:  
    
    if c+1 < n
        minHeap({matrix[r][c+1], r, c+1})
        
        return ans

*/