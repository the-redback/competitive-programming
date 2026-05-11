/**
 *                                   ____
 *       ____ ___  ____ ________  __/ __/
 *      / __ `__ \/ __ `/ ___/ / / / /_
 *     / / / / / / /_/ / /  / /_/ / __/
 *    /_/ /_/ /_/\__,_/_/   \__,_/_/
 *
 *    @link : https://the-redback.com
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

#define ppb pop_back
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 1000000000
#define eps 1e-9
#define NN 400010

vector<int>x,y;

main()
{
    ios_base::sync_with_stdio(false);
    int t,tc;
    //cin>>tc;
    int i,j,k,l,m,n;
    int v;
    while(cin>>n>>m>>k)
    {
        for(i=1;i<=n;i++)
        {
            if(i%2)
            {
                for(j=1;j<=m;j++)
                {
                    x.pb(i);
                    y.pb(j);
                }
            }
            else
            {
                for(j=m;j>=1;j--)
                {
                    x.pb(i);
                    y.pb(j);
                }
            }
        }
        int last=0;
        j=0;
        while(k)
        {
            int hand=((int)x.size()-last)/k;
            printf("%d ",hand);
            for(i=0;i<hand;i++)
            {
                printf("%d %d ",x[j],y[j]);
                j++;
            }
            last+=hand;
            k--;
            if(k)
                puts("");
        }
        x.clear();
        y.clear();

    }
    return 0;
}
