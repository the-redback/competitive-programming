#include <bits/stdc++.h>
using namespace std;

// clang-format off
#ifdef redback //debugging macros
#define dbg(...) {cout << "Line " << __LINE__ << " => "; __f(#__VA_ARGS__, __VA_ARGS__);}
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {os << "{"; for (auto it = v.begin(); it != v.end(); ++it) {if (it != v.begin()) os << ", "; os << *it;} return os << "}";}
template <typename T> ostream& operator<<(ostream& os, const set<T>& v) {os << "["; for (auto it = v.begin(); it != v.end(); ++it) {if (it != v.begin()) os << ","; os << *it;} return os << "]";}
template <typename T1, typename T2> ostream& operator<<(ostream& os, const pair<T1, T2>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <typename T1, typename T2> ostream& operator<<(ostream& os, const map<T1, T2>& v) {os << "["; for (auto it = v.begin(); it != v.end(); ++it) {if (it != v.begin()) os << ", "; os << it->first << " = " << it->second;} return os << "]";}
template <typename T> void __f(const char* name, T&& arg1) {cout << name << " = " << arg1 << std::endl;}
template <typename T1, typename... Args> void __f(const char* names, T1&& arg1, Args&&... args) {const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " = " << arg1 << " | "; __f(comma + 1, args...);}
template <typename T> void __f(const char* name, T a[], int n) {cout << name << " = ["; for (int i = 0; i < n; ++i) cerr << a[i] << ' '; cerr << "]" << endl;}
#else
#define dbg(args...)
#endif
// clang-format on

int main() {
    int               n = 5;
    vector<int>       v = {1, 2, 3, 4};
    pair<int, string> p = {1, "codeforces"};
    dbg(n, v[0], p.first, p.second)
    dbg(v[1])

    pair<int, int>             pa = {1, 2};
    pair<string, bool>         pb = {"abcd", false};
    pair<char, float>          pc = {'x', 0.5};
    string                     pd = "This is a string";
    pair<int, pair<int, int> > pe = {1, {2, 3}};
    dbg(pa, pb, pc, pd, pe);
    dbg(n);
    dbg(v[0],n);

    vector<int>      va = {1, 2, 3, 4};
    set<int>         vb = {1, 2, 2, 3, 3, 4, 4, 5};
    map<string, int> vc;
    vc["string 1"] = 1;
    vc["string 2"] = 2;
    dbg(va, vb, vc);

    int arr[10];
    arr[0]=5;
    arr[1]=6;
    arr[2]=7;
    arr[3]=8;
    dbg(arr,n);

    char ch='c';
    dbg(ch);
}
