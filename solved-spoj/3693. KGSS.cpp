/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : the_redback
 *    @link       : maruf.2hin@gmail.com
 */
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<stack>
using namespace std;

#define ppb pop_back
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 1000000000
#define eps 1e-9
#define NN 100010

struct data
{
    int max1,max2;
    data(data a,data b)
    {
        if(a.max1>b.max1)
        {
            max1=a.max1;
            max2=max(a.max2,b.max1);
        }
        else
        {
            max1=b.max1;
            max2=max(b.max2,a.max1);
        }
    }
    data(int k)
    {
        max1=k;
        max2=0;
    }
    data(){}
}arr[4*NN];

int a[NN];

void init(int node,int l,int h)
{
    if(l==h)
    {
        arr[node]=data(a[l]);
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(l+h)/2;
    init(left,l,mid);
    init(right,mid+1,h);
    arr[node]=data(arr[left],arr[right]);
}

void update(int node,int l,int h,int pos,int val)
{
    if(l==pos && h==pos)
    {
        arr[node]=data(val);
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(l+h)/2;
    if(pos<=mid)
        update(left,l,mid,pos,val);
    else
        update(right,mid+1,h,pos,val);
    arr[node]=data(arr[left],arr[right]);
}

data query(int node,int l,int h,int ll,int lh)
{
    if(l==ll && h==lh)
    {
        return arr[node];
    }
    int left=node*2;
    int right=left+1;
    int mid=(l+h)/2;
    if(lh<=mid)
        return query(left,l,mid,ll,lh);
    if(ll>mid)
        return query(right,mid+1,h,ll,lh);
    data L=query(left,l,mid,ll,mid);
    data R=query(right,mid+1,h,mid+1,lh);
    return data(L,R);
}

char s[5];

main()
{
    ios_base::sync_with_stdio(false);
    int t,tc;
    int i,j,k;
    int n,x,y,r,val;
    //cin>>tc;
    while(~scanf("%d",&n))
    {
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        init(1,1,n);
        scanf("%d",&r);
        while(r--)
        {
            scanf("%s",&s);
            if(s[0]=='U')
            {
                scanf("%d%d",&x,&k);
                update(1,1,n,x,k);
            }
            else
            {
                scanf("%d%d",&x,&y);
                data d=query(1,1,n,x,y);
                printf("%d\n",d.max1+d.max2);
            }

        }
    }
    return 0;
}


