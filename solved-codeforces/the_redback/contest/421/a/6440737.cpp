/**
 *                                   ____
 *       ____ ___  ____ ________  __/ __/
 *      / __ `__ \/ __ `/ ___/ / / / /_
 *     / / / / / / /_/ / /  / /_/ / __/
 *    /_/ /_/ /_/\__,_/_/   \__,_/_/
 *
 *    @link : https://the-redback.com
 */
#include <bits/stdc++.h>
using namespace std;

#define ppb pop_back
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 1000000000
#define eps 1e-9
#define NN 400010
int a[1000];

main()
{
    ios_base::sync_with_stdio(false);
    int t,tc;
    //cin>>tc;
    int i,j,k,l,n,m;
    while(cin>>n>>k>>l)
    {
        mem(a,0);
        for(i=0;i<k;i++)
        {
            cin>>j;
            a[j]=1;
        }
        for(i=0;i<l;i++)
        {
            cin>>j;
            if(!a[j])
                a[j]=2;
        }
        for(i=1;i<=n;i++)
        {
            if(i!=1)
                printf(" ");
            if(a[i]==0)
                a[i]=2;
            printf("%d",a[i]);
        }
        


    }
    return 0;
}
