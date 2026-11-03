#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

mutex gLock;
int sharedValue = 0;

void test(int x) {
    gLock.lock();
        sharedValue++;
    gLock.unlock();
}

int main() {
    vector<thread> threads;
    for (int i = 0; i < 1000; i++) {
        threads.push_back(thread(&test, 10));
    }

    for (int i = 0; i < 1000; i++) {
        threads[i].join();
    }

    cout << "Shared Value " << sharedValue << endl;

    return 0;
}
