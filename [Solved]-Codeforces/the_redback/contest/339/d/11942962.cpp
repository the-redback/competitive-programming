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
#define NN        140010

#define read(a)   scanf("%lld",&a)

struct data
{
    int value;
    int flag;
}tree[NN*4];

ll a[NN];

void init(int node, int low, int high)
{
    if(low==high)
    {
        tree[node].value =a[low];
        tree[node].flag =0;
        return;
    }
    int left = node*2;
    int right = left + 1;
    int mid = (low + high)/2;

    init(left, low, mid);
    init(right, mid + 1, high);

    tree[node].flag=tree[left].flag^1;

    if(tree[node].flag==1)
        tree[node].value=tree[left].value | tree[right].value;
    else
        tree[node].value=tree[left].value ^ tree[right].value;

    return;
}

void update(int node, int low, int high, int rlow, int val)
{
    if(low==rlow && high==rlow)
    {
        tree[node].value = val;
        return;
    }
    int left = node*2;
    int right = left+1;
    int mid = (low+high)/2;

    if(rlow > mid)
        update(right, mid+1, high, rlow, val);
    else
        update(left, low, mid, rlow, val);

    if(tree[node].flag==1)
        tree[node].value=tree[left].value | tree[right].value;
    else
        tree[node].value=tree[left].value ^ tree[right].value;
}


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
        read(m);
        n=pow(2.0,(double)n);

        for(i=1;i<=n;i++)
            read(a[i]);

        init(1,1,n);

        while(m--)
        {
            read(k);
            read(l);

            update(1,1,n,k,l);

            printf("%d\n",tree[1].value);
        }

    }
    return 0;
}
