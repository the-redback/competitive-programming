class FreqStack {
    unordered_map<int, int> freq;
    unordered_map<int, stack<int> >m;
    int maxfreq = 0;
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        maxfreq = max(maxfreq, freq[val]);
        m[freq[val]].push(val);
    }
    
    int pop() {
        int val=m[maxfreq].top();
        m[maxfreq].pop();
        
        freq[val]--;
        if(m[maxfreq].size() == 0)
            maxfreq--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */