#include <iostream>
#include <string>
#include <deque>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <tuple>

using namespace std;

class Logger {
public:
    Logger() {}

    bool shouldPrintMessage(int timestamp, string message) {
        while (!dq.empty() && dq.front().first + 10 <= timestamp) {
            string s = dq.front().second;
            if (mp[s] == dq.front().first) mp.erase(s);
            dq.pop_front();
        }

        if (mp.find(message) != mp.end() && mp[message] + 10 > timestamp) return false;
        dq.push_back({timestamp, message});
        mp[message] = timestamp;

        return true;
    }

private:
    deque<pair<int, string>> dq;
    unordered_map<string, int> mp;
};

static bool _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */