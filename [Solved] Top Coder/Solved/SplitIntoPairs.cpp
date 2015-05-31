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

class SplitIntoPairs
{
    public:
    int makepairs(vector <int> A, int X)
    {
        cout<<A.size()<<endl;
        int ret=0,k=0;
        vector<int>v;
        vector<int>vv;
        int i;
        for(i=0;i<A.size();i++)
        {
            if(A[i]<0)
                vv.push_back(A[i]);
            else
                v.push_back(A[i]);
        }
        sort(v.begin(),v.end());
        sort(vv.begin(),vv.end());
        k=0;
        ret=0;
        if(v.size())
        {
            ret=v.size()/2;
            if(v.size()%2)
                k=1;
        }
        if(vv.size())
        {
            ret+=vv.size()/2;
        }
        if(k==1)
        {
            if((long long)vv[vv.size()-1]*v[0]>=X)
                ret++;
        }
        vv.clear();
        v.clear();
        return ret;
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,-1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; int Arg2 = 0; verify_case(0, Arg2, makepairs(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,-1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; int Arg2 = 1; verify_case(1, Arg2, makepairs(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {-5,-4,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; int Arg2 = 2; verify_case(2, Arg2, makepairs(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {5,-7,8,-2,-5,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -7; int Arg2 = 3; verify_case(3, Arg2, makepairs(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {3,4,5,6,6,-6,-4,-10,-1,-9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -2; int Arg2 = 4; verify_case(4, Arg2, makepairs(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {1000000,1000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -5; int Arg2 = 1; verify_case(5, Arg2, makepairs(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    int a[]={-7726273, -198566, 9681506, -6792315, -540917, -4861632, -4982458, -1383709, -6158006, 4166470, -6812236, -624690, 5158649, -9032251, -8845697, 4151603, 6274931, -8029271, -5157899, 6663477, -1398145, -4257609, 145272, -5237570, 861762, -4839969, -2853810, 577517, -941855, 707825, -9448768, -438974, -2454848, 9216156, 5254895, -923375, 440146, 3309157, -9364361, 8771003};
    int n=-2352133;
    vector<int>v(a,a+40);
    n=SplitIntoPairs().makepairs(v,n);
    cout<<n;
}
// END CUT HERE

