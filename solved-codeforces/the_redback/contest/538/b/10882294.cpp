/**
 *    @author     : Maruf Tuhin
 *    @College    : CUET CSE 11
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
#define inf       1e9
#define eps       1e-9
#define mod       1000000007
#define NN        100010

#define read(a)   scanf("%lld",&a)


string s;
vector<string>ans;

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef redback
    freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
#endif

    ll t=1,tc;
    //read(tc);
    ll i,j,k,l,m,n;
    while(cin>>s)
    {
        ans.clear();

        ll flag=1;

        while(flag)
        {
            string ret="00000000";
            flag=0;

            for(i=s.size()-1,j=ret.size()-1; i>=0; i--,j--)
            {
                if(s[i]>'0')
                {
                    ret[j]++;
                    s[i]--;
                    flag=1;
                }
            }
            if(flag)
                ans.pb(ret);
        }

        ll res=(ll)ans.size();

        cout<<res<<"\n";

        for(i=0;i<ans.size();i++)
        {
            if(i!=0)
                cout<<" ";
            k=0;
            string ss=ans[i];
            for(j=0;j<ss.size();j++)
            {
                if(ss[j]=='0' && k==0)
                    continue;
                else
                {
                    k=1;
                    cout<<ss[j];
                }
            }
        }
        cout<<"\n";



    }
    return 0;
}
