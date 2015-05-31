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

class EllysNewNickname
{
    public:
    int getLength(string nickname)
    {
        int ret,i,count=0;
        for(i=0;i<nickname.size()-1;i++)
        {
            if(nickname[i]=='a' || nickname[i]=='e' ||nickname[i]=='i'||nickname[i]=='o'||nickname[i]=='u'||nickname[i]=='y')
                if(nickname[i+1]=='a' || nickname[i+1]=='e' ||nickname[i+1]=='i'||nickname[i+1]=='o'||nickname[i+1]=='u'||nickname[i+1]=='y')
                    count++;
        }
        ret=nickname.size()-count;
        return ret;
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "tourist"; int Arg1 = 6; verify_case(0, Arg1, getLength(Arg0)); }
	void test_case_1() { string Arg0 = "eagaeoppooaaa"; int Arg1 = 6; verify_case(1, Arg1, getLength(Arg0)); }
	void test_case_2() { string Arg0 = "esprit"; int Arg1 = 6; verify_case(2, Arg1, getLength(Arg0)); }
	void test_case_3() { string Arg0 = "ayayayayayaya"; int Arg1 = 1; verify_case(3, Arg1, getLength(Arg0)); }
	void test_case_4() { string Arg0 = "wuuut"; int Arg1 = 3; verify_case(4, Arg1, getLength(Arg0)); }
	void test_case_5() { string Arg0 = "naaaaaaaanaaaanaananaaaaabaaaaaaaatmaaaaan"; int Arg1 = 16; verify_case(5, Arg1, getLength(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
EllysNewNickname ___test;
___test.run_test(-1);
int gbase;
cin>>gbase; // erase this line if you are not using dev-cpp! :)
return 0;
}
// END CUT HERE
