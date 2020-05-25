/**
 *    author:  tourist
 *    created: 02.09.2018 18:26:55
 **/
#include <bits/stdc++.h>

using namespace std;

// debugging reference: https://codeforces.com/contest/1037/submission/42390789
string to_string(string s) { return '"' + s + '"'; }

string to_string(const char* s) { return to_string((string)s); }

string to_string(bool b) { return (b ? "true" : "false"); }

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
    bool   first = true;
    string res   = "{";
    for (const auto& x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef redback
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

// http://e-maxx.ru/algo/ukkonen

int main() {
    int               n = 5;
    vector<int>       v = {1, 2, 3, 4};
    pair<int, string> p = {1, "codeforces"};
    debug(n, v, p);
}
