class MedianFinder {
    priority_queue<int> low;                              // max heap
    priority_queue<int, vector<int>, greater<int>> high;  // min heap
public:
    MedianFinder() {}

    void addNum(int num) {
        low.push(num);
        high.push(low.top());
        low.pop();

        if (low.size() < high.size()) {
            low.push(high.top());
            high.pop();
        }
    }

    double findMedian() {
        if (low.size() != high.size()) return low.top();
        return (low.top() + high.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */