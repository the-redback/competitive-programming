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
#define inf HUGE_VAL
#define mem(a,b) memset(a,b,sizeof(a))

main()
{
    int tc,t=1;
    int i,j,k,l,x;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d%d",&x,&k);
        //printf("Case %d:\n",t++);
        if(x%k==0)
            printf("0 %d\n",k);
        else
            printf("%d %d\n",-x,x);
    }
    return 0;
}
