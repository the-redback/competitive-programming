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

typedef long long          ll;
typedef unsigned long long llu;

#define ft        first
#define sd        second
//#define mp        make_pair
#define pb(x)     push_back(x)
#define all(x)    x.begin(),x.end()
#define allr(x)   x.rbegin(),x.rend()
#define mem(a,b)  memset(a,b,sizeof(a))
#define meminf(a) memset(a,126,sizeof(a))
#define inf       1e11
#define eps       1e-9
#define mod       1000000007
#define NN        5000100

//cout << setfill('0') << setw(3) << a << endl;
//cout << fixed << setprecision(20) << a << endl;
ll flag=0;
bool mp[NN],mpp[NN];

ll power(ll n,ll x)
{
    ll ret=1;
    while(x>0)
    {
        ret*=n;
        x--;
    }
    return ret;
}



struct SumsOfPerfectPowers
{
    int howMany(int low, int up)
    {
        ll ret=0;
        vector<ll>v;
        v.clear();
        ll i,j,k,l;
        mem(mp,0);
        mem(mpp,0);
        mp[0]=1;
        mp[1]=1;
        v.pb(0);
        v.pb(1);
        ll N=sqrt(up);
        for(i=2; i<=N+1; i++)
        {
            j=2;
            while(1)
            {

                ll temp=power(i,j);
                if(temp>up)
                    break;
                if(mp[temp]==0)
                    v.pb(temp);
                mp[temp]=1;
                j++;
            }
            // cout<<i<<"\n";
        }
        sort(all(v));
        //cout<<"done\n";
        for(i=0; i<v.size(); i++)
        {
            for(j=0; j<v.size(); j++)
            {
                k=v[i]+v[j];
                if(k>=low && k<=up  )
                {
                    if(mpp[k]==0)
                    {
                        mpp[k]=1;
                    ret++;
                    }
                }
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
        int Arg0 = 0;
        int Arg1 = 1;
        int Arg2 = 2;
        verify_case(0, Arg2, howMany(Arg0, Arg1));
    }
    void test_case_1()
    {
        int Arg0 = 5;
        int Arg1 = 6;
        int Arg2 = 1;
        verify_case(1, Arg2, howMany(Arg0, Arg1));
    }
    void test_case_2()
    {
        int Arg0 = 25;
        int Arg1 = 30;
        int Arg2 = 5;
        verify_case(2, Arg2, howMany(Arg0, Arg1));
    }
    void test_case_3()
    {
        int Arg0 = 103;
        int Arg1 = 103;
        int Arg2 = 0;
        verify_case(3, Arg2, howMany(Arg0, Arg1));
    }
    void test_case_4()
    {
        int Arg0 = 1;
        int Arg1 = 100000;
        int Arg2 = 33604;
        verify_case(4, Arg2, howMany(Arg0, Arg1));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    SumsOfPerfectPowers z;
    //int x=z.howMany(1,4999999);
    //cout<<x;
    ___test.run_test(-1);
    int gbase;
    cin>>gbase; // erase this line if you are not using dev-cpp! :)
    return 0;
}
// END CUT HERE

