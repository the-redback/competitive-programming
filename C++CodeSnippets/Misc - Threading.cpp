#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
using namespace std;

// shared resource that will be updated
int sum = 0;

mutex lck;

// function to get sum of the vector elements in the given
// range
void getSum(const vector<int>& v, int start, int end)
{
    // a predefined wrapper over mutex lock
    //     lock_guard<mutex> mu(lck);   // DO not need the lock here.

    for (int i = start; i <= end; i++) {
        cout << "Thread ID: " << this_thread::get_id()
             << " adding v[" << i << "] = " << v[i] << endl;
        sum += v[i];
        this_thread::sleep_for(chrono::milliseconds(10));
    }
}

int main()
{
    vector<int> v;

    for (int i = 0; i < 100; i++) {
        v.push_back(i);
    }

    int mid = v.size() / 2;

    // creating two threads
    thread t1(getSum, v, 0, mid);
    thread t2(getSum, v, mid + 1, v.size() - 1);

    // waiting for threads to finish
    t1.join();
    t2.join();

    cout << "Sum: " << sum;

    return 0;
}
