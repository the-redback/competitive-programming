#include <iostream>
#include <string>
#include <tuple>

using namespace std;

class Solution {
public:
    bool canTransform(string start, string end) {
        int e = 0, i = 0;
        for (; i < start.size(); i++, e++) {
            while (i < start.size() && start[i] == 'X') i++;
            while (e < end.size() && end[e] == 'X') e++;
            if (i >= start.size() || e >= end.size()) break;

            if (start[i] != end[e]) return false;
            if (start[i] == 'L' && i < e) return false;
            if (start[i] == 'R' && i > e) return false;
        }
        while (i < start.size() && start[i] == 'X') i++;
        while (e < end.size() && end[e] == 'X') e++;

        return i == e;
    }
};

static bool _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
