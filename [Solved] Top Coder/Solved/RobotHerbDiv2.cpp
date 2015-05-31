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

class RobotHerbDiv2
{
    public:
    int getdist(int T, vector <int> a)
    {
        int ret,i,j,k=0,l,x=0,y=0;
        while(T--)
        {
            for(i=0;i<a.size();i++)
            {
                if(k==0)
                    y+=a[i];
                if(k==1)
                    x+=a[i];
                if(k==2)
                    y-=a[i];
                if(k==3)
                    x-=a[i];
                k=(k+(a[i]%4))%4;
            }
        }
        ret=abs(0-x)+abs(0-y);
        return ret;
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, getdist(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 100; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, getdist(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arr1[] = {1,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; verify_case(2, Arg2, getdist(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 100; int Arr1[] = {400000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 40000000; verify_case(3, Arg2, getdist(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
RobotHerbDiv2 ___test;
___test.run_test(-1);
int gbase;
cin>>gbase; // erase this line if you are not using dev-cpp! :)
return 0;
}
// END CUT HERE
