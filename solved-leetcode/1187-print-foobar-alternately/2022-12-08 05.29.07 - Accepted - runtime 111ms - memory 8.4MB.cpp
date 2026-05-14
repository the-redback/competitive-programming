#include <functional>

using namespace std;

#include <semaphore.h>

class FooBar {
private:
    int n;
    sem_t food;
    sem_t bart;

public:
    FooBar(int n) {
        this->n = n;
        sem_init(&food, 0, 0); /* added: */
        sem_init(&bart, 0, 1); /* added: */
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            sem_wait(&bart);
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            sem_post(&food);
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            sem_wait(&food);
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            sem_post(&bart);
        }
    }
};