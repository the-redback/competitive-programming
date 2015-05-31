#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

main()
{
    bool a[10000];
    int Z,I,M,L,i,j=0,seed,count;
    while(scanf("%d %d %d %d",&Z,&I,&M,&L)==4)
    {
        memset(a,0,sizeof(a));
        if(Z==0 && I==0 && M==0 && L==0)
            return 0;
        j++;
        seed=L;
        count=0;
        while(1)
        {
            L=((Z*L)+I)%M;
            printf("%d\n",L);
            if(!a[L])
            {
                count++;
                a[L]=1;
            }
            else
                break;

        }
        printf("Case %d: %d\n",j,count);
    }
    return 0;
}
