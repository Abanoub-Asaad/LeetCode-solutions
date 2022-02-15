class Solution {
public:
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int n = arr.size();
        vector<int> ans;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        if(x < arr[0]) 
        {
            for(int i = 0; i < k; i++)
                ans.push_back(arr[i]);
        } 
        else if(x > arr[n-1]) 
        {
            for(int i = n-k; i < n; i++)
                ans.push_back(arr[i]);
        } 
        else 
        {
            for(int i = 0; i < n; i++)
            {
                if(pq.size() != k)
                    pq.push(arr[i]);
                else 
                {
                    if(abs(arr[i] - x) < abs(pq.top() - x))
                        pq.pop(), pq.push(arr[i]);
                }
            }
            
            while(pq.size())
                ans.push_back(pq.top()), pq.pop();
        }
        
        return ans;
    }
};



/*

    Draft: 
    
    When the question says, find k elements
    I think immediately of using a "priority queue"
    When the question says, the array is sorted
    I think immediately of using "Binary Search"
    
    [-1,1,2,4,5] k = 4, x = 3
    
    if x < arr[0]
        get the first k elements in the array
    if x > arr[n], while n is the index of the last element in the array
        get the last k elements in the array
    Otherwise
        x could be in the array or not
        if x existed(Search for x in the array using BS) in the array
            check if k is even or odd and check the boundaries
        if x doesn't exist in the array
            search for the first num that's less than k
            and search for the first num that's bigger than k
            take the less difference between both of them
            
            
    Edge case if there's more than x in the array
    
    
    minHeap   x = 5, k = 4, arr = [1,2,3,4,7]
    [1,2,3,4]
    
    When to pop from the heap, when the heap's size = k
    Compare first element in the heap to the next element in the array
    
    
    
    
*/