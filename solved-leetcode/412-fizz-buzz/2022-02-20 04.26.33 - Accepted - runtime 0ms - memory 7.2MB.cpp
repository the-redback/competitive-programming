#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> v(n);
        for (int i = 1; i <= n; i++) {
            if (!(i % 3)) v[i - 1] = "Fizz";
            if (!(i % 5)) v[i - 1] += "Buzz";
            if (v[i - 1] == "") v[i - 1] = to_string(i);
        }
        return v;
    }
};