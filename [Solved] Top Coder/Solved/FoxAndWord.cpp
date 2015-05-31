/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @TOPCODER   : the_redback
 *    @CodeForces : maruf.2hin
 *    @UVA        : Redback
 *    @link       : http://www.fb.com/maruf.2hin
 *
 */
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
using namespace std;

#define inf HUGE_VAL

int check(string s,string ss)
{
    int i=0,j;
    string p="";
    string q="";
    if(s.size()!=ss.size())
        return 0;
    for(i=0;i<s.size();i++)
    {
        p.push_back(s[i]);
        if(i<s.size()-1)
        {
            q="";
            for(j=i+1;j<s.size();j++)
                q.push_back(s[j]);
            q+=p;
            if(ss==q)
                return 1;
        }
    }
    return 0;

}

class FoxAndWord
{
    public:
    int howManyPairs(vector <string> v)
    {
        int ret=0;
        for(int i=0;i<v.size();i++)
        {
            for(int j=i+1;j<v.size();j++)
                if(check(v[i],v[j]))
                    ret++;
        }
        return ret;
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"tokyo", "kyoto"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, howManyPairs(Arg0)); }
	void test_case_1() { string Arr0[] = {"aaaaa", "bbbbb"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, howManyPairs(Arg0)); }
	void test_case_2() { string Arr0[] = {"ababab","bababa","aaabbb"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, howManyPairs(Arg0)); }
	void test_case_3() { string Arr0[] = {"eel", "ele", "lee"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, howManyPairs(Arg0)); }
	void test_case_4() { string Arr0[] = {"aaa", "aab", "aba", "abb", "baa", "bab", "bba", "bbb"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(4, Arg1, howManyPairs(Arg0)); }
	void test_case_5() { string Arr0[] = {"top","coder"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(5, Arg1, howManyPairs(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    FoxAndWord ___test;
    ___test.run_test(-1);
    int gbase;
    cin>>gbase; // erase this line if you are not using dev-cpp! :)
    return 0;
}
// END CUT HERE

