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


struct data
{
    long long sum;
    long long xtra;
}tree[300010];

void update(int node,int low,int high,int rlow,int rhigh,int value)
{
    if(low>=rlow && high<=rhigh)
    {
        tree[node].sum+=(high-low+1)*value;
        tree[node].xtra+=value;
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(low+high)/2;

    if(rhigh<=mid)
        update(left,low,mid,rlow,rhigh,value);
    else if(rlow>mid)
        update(right,mid+1,high,rlow,rhigh,value);
    else
    {
        update(left,low,mid,rlow,rhigh,value);
        update(right,mid+1,high,rlow,rhigh,value);
    }
    tree[node].sum=tree[left].sum+tree[right].sum+tree[node].xtra*(high-low+1);
}

long long query(int node,int low,int high,int rlow,int rhigh,long long carry)
{
    if(low>=rlow && high<=rhigh)
    {
        return tree[node].sum+carry*(high-low+1);
    }
    int left=node*2;
    int right=left+1;
    int mid=(low+high)/2;

    long long p1=0,p2=0;
    if(rhigh<=mid)
        p1=query(left,low,mid,rlow,rhigh,carry+tree[node].xtra);
    else if(rlow>mid)
        p2=query(right,mid+1,high,rlow,rhigh,carry+tree[node].xtra);
    else
    {
        p1=query(left,low,mid,rlow,rhigh,carry+tree[node].xtra);
        p2=query(right,mid+1,high,rlow,rhigh,carry+tree[node].xtra);
    }
    return p1+p2;
}

main()
{
    ios_base::sync_with_stdio(false);
    int tc,t=1;
    cin>>tc;
    while(tc--)
    {
        int n,q;
        cin>>n>>q;
        printf("Case %d:\n",t++);
        mem(tree,0);
        while(q--)
        {
            int i,j,k,l;
            cin>>i;
            if(i==0)
            {
                cin>>j>>k>>l;
                update(1,1,n,j+1,k+1,l);
            }
            else if(i==1)
            {
                cin>>j>>k;
                long long ans=query(1,1,n,j+1,k+1,0);
                printf("%lld\n",ans);
            }
        }
    }
    return 0;
}

/*
Input:
2
10 5
0 0 9 10
1 1 6
0 3 7 2
0 4 5 1
1 5 5
20 3
0 10 12 1
1 11 12
1 19 19

Output:
Case 1:
60
13
Case 2:
2
0
*/
