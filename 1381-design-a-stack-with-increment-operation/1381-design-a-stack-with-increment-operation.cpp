class CustomStack {
public:
    
    int mxSize = 0;
    int curInd = -1;
    vector<int> st;
    
    CustomStack(int maxSize) { 
        mxSize = maxSize;
        vector<int> customStack(mxSize, -1);
        st = customStack;
    }
    
    void push(int x) {
        if(curInd+1 < mxSize)
            st[++curInd] = x;
    }
    
    int pop() {
        int topVal = -1;
        if(curInd != -1)
            topVal = st[curInd--];
        return topVal;
    }
    
    void increment(int k, int val) {
        if(k >= mxSize)
            k = mxSize;
        for(int i = 0; i < k; i++) 
            st[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */