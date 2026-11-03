#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
using namespace std;

mutex gLock;
condition_variable gCV;

void printFirst(int &state) {
    while (true) {
        unique_lock<mutex> lock(gLock);
        gCV.wait(lock, [&state] { return state == 1; });
        cout << "First" << endl;
        this_thread::sleep_for(chrono::seconds(1));
        state = 2;
        gCV.notify_all();
    }
}

void printSecond(int &state) {
    while (true) {
        unique_lock<mutex> lock(gLock);
        gCV.wait(lock, [&state] { return state == 2; });
        cout << "Second" << endl;
        this_thread::sleep_for(chrono::seconds(1));
        state = 3;
        gCV.notify_all();
    }
}

void printThird(int &state) {
    while (true) {
        unique_lock<mutex> lock(gLock);
        gCV.wait(lock, [&state]{return state == 3;});
        cout << "Third" << endl;
        this_thread::sleep_for(chrono::seconds(1));
        state = 1;
        gCV.notify_all();
    }
}

int main() {
    int state = 0;

    jthread t1(&printFirst, ref(state));
    jthread t2(&printSecond, ref(state));
    jthread t3(&printThird, ref(state));

    state = 1;
    gCV.notify_all();

    return 0;
}
