class FreqStack {
public:
    
    /*
        Time: O(log n)
        Space: O(n)
        
        The hierarchy order:
            1. Frequency of the number
            2. Position 
            3. Element.
    */
    
    priority_queue<pair<int, pair<int, int>>> pq;
    unordered_map<int, int> freq;
    int pos = 0;
    
    void push(int val) {
        pq.emplace(++freq[val], make_pair(pos++, val));
    }
    
    int pop() {
        auto val = pq.top();
        pq.pop();
        int x = val.second.second;
        freq[x]--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */