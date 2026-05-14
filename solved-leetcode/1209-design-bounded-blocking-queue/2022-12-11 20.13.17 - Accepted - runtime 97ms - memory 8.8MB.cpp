// Time:  O(n)
// Space: O(1)

class BoundedBlockingQueue {
private:
    mutex m_;
    condition_variable cv;
    queue<int> q;
    int cap;

public:
    BoundedBlockingQueue(int capacity) { this->cap = capacity; }

    void enqueue(int element) {
        unique_lock<mutex> lck(m_);
        cv.wait(lck, [this]() { return q.size() != cap; });
        q.push(element);

        cv.notify_all();
    }

    int dequeue() {
        unique_lock<mutex> lck(m_);
        cv.wait(lck, [this]() { return !q.empty(); });
        int element = q.front();
        q.pop();

        cv.notify_all();
        return element;
    }

    int size() { return q.size(); }
};