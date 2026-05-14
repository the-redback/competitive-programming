/**
 *                                   ____
 *       ____ ___  ____ ________  __/ __/
 *      / __ `__ \/ __ `/ ___/ / / / /_
 *     / / / / / / /_/ / /  / /_/ / __/
 *    /_/ /_/ /_/\__,_/_/   \__,_/_/
 *
 *    @link : https://the-redback.com
 */
#include <bits/stdc++.h>
using namespace std;

#define mem(a, b) memset(a, b, sizeof(a))
#define pb        push_back
#define pp        pop_back
#define inf       10000000
#define NN        5000
int dp[NN + 7][NN + 7];
string ss;
int call(int i, int j) {
    if (i >= j) return 1;
    int& tc = dp[i][j];
    if (tc != -1) return tc;
    if (ss[i] != ss[j]) return tc = 0;
    return tc = call(i + 1, j - 1);
}
class PalindromicSubstringsDiv2 {
public:
    int count(vector<string> S1, vector<string> S2) {
        int ret;
        int i, j;
        ss = "";
        for (i = 0; i < S1.size(); i++) ss += S1[i];
        for (i = 0; i < S2.size(); i++) ss += S2[i];
        ret = 0;
        mem(dp, -1);
        for (i = 0; i < ss.size(); i++) {
            for (j = i; j < ss.size(); j++) ret += call(i, j);
        }
        return ret;
    }

    // BEGIN CUT HERE
public:
    void run_test(int Case) {
        if ((Case == -1) || (Case == 0)) test_case_0();
        if ((Case == -1) || (Case == 1)) test_case_1();
        if ((Case == -1) || (Case == 2)) test_case_2();
        if ((Case == -1) || (Case == 3)) test_case_3();
    }

private:
    template <typename T>
    string print_array(const vector<T>& V) {
        ostringstream os;
        os << "{ ";
        for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\",";
        os << " }";
        return os.str();
    }
    void verify_case(int Case, const int& Expected, const int& Received) {
        cerr << "Test Case #" << Case << "...";
        if (Expected == Received)
            cerr << "PASSED" << endl;
        else {
            cerr << "FAILED" << endl;
            cerr << "\tExpected: \"" << Expected << '\"' << endl;
            cerr << "\tReceived: \"" << Received << '\"' << endl;
        }
    }
    void test_case_0() {
        string Arr0[] = {"a", "a", ""};
        vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        string Arr1[] = {"a"};
        vector<string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 6;
        verify_case(0, Arg2, count(Arg0, Arg1));
    }
    void test_case_1() {
        string Arr0[] = {"zaz"};
        vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        string Arr1[] = {};
        vector<string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 4;
        verify_case(1, Arg2, count(Arg0, Arg1));
    }
    void test_case_2() {
        string Arr0[] = {"top"};
        vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        string Arr1[] = {"coder"};
        vector<string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 8;
        verify_case(2, Arg2, count(Arg0, Arg1));
    }
    void test_case_3() {
        string Arr0[] = {};
        vector<string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        string Arr1[] = {"daata"};
        vector<string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 7;
        verify_case(3, Arg2, count(Arg0, Arg1));
    }

    // END CUT HERE
};

// BEGIN CUT HERE
int main() {
    PalindromicSubstringsDiv2 ___test;
    ___test.run_test(-1);
    int gbase;
    cin >> gbase;  // erase this line if you are not using dev-cpp! :)
    return 0;
}
// END CUT HERE
