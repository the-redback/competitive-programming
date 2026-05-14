class MyCircularQueue {
    vector<int> q;
    int head, tail;
    int count;
    int capacity;

public:
    MyCircularQueue(int k) {
        capacity = k;
        count = 0;
        q.resize(k);
        head = 0;
    }

    bool enQueue(int value) {
        if (count == capacity) return false;
        int index = (head + count) % capacity;
        q[index] = value;
        count++;
        return true;
    }

    bool deQueue() {
        if (count == 0) return false;
        head = (head + 1) % capacity;
        count--;
        return true;
    }

    int Front() {
        if (count == 0) return -1;
        return q[head];
    }

    int Rear() {
        if (count == 0) return -1;
        int index = (head + count - 1) % capacity;

        return q[index];
    }

    bool isEmpty() { return count == 0; }

    bool isFull() { return count == capacity; }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */