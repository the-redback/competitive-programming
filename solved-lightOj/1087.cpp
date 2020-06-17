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
#define NN 150010

int tree[4*NN];
int arr[NN];
int N;

void build(int node,int low,int high)
{
    if(low==high)
    {
        tree[node]=1;
        if(low>N)
            tree[node]=0;
        return;
    }
    int mid=(low+high)/2;
    int left=node*2;
    int right=left+1;
    build(left,low,mid);
    build(right,mid+1,high);

    tree[node]=tree[left]+tree[right];
    return;
}

void query(int node,int low,int high,int k)
{
    if(low==high)
    {
        printf("%d\n",arr[low]);
        tree[node]=0;
        return;
    }
    int mid=(low+high)/2;
    int left=node*2;
    int right=left+1;
    if(k<=tree[left])
        query(left,low,mid,k);
    else
        query(right,mid+1,high,k-tree[left]);

    tree[node]=tree[left]+tree[right];
    return;
}

void update(int node,int low,int high,int id,int val)
{
    if(low==high && low==id)
    {
        tree[node]=1;
        arr[low]=val;
        return;
    }
    int mid=(low+high)/2;
    int left=node*2;
    int right=left+1;
    if(id<=mid)
        update(left,low,mid,id,val);
    else
        update(right,mid+1,high,id,val);

    tree[node]=tree[left]+tree[right];
    return;
}


main()
{
//    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    scanf("%d",&tc);
    int i,j,k,l;
    int r,c;
    int n,m;
    while(tc--)
    {
        scanf("%d%d",&n,&m);
        N=n;
        char a[3];
        for(i=1;i<=n;i++)
            scanf("%d",&arr[i]);

        printf("Case %d:\n",t++);
        int siz=n+m;
        build(1,1,siz);
        while(m--)
        {
            scanf("%s %d",&a,&k);
            if(a[0]=='a')
                update(1,1,siz,++n,k);
            else
            {
                if(tree[1]<k)
                    puts("none");
                else
                    query(1,1,siz,k);
            }
        }
    }
    return 0;
}
