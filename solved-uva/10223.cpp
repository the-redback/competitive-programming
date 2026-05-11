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
#define inf 1000000000
#define NN 30

long long a[25];


int main()
{
    int i,j,k,l;
    int tc,t;
    int n,m;
    long long x,y,z;
    a[0]=0;
    a[1]=1;
    for(i=2;i<=20;i++)
    {
        x=a[i-1]*2*(2*i-1);
        a[i]=x/(i+1);
    }
    while(~scanf("%lld",&x))
    {
        for(i=0;i<20;i++)
        {
            if(a[i]<x && x<=a[i+1])
            {
                printf("%d\n",i+1);
                break;
            }
        }
    }
    return 0;
}
