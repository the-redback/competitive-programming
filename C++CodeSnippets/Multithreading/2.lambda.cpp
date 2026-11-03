#include <iostream>
#include <thread>
using namespace std;

int main() {

    auto lambda = [](int x) {
        cout << "From Thread: " << x <<endl;
    };
    thread myThread(lambda, 10);
    myThread.join();
    cout << "From main Thread" << endl;

    return 0;
}
