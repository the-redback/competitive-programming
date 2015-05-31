/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : the_redback
 *    @link       : http://www.fb.com/maruf.2hin
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long          LL;
typedef unsigned long long LLU;

#define ft        first
#define sd        second
#define mp        make_pair
#define pb(x)     push_back(x)
#define all(x)    x.begin(),x.end()
#define allr(x)   x.rbegin(),x.rend()
#define mem(a,b)  memset(a,b,sizeof(a))
#define meminf(a) memset(a,126,sizeof(a))
#define inf       1e11
#define eps       1e-9
#define mod       1000000007
#define NN        1010

//cout << setfill('0') << setw(3) << a << endl;
//cout << fixed << setprecision(20) << a << endl;

struct DoubleLetter
{
    string ableToSolve(string s)
    {
        string ret;
        string ss;
        int fl=1;
        while(1 && s.size()>=2 && fl)
        {
            fl=0;
            for(int i=0;i<s.size()-1;)
            {
                if(s[i]==s[i+1])
                {
                    fl=1;
                    ss="";
                    for(int j=0,k=0;j<s.size();j++,k++)
                    {
                        if(j==i||j==i+1)
                            continue;
                        else
                            ss+=s[j];
                    }
                    s=ss;
                    break;
                }
                else
                    i++;
            }
        }
        if(s.size()==0)
            ret="Possible";
        else
            ret="Impossible";
        return ret;
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aabccb"; string Arg1 = "Possible"; verify_case(0, Arg1, ableToSolve(Arg0)); }
	void test_case_1() { string Arg0 = "aabccbb"; string Arg1 = "Impossible"; verify_case(1, Arg1, ableToSolve(Arg0)); }
	void test_case_2() { string Arg0 = "abcddcba"; string Arg1 = "Possible"; verify_case(2, Arg1, ableToSolve(Arg0)); }
	void test_case_3() { string Arg0 = "abab"; string Arg1 = "Impossible"; verify_case(3, Arg1, ableToSolve(Arg0)); }
	void test_case_4() { string Arg0 = "aaaaaaaaaa"; string Arg1 = "Possible"; verify_case(4, Arg1, ableToSolve(Arg0)); }
	void test_case_5() { string Arg0 = "aababbabbaba"; string Arg1 = "Impossible"; verify_case(5, Arg1, ableToSolve(Arg0)); }
	void test_case_6() { string Arg0 = "zzxzxxzxxzzx"; string Arg1 = "Possible"; verify_case(6, Arg1, ableToSolve(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    DoubleLetter ___test;
    ___test.run_test(-1);
    int gbase;
    cin>>gbase; // erase this line if you are not using dev-cpp! :)
    return 0;
}
// END CUT HERE

