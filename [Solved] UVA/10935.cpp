#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
main()
{
    queue <int> q;
    int i,k,n;
    while(scanf("%d",&n)==1)
    {
        if(n==0)
            return 0;
        for(i=1;i<=n;i++)
            q.push(i);
        printf("Discarded cards:");
        i=0;
        k=0;
        while(q.size()!=1)
        {
            if(k==0)
            {
                if(i!=0)
                    printf(",");
                printf(" %d",q.front());
                q.pop();
                k=1;
            }
            else
            {
                q.push(q.front());
                q.pop();
                k=0;
            }
            i=1;
        }
        puts("");
        printf("Remaining card: %d\n",q.front());
        q.pop();
    }
    return 0;
}
