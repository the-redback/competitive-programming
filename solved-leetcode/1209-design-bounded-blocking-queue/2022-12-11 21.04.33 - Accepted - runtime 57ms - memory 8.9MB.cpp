#include <queue>
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

// int main() {
//   BoundedBlockingQueue bbq(3);
//   vector<thread> threads;
//   for (int i=0; i<15; ++i) {
//     threads.emplace_back(&BoundedBlockingQueue::dequeue, ref(bbq));
//   }

//   for (int i=0; i<15; ++i) {
//     threads.emplace_back(&BoundedBlockingQueue::enqueue, ref(bbq), i);
//   }

//   for(auto &t: threads)
//     t.join();
// }
