#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <atomic>
using namespace std;

atomic<int> sharedValue = 0;

void test(int x) {
    sharedValue++; // good
    // sharedValue = sharedValue + 1; //not good
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
