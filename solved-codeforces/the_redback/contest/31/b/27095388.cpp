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
#define NN        30100

#define read(a)   scanf("%lld",&a)

char a[1000];
char c[1000];

vector<char>v[1000];

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    //cin>>tc;
    ll i,j,k,l,m,n;
    while(~scanf("%s",&a))
    {
        ll r=0;
        j=0;
        l=strlen(a);
        ll pos=0,pp=0;
        if(a[0]=='@' || a[l-1]=='@')
            pos=1;
        for(i=1;i<l;i++)
        {
            if(a[i]=='@')
                pp=1;
            if(a[i]=='@' && j==i)
            {
                pos=1;
                break;
            }
            if(a[i-1]=='@')
            {
                if(a[i]=='@')
                {
                    pos=1;
                    break;
                }
                else
                {
                    ll rr=0;
                    for(k=j;k<=i;k++)
                        v[r].pb(a[k]);
                    r++;
                    j=i+1;
                }
            }

        }
        if(pos==1 || pp==0)
        {
            printf("No solution\n");
        }
        else
        {
            for(i=0;i<r;i++)
            {
                for(k=0;k<v[i].size();k++)
                    printf("%c",v[i][k]);
                if(i+1<r)
                    printf(",");
            }
            for(i=j;i<l;i++)
            {
                printf("%c",a[i]);
            }
            printf("\n");
            for(i=0;i<=r;i++)
                v[i].clear();
        }

    }
    return 0;
}
