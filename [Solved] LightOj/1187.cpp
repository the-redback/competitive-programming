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
#define NN        100001

#define read(a)   scanf("%lld",&a)



ll tree[4*NN];
ll arr[NN];

void init(int node, int low, int high)
{
    if(low==high)
    {
        tree[node] = 1;
        return;
    }
    int left = node<<1;
    int right = left + 1;
    int mid = (low + high)>>1;

    init(left, low, mid);
    init(right, mid + 1, high);
    tree[node] = tree[left]+tree[right];
    return;
}

void update(int node, int low, int high, int in , int value)
{
    if(low==high && low==in )
    {
        tree[node]  = value;
        return;
    }
    int left = node<<1;
    int right = left + 1;
    int mid = (low + high)>>1;

    if(in <= mid)
        update(left, low, mid,in, value);
    else
        update(right, mid+1, high, in, value);

    tree[node]  = tree[left] + tree[right];
}

long long Find(int node, int low, int high, int value)
{
    if(low==high)
    {
        return low;
    }
    int left = node<<1;
    int right = left + 1;
    int mid = (low + high)>>1;

    if(tree[left]>=value)
        return Find(left, low, mid, value);
    else
        return Find(right, mid+1, high, value-tree[left]);
}



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef redback
        freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    #endif



    ll t=1,tc;
    cin>>tc;       ///Test case
    ll i,j,k,l,m,n;
    while(tc--)
    {
        cin>>n;
        init(1,1,n);

        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }

        ll res,in;
        for(i=n-1;i>=0;i--)
        {
            k=tree[1]-arr[i];
            in=Find(1,1,n,k);
            update(1,1,n,in,0);
        }
        res=in;

        printf("Case %lld: %lld\n",t++,res);

    }
    return 0;
}
