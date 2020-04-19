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

#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pp pop_back
#define inf 1000000000
#define NN 500100

struct data
{
    int totalsum,maxsum,leftmax,rightmax;
    data(int k)
    {
        totalsum=maxsum=leftmax=rightmax=k;
    }
    data()
    {

    }
}arr[NN];

int a[65010];

data merge(data a,data b)
{
    data ret;
    ret.totalsum=(a.totalsum+b.totalsum);
    ret.maxsum=max(max(a.maxsum,b.maxsum),a.rightmax+b.leftmax);
    ret.leftmax=max(a.leftmax,a.totalsum+b.leftmax);
    ret.rightmax=max(b.rightmax,b.totalsum+a.rightmax);
    return ret;
}

void init(int node,int low,int high)
{
    if(low==high)
    {
        arr[node]=data(a[low]);
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(low+high)/2;

    init(left,low,mid);
    init(right,mid+1,high);
    arr[node]=merge(arr[left],arr[right]);
    return;
}

data query(int node,int low,int high,int rlow,int rhigh)
{
    if(low>=rlow && high<=rhigh)
        return arr[node];
    int left=node*2;
    int right=left+1;
    int mid=(low+high)/2;

    if(rhigh<=mid)
        return query(left,low,mid,rlow,rhigh);
    else if(rlow>mid)
        return query(right,mid+1,high,rlow,rhigh);
    else
    {
        data L=query(left,low,mid,rlow,rhigh);
        data R=query(right,mid+1,high,rlow,rhigh);
        return merge(L,R);
    }

}

void update(int node,int low,int high,int pos,int val)
{
    if(low==pos && high==pos)
    {
        arr[node]=data(val);
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(low+high)/2;

    if(pos<=mid)
        update(left,low,mid,pos,val);
    else
        update(right,mid+1,high,pos,val);
    arr[node]=merge(arr[left],arr[right]);
    return;

}

main()
{
    ios_base::sync_with_stdio(false);
    int t,tc;
    int i,j,k;
    int res,u,w,p,n,x,y,z,m,q,r,v,zero;
    //cin>>tc;
    while(cin>>n)
    {
        for(i=1;i<=n;i++)
            cin>>a[i];
        init(1,1,n);
        cin>>k;
        while(k--)
        {
            cin>>j>>x>>y;
            if(j==0)
                update(1,1,n,x,y);
            else
            {
                data dt=query(1,1,n,x,y);
                printf("%d\n",dt.maxsum);
            }

        }
    }
    return 0;
}

/*
Input:
4
1 2 3 4
4
1 1 3
0 3 -3
1 2 4
1 3 3
Output:
6
4
-3
*/
