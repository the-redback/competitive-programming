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
#define mp        make_pair
#define pb(x)     push_back(x)
#define all(x)    x.begin(),x.end()
#define allr(x)   x.rbegin(),x.rend()
#define mem(a,b)  memset(a,b,sizeof(a))
#define meminf(a) memset(a,126,sizeof(a))
#define inf       1e6
#define eps       1e-9
#define mod       1000000007
#define NN        100

//cout << setfill('0') << setw(3) << a << endl;
//cout << fixed << setprecision(20) << a << endl;

int flag[NN];


struct BagsQuiz
{
    int checkIfProper(int n, vector <string> act)
    {
        mem(flag,-1);
        int ret;
        int i,j,k,l,m;
        for(i=0; i<act.size(); i++)
        {
            char aa[20],bb[20];
            char cc[20];

            sscanf(act[i].c_str(),"%s %*s",&aa);
            if(strcmp(aa,"PUT")==0)
            {
                sscanf(act[i].c_str(),"%*s %d %*s %d",&k,&l);
                if(flag[k]!=-1 ||flag[l]!=-1 )
                    return -1;
                flag[k]=l;
            }
            else if(strcmp(aa,"SET")==0)
            {
                sscanf(act[i].c_str(),"%*s %d %*s",&k);
                if(flag[k]!=-1)
                    return -1;
                for(j=1; j<=n; j++)
                    if(flag[j]==k)
                        flag[j]=-1;
            }
            else
            {
                sscanf(act[i].c_str(),"%*s %d %*s %d",&k,&l);
                if(flag[k]!=-1 ||flag[l]!=-1 )
                    return -1;
                for(j=1; j<=n; j++)
                    if(flag[j]==k)
                        flag[j]=inf;
                for(j=1; j<=n; j++)
                    if(flag[j]==l)
                        flag[j]=k;
                for(j=1; j<=n; j++)
                    if(flag[j]==inf)
                        flag[j]=l;
            }
        }
        ret=0;
        for(j=1; j<=n; j++)
        {
            if(flag[j]==-1)
                ret++;
            else if(flag[j]<j)
                return -1;

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
        int Arg0 = 9;
        string Arr1[] = {"PUT 1 INSIDE 9", "SET 6 LOOSE", "PUT 9 INSIDE 7", "SWAP 8 WITH 7", "PUT 6 INSIDE 8", "PUT 3 INSIDE 7", "SET 2 LOOSE", "PUT 4 INSIDE 7", "PUT 8 INSIDE 2", "PUT 7 INSIDE 2", "PUT 5 INSIDE 2", "SET 2 LOOSE", "PUT 2 INSIDE 5", "PUT 5 INSIDE 8", "PUT 7 INSIDE 8", "SET 8 LOOSE"};
        vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 5;
        verify_case(0, Arg2, checkIfProper(Arg0, Arg1));
    }
    void test_case_1()
    {
        int Arg0 = 2;
        string Arr1[] = {"PUT 1 INSIDE 2", "SET 2 LOOSE"};
        vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 2;
        verify_case(1, Arg2, checkIfProper(Arg0, Arg1));
    }
    void test_case_2()
    {
        int Arg0 = 2;
        string Arr1[] = {"PUT 2 INSIDE 1"};
        vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = -1;
        verify_case(2, Arg2, checkIfProper(Arg0, Arg1));
    }
    void test_case_3()
    {
        int Arg0 = 4;
        string Arr1[] = {"PUT 3 INSIDE 2", "SWAP 4 WITH 2", "PUT 2 INSIDE 4", "SET 1 LOOSE"};
        vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 2;
        verify_case(3, Arg2, checkIfProper(Arg0, Arg1));
    }
    void test_case_4()
    {
        int Arg0 = 3;
        string Arr1[] = {"PUT 1 INSIDE 2", "PUT 3 INSIDE 1"};
        vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = -1;
        verify_case(4, Arg2, checkIfProper(Arg0, Arg1));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    BagsQuiz ___test;
    ___test.run_test(-1);
    int gbase;
    cin>>gbase; // erase this line if you are not using dev-cpp! :)
    return 0;
}
// END CUT HERE

