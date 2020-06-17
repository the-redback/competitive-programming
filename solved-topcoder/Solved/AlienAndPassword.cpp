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
map<string,int>mp;
class AlienAndPassword
{
    public:
    int getNumber(string S)
    {
        int ret=0,i;
        string s=S;
        for(i=0;i<S.size();i++)
        {
            s=S;
            s.erase(s.begin()+i);
            if(mp.find(s)==mp.end())
            {
                mp[s]=1;
                ret++;
            }
        }
        mp.clear();
        return ret;
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "A"; int Arg1 = 1; verify_case(0, Arg1, getNumber(Arg0)); }
	void test_case_1() { string Arg0 = "ABA"; int Arg1 = 3; verify_case(1, Arg1, getNumber(Arg0)); }
	void test_case_2() { string Arg0 = "AABACCCCABAA"; int Arg1 = 7; verify_case(2, Arg1, getNumber(Arg0)); }
	void test_case_3() { string Arg0 = "AGAAGAHHHHFTQLLAPUURQQRRRUFJJSBSZVJZZZ"; int Arg1 = 26; verify_case(3, Arg1, getNumber(Arg0)); }
	void test_case_4() { string Arg0 = "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ"; int Arg1 = 1; verify_case(4, Arg1, getNumber(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    AlienAndPassword ___test;
    ___test.run_test(-1);
    int gbase;
    cin>>gbase; // erase this line if you are not using dev-cpp! :)
    return 0;
}
// END CUT HERE

