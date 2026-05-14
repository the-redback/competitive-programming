#include <queue>
#include <mutex>
#include <condition_variable>

using namespace std;

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
    ~BoundedBlockingQueue() { q = queue<int>(); }

    void enqueue(int element) {
        {
            unique_lock<mutex> lck(m_);
            cv.wait(lck, [this] { return q.size() != cap; });
            q.push(element);
        }
        cv.notify_one();
    }

    int dequeue() {
        int element;
        {
            unique_lock<mutex> lck(m_);
            cv.wait(lck, [this] { return !q.empty(); });
            element = q.front();
            q.pop();
        }
        cv.notify_one();
        return element;
    }

    int size() { return q.size(); }
};