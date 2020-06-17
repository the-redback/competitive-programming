/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : Redback
 *    @link       : http://www.fb.com/maruf.2hin
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

#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pp pop_back
#define inf 10000000
#define NN 200000

class MagicalStringDiv2
{
    public:
    int minimalMoves(string S)
    {
        int ret=0;
        int l=S.size()-1;
        for(int i=0;i<l;i++,l--)
        {
            if(S[i]=='<')
                ret++;
            if(S[l]=='>')
                ret++;
        }
        return ret;
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = ">><<><"; int Arg1 = 2; verify_case(0, Arg1, minimalMoves(Arg0)); }
	void test_case_1() { string Arg0 = ">>>><<<<"; int Arg1 = 0; verify_case(1, Arg1, minimalMoves(Arg0)); }
	void test_case_2() { string Arg0 = "<<>>"; int Arg1 = 4; verify_case(2, Arg1, minimalMoves(Arg0)); }
	void test_case_3() { string Arg0 = "<><<<>>>>><<>>>>><>><<<>><><><><<><<<<<><<>>><><><"; int Arg1 = 20; verify_case(3, Arg1, minimalMoves(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    MagicalStringDiv2 ___test;
    ___test.run_test(-1);
    int gbase;
    cin>>gbase; // erase this line if you are not using dev-cpp! :)
    return 0;
}
// END CUT HERE

