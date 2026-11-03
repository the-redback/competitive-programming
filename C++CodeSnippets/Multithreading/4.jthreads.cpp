#include <iostream>
#include <thread>
#include <vector>
using namespace std;

void test(int x) {
    cout << "From Thread: " << x <<endl;
}

int main() {
    vector<jthread> threads;
    for (int i = 0; i < 10; i++) {
        threads.push_back(jthread(&test, 10));
    }

    cout << "From main Thread" << endl;

    return 0;
}
