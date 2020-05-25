#include <bits/stdc++.h>
using namespace std;

// clang-format on
#ifdef redback //debugging macros
#include "prettyprint.hpp"
#define debug(...) {cout << "L-" << __LINE__ << " :: "; __f(#__VA_ARGS__, __VA_ARGS__);} 
template <typename T> void __f(const char* name, T&& arg1) {cout << name << " = " << arg1 << std::endl;}
template <typename T1, typename... Args> void __f(const char* names, T1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " = " << arg1 << " | "; __f(comma + 1, args...);}
template <typename T> void __f(const char* name, T a[], int n) {cout << name << " = "<< pretty_print_array(a,n) << endl;}
#else 
#define debug(args...) 
#endif
// clang-format on

int main() {
    int               n = 5;
    vector<int>       v = {1, 2, 3, 4};
    pair<int, string> p = {1, "codeforces"};
    debug(n, v[0], p.first, p.second);
    debug(v[1]);

    pair<int, int>             pa = {1, 2};
    pair<string, bool>         pb = {"abcd", false};
    pair<char, float>          pc = {'x', 0.5};
    string                     pd = "This is a string";
    pair<int, pair<int, int> > pe = {1, {2, 3}};
    debug(pa, pb, pc, pd, pe);
    debug(n);
    debug(v[0], n);

    vector<int>      va = {1, 2, 3, 4};
    set<int>         vb = {1, 2, 2, 3, 3, 4, 4, 5};
    map<string, int> vc;
    vc["string 1"] = 1;
    vc["string 2"] = 2;
    debug(va);
    debug(vb);
    debug(vc);

    int arr[10];
    arr[0] = 5;
    arr[1] = 6;
    arr[2] = 7;
    arr[3] = 8;
    debug(arr, n);
    debug(arr);

    char ch = 'c';
    debug(ch);

    long long i = 10, j = 9, k = 45, l = 4, m = 23;
    debug(i, j, k, l, m);
    // cout<<pretty_print_array(arr, 4);
}
