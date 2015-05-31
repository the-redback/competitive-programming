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
#define NN 400010

struct data
{
    long long sum,step;
}arr[NN];


void update(int node,int l,int h,int rl,int rh,long long val)
{
    if(l>rh||h<rl)
        return;
    if(l>=rl && h<=rh)
    {
        arr[node].sum+=val*(h-l+1);
        arr[node].step+=val;
        return;
    }
    int left=node*2;
    int right=(node*2)+1;
    int mid=(l+h)/2;
    update(left,l,mid,rl,rh,val);
    update(right,mid+1,h,rl,rh,val);
    arr[node].sum=arr[left].sum+arr[right].sum+arr[node].step*(h-l+1);
    return;
}

long long query(int node,int l,int h,int rl,int rh,long long carry)
{
    if(l>rh||h<rl)
        return 0;
    if(l>=rl && h<=rh)
    {
        long long ret=carry*(h-l+1);
        ret+=arr[node].sum;
        return ret;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(l+h)/2;
    long long L=query(left,l,mid,rl,rh,carry+arr[node].step);
    long long R=query(right,mid+1,h,rl,rh,carry+arr[node].step);
    return L+R;
}

main()
{
    ios_base::sync_with_stdio(false);
    int t,tc;
    int i,j,k;
    int n,x,y,r,val;
    cin>>tc;
    while(tc--)
    {
        cin>>n>>k;
        mem(arr,0);
        while(k--)
        {
            cin>>r;
            if(r==0)
            {
                cin>>x>>y>>val;
                update(1,1,n,x,y,val);
            }
            else
            {
                cin>>x>>y;
                long long res=query(1,1,n,x,y,0);
                printf("%lld\n",res);
            }

        }
    }
    return 0;
}


