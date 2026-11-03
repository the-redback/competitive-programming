#include <iostream>
#include <thread>
using namespace std;

void test(int x) {
    cout << "From Thread: " << x <<endl;
}

int main() {
    thread myThread(&test, 10);
    myThread.join();
    cout << "From main Thread" << endl;

    return 0;
}
