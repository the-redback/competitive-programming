/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @TOPCODER   : the_redback
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

#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pp pop_back
#define inf 1000000000
#define NN 30

vector<int>v;

int main()
{
    int tc,t=1,ret=0;
    int i,j,k,l,r,cc;
    int n,m,x=0,y=0;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&r);
        if(r%2==0)
        {
            for(i=0;i<r/2;i++)
                scanf("%d",&k),x+=k;
            for(i=0;i<r/2;i++)
                scanf("%d",&k),y+=k;
        }
        else
        {
            for(i=0;i<r/2;i++)
                scanf("%d",&k),x+=k;
            scanf("%d",&k);
            v.pb(k);
            for(i=0;i<r/2;i++)
                scanf("%d",&k),y+=k;
        }
    }
    sort(v.rbegin(),v.rend());
    for(i=0;i<v.size();i++)
    {
        if(i%2==0)
            x+=v[i];
        else
            y+=v[i];
    }
    printf("%d %d\n",x,y);
    return 0;
}
