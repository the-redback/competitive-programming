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

#define ppb pop_back
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 1000000000
#define eps 1e-9
#define NN 400010

int prime(int n)
{
    for(int i=2; i*i<=n; i++)
        if(n%i==0)
            return 1;
    return 0;
}


struct SilverbachConjecture
{
    vector <int> solve(int n)
    {
        vector <int> ret;
        vector <int>v;
        int i;
        for(i=2; i<=n; i++)
            if(prime(i))
                v.push_back(i);
        for(i=0; i<v.size(); i++)
        {
            int r=v[i];
            int k=n-r;
            if(prime(k))
            {
                ret.push_back(k);
                ret.push_back(r);
                break;
            }

        }

        return ret;
    }

// BEGIN CUT HERE
public:
    void run_test(int Case)
    {
        if ((Case == -1) || (Case == 0)) test_case_0();
        if ((Case == -1) || (Case == 1)) test_case_1();
        if ((Case == -1) || (Case == 2)) test_case_2();
        if ((Case == -1) || (Case == 3)) test_case_3();
    }
private:
    template <typename T> string print_array(const vector<T> &V)
    {
        ostringstream os;
        os << "{ ";
        for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\",";
        os << " }";
        return os.str();
    }
    void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received)
    {
        cerr << "Test Case #" << Case << "...";
        if (Expected == Received) cerr << "PASSED" << endl;
        else
        {
            cerr << "FAILED" << endl;
            cerr << "\tExpected: " << print_array(Expected) << endl;
            cerr << "\tReceived: " << print_array(Received) << endl;
        }
    }
    void test_case_0()
    {
        int Arg0 = 20;
        int Arr1[] = {8, 12 };
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(0, Arg1, solve(Arg0));
    }
    void test_case_1()
    {
        int Arg0 = 30;
        int Arr1[] = {15, 15 };
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(1, Arg1, solve(Arg0));
    }
    void test_case_2()
    {
        int Arg0 = 999;
        int Arr1[] = {699, 300 };
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(2, Arg1, solve(Arg0));
    }
    void test_case_3()
    {
        int Arg0 = 45;
        int Arr1[] = {15, 30 };
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(3, Arg1, solve(Arg0));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    SilverbachConjecture ___test;
    ___test.run_test(-1);
    int gbase;
    cin>>gbase; // erase this line if you are not using dev-cpp! :)
    return 0;
}
// END CUT HERE
