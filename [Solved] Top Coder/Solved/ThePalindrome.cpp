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

class ThePalindrome
{
    public:
    int find(string s)
    {
        int ret;
        int i,j,k=0;
        string str,st,ss;
        ss=s;
        reverse(ss.begin(),ss.end());
        for(i=0;i<s.size();i++)
        {
            if(s[i]==ss[0])
            {
                str.erase();
                st.erase();
                j=s.size()-i;
                str=s.substr(i,j);
                st=ss.substr(0,j);
                if(str==st)
                {
                    k=1;
                    ret=s.size()+i;
                    break;
                }
            }
        }
        if(k!=1)
            ret=(s.size()*2)-1;
        return ret;
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "abab"; int Arg1 = 5; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { string Arg0 = "abacaba"; int Arg1 = 7; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { string Arg0 = "qwerty"; int Arg1 = 11; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { string Arg0 = "abdfhdyrbdbsdfghjkllkjhgfds"; int Arg1 = 38; verify_case(3, Arg1, find(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
ThePalindrome ___test;
___test.run_test(-1);
int gbase;
cin>>gbase; // erase this line if you are not using dev-cpp! :)
return 0;
}
// END CUT HERE
