class BrowserHistory {
public:            
    
    string stack[5005];
    int curPtr, stackTop;
    
    BrowserHistory(string homepage) {
        stack[curPtr = stackTop = 0] = homepage;
    }
    
    void visit(string url) {
        stack[stackTop = ++curPtr] = url;
    }
    
    string back(int steps) {
        return stack[curPtr = max(0, curPtr-steps)];
    }
    
    string forward(int steps) {
        return stack[curPtr = min(stackTop, curPtr+steps)];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */