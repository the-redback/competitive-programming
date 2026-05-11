#include <bits/stdc++.h>
using namespace std;

main()
{
    int count,i,j,k,l,t,n;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d %d",&n,&k);
        count=1;
        l=k;
        while(k%n!=0)
        {
            k=k%n;
            k=k*10+l;
            count++;
        }
        printf("Case %d: %d\n",i,count);
    }
    return 0;
}
