class MedianFinder {
    multiset<int>m;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        m.insert(num);
    }
    
    double findMedian() {
        auto mid = next(m.begin(), m.size() / 2);
        return ((double) *mid + *next(mid, m.size() % 2 - 1)) * 0.5;

    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */