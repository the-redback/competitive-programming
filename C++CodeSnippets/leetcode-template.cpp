#include <iostream>
#include <tuple>
using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
};

// Fast I/O; 4 ms. Just add the following line

static int noio = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

static bool _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
