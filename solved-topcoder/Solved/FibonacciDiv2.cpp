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

#define mp make_pair
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 1e9
#define eps 1e-9
#define NN 1050

vector<int>v;

void work(void)
{
    int i;
    v.pb(0);
    v.pb(1);
    i=2;
    while(true)
    {
        int k=v[i-1]+v[i-2];
        i++;
        v.pb(k);
        if(k>1000000)
            break;
    }
}


struct FibonacciDiv2
{
    int find(int N)
    {
        int ret;
        work();
        vector<int>::iterator low;
        low=lower_bound(all(v),N);
        int in=low-v.begin();
        ret=min(N-v[in-1], v[in]-N);
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
        if ((Case == -1) || (Case == 4)) test_case_4();
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
    void verify_case(int Case, const int &Expected, const int &Received)
    {
        cerr << "Test Case #" << Case << "...";
        if (Expected == Received) cerr << "PASSED" << endl;
        else
        {
            cerr << "FAILED" << endl;
            cerr << "\tExpected: \"" << Expected << '\"' << endl;
            cerr << "\tReceived: \"" << Received << '\"' << endl;
        }
    }
    void test_case_0()
    {
        int Arg0 = 1;
        int Arg1 = 0;
        verify_case(0, Arg1, find(Arg0));
    }
    void test_case_1()
    {
        int Arg0 = 13;
        int Arg1 = 0;
        verify_case(1, Arg1, find(Arg0));
    }
    void test_case_2()
    {
        int Arg0 = 15;
        int Arg1 = 2;
        verify_case(2, Arg1, find(Arg0));
    }
    void test_case_3()
    {
        int Arg0 = 19;
        int Arg1 = 2;
        verify_case(3, Arg1, find(Arg0));
    }
    void test_case_4()
    {
        int Arg0 = 1000000;
        int Arg1 = 167960;
        verify_case(4, Arg1, find(Arg0));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    FibonacciDiv2 ___test;
    ___test.run_test(-1);
    int gbase;
    cin>>gbase; // erase this line if you are not using dev-cpp! :)
    return 0;
}
// END CUT HERE
