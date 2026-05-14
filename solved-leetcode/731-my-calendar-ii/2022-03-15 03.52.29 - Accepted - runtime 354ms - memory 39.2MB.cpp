class MyCalendarTwo {
public:
    MyCalendarTwo() {}

    bool book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int sum = 0;
        for (auto x : mp) {
            sum += x.second;
            if (sum >= 3) {
                mp[start]--;
                mp[end]++;
                return false;
            }
        }
        return true;
    }

private:
    map<int, int> mp;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */

static bool _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
