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
Map the community numbers in incresing order.
Build segment tree on max occurences of community no.
for each query find the rightmost community that is
completely inside the range, find the leftmost community
that is completely inside the range(both with binary search Or L/R array),
with a segment tree find the strongest community between the
two communities that have been just found and check if the
communities on the extremes of the range are stronger
then those inside the range.
*/
ll arr[NN];
ll tree[4*NN];
ll L[NN];
ll R[NN];

void init(ll node,ll low,ll high)
{
    if(low==high)
    {
        tree[node]=arr[low];
        return;
    }

    ll left=node<<1;
    ll right=left+1;
    ll mid=(low+high)>>1;

    init(left,low,mid);
    init(right,mid+1,high);

    tree[node]=max(tree[left],tree[right]);

    return;
}
long long query(int node, int low, int high, int rlow, int rhigh)
{
    if(low>=rlow && high<=rhigh)
    {
        return tree[node];
    }
    int left = node*2;
    int right = left + 1;
    int mid = (low + high)/2;

    long long p1=0, p2=0;
    if(rhigh<=mid)
        p1=query(left, low, mid, rlow, rhigh);
    else if(rlow>mid)
        p2=query(right, mid+1, high, rlow, rhigh);
    else
    {
        p1=query(left, low, mid, rlow, mid);
        p2=query(right, mid+1, high, mid+1, rhigh);
    }
    return max(p1,p2);
}


int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef redback
        freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    #endif

    ll temp[NN];
    ll t=1,tc;
    read(tc);
    ll i,j,k,l,m,q,n;
    while(tc--)
    {
        read(n);
        read(m);
        read(q);

        mem(arr,0);

        ll last=-1;
        for(i=1,j=0;i<=n;i++)
        {
            read(k);
            if(k!=last)
            {
                j++;
                last=k;
            }
            temp[i]=j;
            arr[j]++;
        }
        init(1,1,m);
        L[1]=0;
        for(i=2;i<=n;i++)
        {
            if(temp[i]!=temp[i-1])
                L[i]=i-1;
            else
                L[i]=L[i-1];
        }

        R[n]=n+1;
        for(i=n-1;i>=1;i--)
        {
            if(temp[i]!=temp[i+1])
                R[i]=i+1;
            else
                R[i]=R[i+1];
        }

        printf("Case %lld:\n",t++);
        for(i=0;i<q;i++)
        {
            read(k);
            read(l);

            ll ans=0;

            if(R[k]<=l && temp[R[k]]!=temp[l])
            {
                ans=query(1,1,m,temp[R[k]],temp[L[l]]);
                ans=max(ans, max(R[k]-k,l-L[l]));
            }
            else if(R[k]<=l)
            {
                ans=max(R[k]-k,l-L[l]);
            }
            else
                ans=l-k+1;
            printf("%lld\n",ans);
        }
    }
    return 0;
}
