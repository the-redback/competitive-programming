#include <bits/stdc++.h>
using namespace std;

#ifdef redback
string to_string(char c) { return (string) "\'" + c + "\'"; }
string to_string(const string& s) { return '\"' + s + '\"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return b ? "true" : "false"; }
template <typename T, typename V>
string to_string(const pair<T, V>& p) {
    return '(' + to_string(p.first) + ' ' + to_string(p.second) + ')';
}
template <typename T>
string to_string(const T& a) {
    int    f = 0;
    string r;
    for (auto& i : a) r += (f++ ? " " : "") + to_string(i);
    return '{' + r + '}';
}

void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
    cerr << to_string(t);
    if (sizeof...(v)) cerr << ", ";
    _print(v...);
}
#define debug(a...)               \
    cerr << "[" << #a << "] = ["; \
    _print(a)
#else
#define debug(...)
#endif

int main() {
    int               n = 5;
    vector<int>       v = {1, 2, 3, 4};
    pair<int, string> p = {1, "codeforces"};
    debug(n, v, p);

    pair<int, int>             pa = {1, 2};
    pair<string, bool>         pb = {"abcd", false};
    pair<char, float>          pc = {'x', 0.5};
    string                     pd = "This is a string";
    pair<int, pair<int, int> > pe = {1, {2, 3}};
    debug(pa, pb, pc, pd, pe);

    vector<int>      va = {1, 2, 3, 4};
    set<int>         vb = {1, 2, 2, 3, 3, 4, 4, 5};
    map<string, int> vc;
    vc["string 1"] = 1;
    vc["string 2"] = 2;
    debug(va, vb, vc);
}