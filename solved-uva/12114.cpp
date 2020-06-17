#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <string>
using namespace std;

main()
{
    long n,m,i=1;
    while(scanf("%ld %ld",&n,&m)==2)
    {
        if(n==0 && m==0)
            return 0;
        else if(n==1)
            printf("Case %d: :-\\\n",i++);
        else if(n<=m)
            printf("Case %d: :-|\n",i++);
        else
            printf("Case %d: :-(\n",i++);
    }
    return 0;
}
