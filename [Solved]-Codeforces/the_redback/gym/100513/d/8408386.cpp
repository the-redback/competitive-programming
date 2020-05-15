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

struct D
{
    ll num,id,fl;
    D(ll Num,ll Id,ll Fl)
    {
        num=Num,id=Id,fl=Fl;
    }
    D()
    {

    }

} a[NN],L[NN],R[NN];

vector<D>v;

bool comp(D aa,D bb)
{
    if(aa.num==bb.num)
        return aa.fl>bb.fl;
    return aa.num>bb.num;
}

bool bl[NN];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1,tc;
    //cin>>tc;
    ll i,j,k,l,m,n;
    cin>>n>>k;
    ll rr=0,lo=0;
    for(i=0; i<n; i++)
    {
        cin>>j>>l;
        a[i]=D(j,i,l);
        if(l==1)
            R[rr++]=D(j,i,l);
        else if(l==0)
            L[lo++]=D(j,i,l);
    }
    sort(a,a+n,comp);

    ll sum=0,cnt=0;
    mem(bl,0);

    for(i=0; i<n && sum<k; i++)
    {
        sum+=a[i].num;
        cnt++;
    }
    sum=0;
    ll cnt1=0;

    sort(R,R+rr,comp);
    ll I=-1;
    for(i=0; i<rr && cnt1<cnt; i++)
    {
        I=i;
        sum+=R[i].num;
        cnt1++;
        bl[R[i].id]=1;
    }
    i=0;
    sort(L,L+lo,comp);

    while(cnt1<cnt && i<lo)
    {
        sum+=L[i].num;
        bl[L[i].id]=1;
        cnt1++;
        i++;
    }

    while(sum<k)
    {
        if(I>=0)
            sum-=R[I].num;
        sum+=L[i].num;
        bl[R[I].id]=0;
        bl[L[i].id]=1;
        I--;
        i++;
    }
    cout<<cnt<<" "<<I+1<<"\n";
    for(i=0;i<n;i++)
    {
        if(bl[i]==1)
        {
            cout<<i+1<<" ";
        }
    }
    cout<<"\n";


    return 0;
}
