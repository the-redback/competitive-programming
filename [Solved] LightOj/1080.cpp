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

char a[100000];
int flag[300100];
int N,M;
void update(int node,int low,int high,int rlow,int rhigh)
{
    if(rlow<=low&&rhigh>=high)
    {
        flag[node]++;
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(low+high)/2;

    if(rhigh<=mid)
        update(left,low,mid,rlow,rhigh);
    else if(rlow>mid)
        update(right,mid+1,high,rlow,rhigh);
    else
    {
        update(left,low,mid,rlow,rhigh);
        update(right,mid+1,high,rlow,rhigh);
    }
    return;
}

bool value(int node,int low,int high,int pos,int carry)
{
    if(pos==low && pos==high)
    {
        int k=a[pos-1]-'0';
        return ((carry+flag[node])%2)?k^1:k;
    }

    int left=node*2;
    int right=left+1;
    int mid=(low+high)/2;

    bool p1=0,p2=0;
    if(pos<=mid)
        return value(left,low,mid,pos,carry+flag[node]);
    else
        return value(right,mid+1,high,pos,carry+flag[node]);
}

main()
{

    int tc,t=1;
    scanf("%d",&tc);
    for(t=1;t<=tc;t++)
    {
        scanf("%s",&a);
        int q;
        int l=strlen(a);
        scanf("%d",&q);
        printf("Case %d:\n",t);
        memset(flag,0,sizeof(flag));
        while(q--)
        {
            char ch[5];
            scanf("%s",&ch);
            if(ch[0]=='I')
            {
                int i,j;
                scanf("%d%d",&i,&j);
                update(1,1,l,i,j);
            }
            else if(ch[0]=='Q')
            {
                int i;
                scanf("%d",&i);
                int k=value(1,1,l,i,0);
                printf("%d\n",k);
            }
        }
    }
    return 0;
}
