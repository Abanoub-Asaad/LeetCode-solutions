class MinStack {
public:
    
    stack<int> st, mins;
    int mn = INT_MAX;
    
    MinStack() {
        
    }
    
    void pushToMins(int val) {
        if(mins.size())
            mins.push(min(mins.top(),val));
        else 
            mins.push(min(mn, val));
    }
    
    void push(int val) {
        st.push(val);
        pushToMins(val);
    }
    
    void pop() {
        st.pop();
        mins.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mins.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */