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
#define NN        200010

#define read(a)   scanf("%lld",&a)


ll tree[4*NN];
bool b[NN];
ll cnt=0;

void update(ll node, ll low, ll high, ll rlow, ll rhigh, ll value)
{
    if(low>=rlow && high<=rhigh)
    {
        tree[node]=value;
        return;
    }
    ll left = node<<1;
    ll right = left+1;
    ll mid = (low+high)>>1;

    if(tree[node]!=-1)
    {
        tree[left]=tree[node];
        tree[right]=tree[node];
        tree[node]=-1;
    }

    if(rhigh <= mid)
        update(left, low, mid, rlow, rhigh, value);
    else if(rlow > mid)
        update(right, mid+1, high, rlow, rhigh, value);
    else
    {
        update(left, low, mid, rlow, mid, value);
        update(right, mid+1, high, mid+1, rhigh, value);
    }
    return;
}

void query(ll node, ll low, ll high)
{
    if(tree[node]!=-1)
    {
        if(!b[tree[node]])
        {
            b[tree[node]]=1;
            cnt++;
        }
        return;
    }

    if(low==high)
        return;


    ll left = node<<1;
    ll right = left + 1;
    ll mid = (low + high)>>1;

    query(left, low, mid);
    query(right, mid + 1, high);
    return;
}



main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll tc, t=1;
    cin>>tc;
    ll i, j, k, l;
    while(tc--)
    {
        ll n, q;
        cin>>q;
        n=q*2;

        memset(tree,-1,sizeof(ll)*4*(n+1));
        memset(b,0,sizeof(bool)*(q+1));

        for(i=1;i<=q;i++)
        {

            cin>>j>>k;
            update(1, 1, n, j+1, k+1, i);
        }

        cnt=0;
        query(1,1,n);

        printf("Case %lld: %lld\n", t++,cnt);

    }
    return 0;
}
