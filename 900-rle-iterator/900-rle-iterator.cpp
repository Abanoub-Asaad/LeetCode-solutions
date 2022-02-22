class RLEIterator {
public:
    
    vector <int> arr;
    int ind;
    
    RLEIterator(vector<int>& encoding) {
        arr = encoding;
        ind = 0;
    }
    
    int next(int n) {
      
        while(ind < arr.size() && n > arr[ind]) {
            n -= arr[ind];
            ind += 2;
        }
        
        if(ind >= arr.size())
            return -1;
        
        arr[ind] -= n;
        return arr[ind+1];
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */