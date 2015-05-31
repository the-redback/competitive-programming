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
struct data
{
    long long color;
    string name;
};
bool comp(data a,data b)
{
    return a.color<b.color;
}

class AlternateColors
{
    public:
    string getColor(long long r, long long g, long long b, long long k)
    {
        string ret;
        data v[4];
        v[0].color=r;
        v[0].name="RED";
        v[1].color=g;
        v[1].name="GREEN";
        v[2].color=b;
        v[2].name="BLUE";
        sort(v,v+3,comp);
        if(k<=v[0].color*3)
        {
            v[1].name="RED";
            v[2].name="GREEN";
            v[0].name="BLUE";
            k=k%3;
            ret=v[k].name;
        }
        else
        {
            k-=v[0].color*3;
            v[1].color-=v[0].color;
            v[2].color-=v[0].color;
            v[0].color-=v[0].color;
            if(k<=v[1].color*2)
            {
                if(v[0].name=="RED")
                {
                    v[1].name="GREEN";
                    v[0].name="BLUE";
                }
                else if(v[0].name=="GREEN")
                {
                    v[1].name="RED";
                    v[0].name="BLUE";
                }
                else
                {
                    v[1].name="RED";
                    v[0].name="GREEN";
                }
                k=k%2;
                ret=v[k].name;
            }
            else
                ret=v[2].name;
        }

        return ret;
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 1LL; long long Arg1 = 1LL; long long Arg2 = 1LL; long long Arg3 = 3LL; string Arg4 = "BLUE"; verify_case(0, Arg4, getColor(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { long long Arg0 = 3LL; long long Arg1 = 4LL; long long Arg2 = 5LL; long long Arg3 = 4LL; string Arg4 = "RED"; verify_case(1, Arg4, getColor(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { long long Arg0 = 7LL; long long Arg1 = 7LL; long long Arg2 = 1LL; long long Arg3 = 7LL; string Arg4 = "GREEN"; verify_case(2, Arg4, getColor(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { long long Arg0 = 1000000000000LL; long long Arg1 = 1LL; long long Arg2 = 1LL; long long Arg3 = 1000000000002LL; string Arg4 = "RED"; verify_case(3, Arg4, getColor(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { long long Arg0 = 653LL; long long Arg1 = 32LL; long long Arg2 = 1230LL; long long Arg3 = 556LL; string Arg4 = "BLUE"; verify_case(4, Arg4, getColor(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{

AlternateColors ___test;
___test.run_test(-1);
int gbase;
cin>>gbase; // erase this line if you are not using dev-cpp! :)
return 0;
}
// END CUT HERE
