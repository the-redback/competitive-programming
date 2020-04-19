/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : the_redback
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

//#define ll long long
#define mp make_pair
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 1e9
#define eps 1e-9
#define NN 1050
vector<double>vv,ww;

double check(double mid)
{
    double res=0,k,ret=0;
    for(int i=0;i<vv.size();i++)
    {
        k=vv[i]*mid;
        res+=abs(k-ww[i]);
    }
    return res;
}

struct CandyMaking{

double findSuitableDensity(vector <int>v, vector <int>w)
{
    double ret=0,res=0,high,low,mid1,mid2,kk,ll,mid;

    vv.clear(),ww.clear();
    double mx=0;
    int i,j;
    for( i=0;i<v.size();i++)
        vv.pb(v[i]),ww.pb(w[i]),mx=max(mx,ww[i]/vv[i]);

    low=0,high=mx;

    for(i=0;i<=200;i++)
    {
        mid=(high-low)/3.0;
        mid1=low+mid;
        mid2=high-mid;
        kk=check(mid1);
        ll=check(mid2);
        if(ll-kk>0)
            high=mid2,res=kk;
        else
            low=mid1,res=ll;
    }
    return ret=res;
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(0, Arg2, findSuitableDensity(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {10,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000,2000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1000.0; verify_case(1, Arg2, findSuitableDensity(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {10,20,40}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4000,2000,1000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 5250.0; verify_case(2, Arg2, findSuitableDensity(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1234,1541,3321,1234,123,123,3414,123,12,2442,1421,1223,3232,1123,2121}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3213,1231,232143,44312,132132,142424,123123,41341,41244,21312,232131,2312,2322,11,2223}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 983673.2727272725; verify_case(3, Arg2, findSuitableDensity(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {30621,30620,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1,1000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 999999.9999673415; verify_case(4, Arg2, findSuitableDensity(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
CandyMaking ___test;
___test.run_test(-1);
int gbase;
cin>>gbase; // erase this line if you are not using dev-cpp! :)
return 0;
}
// END CUT HERE

