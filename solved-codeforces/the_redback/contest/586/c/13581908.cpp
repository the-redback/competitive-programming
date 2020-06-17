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
#define NN        4010

#define read(a)   scanf("%lld",&a)

ll MaxVal;

ll tree[NN];
ll arr[NN];

ll update(ll idx,ll val)
{
    while(idx<=MaxVal)
    {
        tree[idx]+=val;
        idx+=idx & (-idx);
    }
    return 0;
}

ll query(ll idx)
{
    ll sum=0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx-=idx & (-idx);
    }
    return sum;
}

ll v[NN],d[NN],p[NN];
ll flag[NN];

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef redback
        freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    #endif

    ll t=1,tc;
    //read(tc);
    ll i,j,k,l,m,n;
    while(~read(n))
    {
        MaxVal=n;
        mem(tree,0);
        vector<ll>ans;
        mem(flag,-1);

        for(i=1;i<=n;i++)
        {
            scanf("%lld %lld %lld",&v[i],&d[i],&p[i]);
            update(i,p[i]);
            update(i+1,-p[i]);
        }

        for(i=1;i<=n;i++)
        {
            if(flag[i]==-1)
            {
                ans.pb(i);
                flag[i]=0;

                for(j=i+1,k=v[i];j<=n && k>0;j++)
                {
                    if(flag[j]!=-1)
                    {
                        continue;
                    }
                    update(j,-k);
                    update(j+1,k);
                    k--;
                }
                for(j=i+1;j<=n;j++)
                {
                    if(flag[j]==0)
                        continue;
                    k=query(j);
                    if(k<0)
                    {
                        flag[j]=0;
                        update(j+1,-d[j]);
                    }
                }
            }
        }

        printf("%lld\n",(ll)ans.size());
        for(i=0;i<ans.size();i++)
        {
            if(i!=0)
                printf(" ");
            printf("%lld",ans[i]);
        }
        puts("");


    }
    return 0;
}
