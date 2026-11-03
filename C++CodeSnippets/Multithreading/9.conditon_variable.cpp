#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

mutex gLock;
condition_variable gCV;

void reporter(int &result, bool &notified) {
    unique_lock<mutex> lock(gLock);
    while (!notified) {
        gCV.wait(lock);
    }
    cout << "Result is: " << result << endl;
}

void worker(int &result, bool &notified) {
    unique_lock<mutex> lock(gLock);

    result = 24 + 10 + 121;
    notified = true;
    this_thread::sleep_for(chrono::milliseconds(3000));
    cout << "work is done" << endl;
    gCV.notify_all();
}

int main() {
    int result = 0;
    bool notified = false;

    thread t1(&worker, ref(result), ref(notified));
    thread t2(&reporter, ref(result), ref(notified));

    t1.join();
    t2.join();

    return 0;
}
