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

int parent[100010];
int tree[300010];
void makeTree(int node,int low,int high)
{
    if(low==high)
    {
        tree[node]=parent[low];
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(low+high)/2;
    makeTree(left,low,mid);
    makeTree(right,mid+1,high);
    tree[node]=tree[right]+tree[left];
    return;
}

int value(int node, int low,int high, int rlow, int rhigh)
{
    if(low>=rlow && high<=rhigh)
        return tree[node];
    int left=node*2;
    int right=left+1;
    int mid=(low+high)/2;

    if(rhigh<=mid)
        return value(left,low,mid,rlow,rhigh);
    else if(rlow>mid)
        return value(right,mid+1,high,rlow,rhigh);
    else
    {
        right=value(right,mid+1,high,rlow,rhigh);
        left=value(left,low,mid,rlow,rhigh);
        return (left+right);
    }

}

void update(int node,int low,int high,int pos)
{
    if(low==pos && high==pos)
    {
        tree[node]=parent[pos];
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(low+high)/2;

    if(pos<=mid)
        update(left,low,mid,pos);
    else
        update(right,mid+1,high,pos);
    tree[node]=tree[right]+tree[left];
    return;
}

main()
{
    ios_base::sync_with_stdio(false);
    int tc,i,t;
    cin>>tc;
    for(t=1;t<=tc;t++)
    {
        int n,q;
        cin>>n>>q;
        for(int i=1;i<=n;i++)
            cin>>parent[i];
        makeTree(1,1,n);
        printf("Case %d:\n",t);
        while(q--)
        {
            int i,j,k,v;
            cin>>k;
            if(k==1)
            {
                cin>>i;
                printf("%d\n",parent[i+1]);
                parent[i+1]=0;
                update(1,1,n,i+1);
            }
            else if(k==2)
            {
                cin>>i>>v;
                parent[i+1]+=v;
                update(1,1,n,i+1);
            }
            else if(k==3)
            {
                cin>>i>>j;
                k=value(1,1,n,i+1,j+1);
                printf("%d\n",k);
            }
        }
    }
    return 0;
}
