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
#define NN        100100

//cout << setfill('0') << setw(3) << a << endl;
//cout << fixed << setprecision(20) << a << endl;

ll tree[NN*4];
ll a[NN];
ll N;

void init(ll ind,ll low,ll high)
{
    if(low==high)
    {
        tree[ind]=a[low];
        return ;
    }

    ll mid=(low+high)>>1;
    ll left=ind<<1;
    ll right=left+1;
    init(left,low,mid);
    init(right,mid+1,high);
    tree[ind]=min(tree[left],tree[right]);
    return;
}

ll query(ll ind,ll low,ll high,ll rlow,ll rhigh)
{

    if(low>=rlow && high<=rhigh)
    {
        return tree[ind];
    }
    ll mid=(low+high)>>1;
    ll left=ind<<1;
    ll right=left+1;

    if(mid<rlow)
        return query(right,mid+1,high,rlow,rhigh);
    else if(mid>=rhigh)
        return query(left,low,mid,rlow,rhigh);
    else
    {
        ll p=query(right,mid+1,high,mid+1,rhigh);
        ll q=query(left,low,mid,rlow,mid);

        return min(p,q);
    }
}

ll goLeft(ll val,ll low,ll high)
{
    ll ret=0;

    while(low<=high)
    {
        ll mid=(low+high)>>1;
        if(query(1,1,N,mid,high)>=val)
            ret+=high-mid+1,high=mid-1;
        else
            low=mid+1;
    }
    return ret;
}

ll goRight(ll val,ll low,ll high)
{
    ll ret=0;
    while(low<=high)
    {
        ll mid=(low+high)>>1;

        if(query(1,1,N,low,mid)>=val)
            ret+=mid-low+1,low=mid+1;
        else
            high=mid-1;
    }
    return ret;
}

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    ll i,j,k,l,m,n;
    cin>>tc;
    while(tc--)
    {
        cin>>n;
        N=n;
        for(i=1;i<=n;i++)
            cin>>a[i];
        init(1,1,n);
        ll ret=0;
        for(i=1;i<=n;i++)
        {
            ll left=goLeft(a[i],1,i-1);
            ll right=goRight(a[i],i+1,n);
            ll dist=left+right+1;
            ll res=dist*a[i];
            ret=max(ret,res);
        }
        cout<<"Case "<<t++<<": "<<ret<<"\n";
    }
    return 0;
}
