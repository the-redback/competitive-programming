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
        int q=x%k;
        int p=k-q;
        printf("%d %d\n",p,q);
    }
    return 0;
}
