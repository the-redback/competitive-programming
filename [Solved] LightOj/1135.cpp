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
#define NN        100000

#define read(a)   scanf("%lld",&a)

struct D
{
    ll n0,n1,n2,xtra;
    D(ll N0,ll N1,ll N2, ll Xtra)
    {
        n0=N0,n1=N1,n2=N2;
        xtra=Xtra;
    }
    D()
    {

    }
}arr[4*NN];

D modify(D a)
{
    a.xtra%=3;
    D b=a;
    if(a.xtra==1)
    {
        b.n0=a.n2;
        b.n2=a.n1;
        b.n1=a.n0;
    }
    else if(a.xtra==2)
    {
        b.n1=a.n2;
        b.n2=a.n0;
        b.n0=a.n1;
    }
    return b;
}

D merge(D a, D b,ll xtra)
{
    D c=D(0,0,0,0);

    c.n0=a.n0+b.n0;
    c.n1=a.n1+b.n1;
    c.n2=a.n2+b.n2;

    c=modify(D(c.n0,c.n1,c.n2,xtra));
    return c;
}

void init(ll node, ll low, ll high)
{
    if(low==high)
    {
        arr[node] = D(1,0,0,0);
        return;
    }
    ll left = node*2;
    ll right = left + 1;
    ll mid = (low + high)/2;

    init(left, low, mid);
    init(right, mid + 1, high);
    arr[node] = merge(arr[left], arr[right],0);
    return;
}

void update(ll node, ll low, ll high, ll rlow, ll rhigh, ll value)
{
    if(low>=rlow && high<=rhigh)
    {
        ll tmp=arr[node].xtra+value;
        arr[node]=modify(D(arr[node].n0,arr[node].n1,arr[node].n2,value%3));
        arr[node].xtra=tmp%3;
        return;
    }
    ll left = node*2;
    ll right = left+1;
    ll mid = (low+high)/2;

    if(rhigh <= mid)
        update(left, low, mid, rlow, rhigh, value);
    else if(rlow > mid)
        update(right, mid+1, high, rlow, rhigh, value);
    else
    {
        update(left, low, mid, rlow, mid, value);
        update(right, mid+1, high, mid+1, rhigh, value);
    }
    arr[node] = merge(arr[left], arr[right],arr[node].xtra);
}

D query(ll node, ll low, ll high, ll rlow, ll rhigh, ll carry)
{
    if(low>=rlow && high<=rhigh)
    {
        return modify(D(arr[node].n0,arr[node].n1,arr[node].n2,carry%3));
    }
    ll left = node*2;
    ll right = left + 1;
    ll mid = (low + high)/2;

    D p1=D(0,0,0,0), p2=D(0,0,0,0);
    if(rhigh<=mid)
        p1=query(left, low, mid, rlow, rhigh, carry+arr[node].xtra);
    else if(rlow>mid)
        p2=query(right, mid+1, high, rlow, rhigh, carry+arr[node].xtra);
    else
    {
        p1=query(left, low, mid, rlow, mid, carry+arr[node].xtra);
        p2=query(right, mid+1, high, mid+1, rhigh, carry+arr[node].xtra);
    }
    return merge(p1,p2,0);
}


main()
{
    ll t=1,tc;
    read(tc);
    ll i,j,k,l,m,n;
    while(tc--)
    {
        read(n);
        read(m);
        init(1,1,n);
        printf("Case %lld:\n",t++);
        while(m--)
        {
            read(k);
            if(k==0)
            {
                read(i);
                read(j);
                update(1,1,n,i+1,j+1,1);
            }
            if(k==1)
            {
                read(i);
                read(j);
                D temp=query(1,1,n,i+1,j+1,0);
                printf("%lld\n",temp.n0);
            }
        }
    }
    return 0;
}

