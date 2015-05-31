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
#define inf       1e11
#define eps       1e-9
#define mod       1000000007
#define NN        30010

//cout << setfill('0') << setw(3) << a << endl;
//cout << fixed << setprecision(20) << a << endl;

int MaxVal;

int flag[1000010];
int tree[NN];
int a[NN];
int ans[200010];
struct D
{
    int ft,sd,id;
}q[200010];


int update(int idx,int val)
{
    while(idx<=MaxVal)
    {
        tree[idx]=(tree[idx]+val)%mod;
        idx+=idx & (-idx);
    }
    return 0;
}

int query(int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum=(sum+tree[idx])%mod;
        idx-=idx & (-idx);
    }
    return sum;
}

bool comp(D aa,D bb)
{
    return aa.sd<bb.sd;
}

main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    //cin>>tc;

    int i,j,k,l,m,n;
    scanf("%d",&n);
    {

        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        scanf("%d",&m);
        int MAX=0;
        for(i=1;i<=m;i++)
        {
            scanf("%d %d",&q[i].ft,&q[i].sd);
            q[i].id=i;
        }

        sort(q+1,q+m+1,comp);
        MaxVal=n;
        memset(tree,0,sizeof(int)*(n+2));
        mem(flag,-1);
        int total=0,pos=1;

        for(i=1;i<=n;i++)
        {
            if(flag[a[i]]==-1)
                total++;
            else
                update(flag[a[i]],-1);
            update(i,1);
            flag[a[i]]=i;

            while(pos<=m && q[pos].sd==i )
            {
                int temp=total-query(q[pos].ft-1);
                ans[q[pos].id]=temp;
                pos++;
            }
        }
        for(i=1;i<=m;i++)
            printf("%d\n",ans[i]);

    }
    return 0;
}
