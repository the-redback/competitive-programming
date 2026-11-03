#include <iostream>
#include <thread>
#include <vector>
using namespace std;

void test(int x) {
    cout << "From Thread: " << x <<endl;
}

int main() {
    vector<thread> threads;
    for (int i = 0; i < 10; i++) {
        threads.push_back(thread(&test, 10));
    }

    for (int i = 0; i < 10; i++) {
        threads[i].join();
    }
    cout << "From main Thread" << endl;

    return 0;
}
