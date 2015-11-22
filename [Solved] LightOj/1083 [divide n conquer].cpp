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

/*
Segment tree stores the index with the lowest value in that range.

*/

ll tree[NN*4];
ll arr[NN];
ll N;

void init(ll node,ll low,ll high)
{
    if(low==high)
    {
        tree[node]=low;
        return ;
    }

    ll mid=(low+high)>>1;
    ll left=node<<1;
    ll right=left+1;
    init(left,low,mid);
    init(right,mid+1,high);

    ll  left_ind=tree[left];
    ll right_ind=tree[right];

    if(arr[left_ind]<arr[right_ind])
        tree[node]=left_ind;
    else
        tree[node]=right_ind;
    return;
}

ll query(ll node,ll low,ll high,ll rlow,ll rhigh)
{

    if(low>=rlow && high<=rhigh)
    {
        return tree[node];
    }
    ll mid=(low+high)>>1;
    ll left=node<<1;
    ll right=left+1;

    if(mid<rlow)
        return query(right,mid+1,high,rlow,rhigh);
    else if(mid>=rhigh)
        return query(left,low,mid,rlow,rhigh);
    else
    {
        ll  left_ind=query(right,mid+1,high,mid+1,rhigh);
        ll right_ind=query(left,low,mid,rlow,mid);

        if(arr[left_ind]<arr[right_ind])
            return left_ind;
        else
            return right_ind;
    }
}

ll area(ll low,ll high)
{
    if(high<low)
        return 0;
    if(low==high)
        return arr[low];
    ll ind=query(1,1,N,low,high);

    ll cur=(high-low+1)*arr[ind];

    ll L=area(low,ind-1);
    ll R=area(ind+1,high);

    return max(max(R,L),cur);

}

main()
{
    #ifdef redback
        freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    #endif

    ll t=1,tc;
    ll i,j,k,l,m,n;
    read(tc);
    while(tc--)
    {
        read(n);
        N=n;
        for(i=1;i<=n;i++)
            read(arr[i]);
        init(1,1,n);
        ll ret=area(1,n);
        printf("Case %lld: %lld\n",t++,ret);
    }
    return 0;
}
