/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : the_redback
 *    @link       : http://www.fb.com/maruf.2hin
 */
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
using namespace std;

#define mp make_pair
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 1e9
#define eps 1e-9
#define NN 1050

int a[100010];
int mxx;
int mnn;
int sum;

struct data
{
    int mx;
    int mn;
}tree[400010];

void make(int node,int low,int high)
{
    if(low==high)
    {
        tree[node].mx=a[low];
        tree[node].mn=a[low];
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(low+high)/2;
    make(left,low,mid);
    make(right,mid+1,high);
    tree[node].mx=max(tree[left].mx,tree[right].mx);
    tree[node].mn=min(tree[left].mn,tree[right].mn);
    return;
}

void query(int node,int low,int high,int rlow,int rhigh)
{
    if(low>=rlow && high<=rhigh)
    {
        mxx=max(mxx,tree[node].mx);
        mnn=min(mnn,tree[node].mn);
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(low+high)/2;

    if(rhigh<=mid)
        query(left,low,mid,rlow,rhigh);
    else if(rlow>mid)
        query(right,mid+1,high,rlow,rhigh);
    else
    {
        query(left,low,mid,rlow,rhigh);
        query(right,mid+1,high,rlow,rhigh);
    }
    return;
}

main()
{
    ios_base::sync_with_stdio(false);
    int t=1,tc;
    cin>>tc;
    while(tc--)
    {
        int i,j,n,k;
        cin>>n>>k;
        for(i=1;i<=n;i++)
            cin>>a[i];
        make(1,1,n);
        sum=0;
        for(i=1;i<=n-k+1;i++)
        {
            mxx=0;
            mnn=inf;
            query(1,1,n,i,i+k-1);
            sum=max(sum,mxx-mnn);
        }
        printf("Case %d: %d\n",t++,sum);
    }
    return 0;
}
