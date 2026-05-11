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

#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pp pop_back
#define inf 10e9 //10^9
#define meminf 100
#define eps 10e-5
#define NN 1000000

main()
{
    ios_base::sync_with_stdio(false);
    int t=1,tc;
    int i,j,r,l,m,n,k;
    int y,z,u,w,xx,yy,zz,d,h,e;
    int aa,bb,cc,p,dd,arr,res;
    //cin>>tc;
    while(cin>>r>>arr>>p>>k)
    {
        res=0;
        e=0;
        r-=1;
        int fl=1;
        while(fl)
        {
            res++;
            if(p>0)
            {
                if(p<r)
                {
                    e+=(p+1)*k;
                    p=0;
                }
                else
                {
                    e+=(r+1)*k;
                    p-=r;
                }
            }
            else e+=k;
            if(e>=arr) break;
        }
        cout<<res<<endl;
    }
    return 0;
}
