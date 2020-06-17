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

char a[NN];
vector<int>v;

main()
{
    #ifdef redback
        //freopen("in.txt","r",stdin);
    #endif // redback

    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    //cin>>tc;
    int i,j,k,l,m,n;
    while(~scanf("%s",&a))
    {
        v.clear();
        int prev=0;
        l=strlen(a);
        for(i=0;i<l && prev>=0;i++)
        {
            if(a[i]=='(')
                prev++;
            else if(a[i]==')')
                prev--;
            else if(a[i]=='#')
            {
                v.pb(1);
                prev--;
            }
        }
        if(prev<0)
        {
            printf("-1\n");
            continue;
        }
        if(prev>0)
            v[v.size()-1]+=prev;

        prev=0;
        j=0;
        for(i=0;i<l && prev>=0;i++)
        {
            if(a[i]=='(')
                prev++;
            else if(a[i]==')')
                prev--;
            else if(a[i]=='#')
            {
                prev-=v[j];
                j++;
            }
        }
        if(prev<0)
        {
            printf("-1\n");
            continue;
        }
        for(i=0;i<v.size();i++)
            printf("%d\n",v[i]);


    }
    return 0;
}

