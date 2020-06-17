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

ll a[NN];
ll tree[4*NN];
int fl=0;
ll I[NN],J[NN],Q[NN];

void update(int node, int low, int high, int rlow, int rhigh, ll value)
{
    if(low>=rlow && high<=rhigh)
    {
        tree[node]= value|tree[node];
        return;
    }
    int left = node*2;
    int right = left+1;
    int mid = (low+high)/2;

    if(rhigh <= mid)
        update(left, low, mid, rlow, rhigh, value);
    else if(rlow > mid)
        update(right, mid+1, high, rlow, rhigh, value);
    else
    {
        update(left, low, mid, rlow, mid, value);
        update(right, mid+1, high, mid+1, rhigh, value);
    }
}

long long query(int node, int low, int high, int rlow, int rhigh, long long carry)
{
    if(low>=rlow && high<=rhigh)
    {
        return tree[node]| carry;
    }
    int left = node*2;
    int right = left + 1;
    int mid = (low + high)/2;

    long long p1=0, p2=0;
    if(rhigh<=mid)
        return query(left, low, mid, rlow, rhigh, carry | tree[node]);
    else if(rlow>mid)
        return query(right, mid+1, high, rlow, rhigh,  carry | tree[node]);
}

void init(int node, int low, int high)
{
    if(low==high)
    {
        tree[node] = a[low];
        return;
    }
    int left = node*2;
    int right = left + 1;
    int mid = (low + high)/2;

    init(left, low, mid);
    init(right, mid + 1, high);
    tree[node] = tree[left] & tree[right];
    return;
}

long long query2(int node, int low, int high, int rlow, int rhigh)
{
    if(low>=rlow && high<=rhigh)
    {
        return tree[node];
    }
    int left = node*2;
    int right = left + 1;
    int mid = (low + high)/2;

    if(rhigh<=mid)
        return query2(left, low, mid, rlow, rhigh);
    else if(rlow>mid)
        return query2(right, mid+1, high, rlow, rhigh);
    else
    {
        ll p1=query2(left, low, mid, rlow, mid);
        ll p2=query2(right, mid+1, high, mid+1, rhigh);
        return p1&p2;
    }
}


main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    //cin>>tc;
    ll i,j,k,l,r,m,n;
    cin>>n>>k;
    fl=0;
    for(r=1;r<=k;r++)
    {
        cin>>i>>j>>l;
        update(1,1,n,i,j,l);
        I[r]=i;
        J[r]=j;
        Q[r]=l;
    }
    ll limit=1<<30;
    for(i=1;i<=n;i++)
    {
        a[i]=query(1,1,n,i,i,0);
        if(a[i]>= limit )
            fl=1;
    }
    mem(tree,0);
    init(1,1,n);
    for(i=1;i<=k;i++)
    {
        if(query2(1,1,n,I[i],J[i])!=Q[i])
        {
            fl=1;
            break;
        }
    }

    if(fl==1)
        cout<<"NO\n";
    else
    {
        cout<<"YES\n"<<a[1];
        for(i=2;i<=n;i++)
            cout<< " "<<a[i];
        cout<<"\n";
    }


    return 0;
}
