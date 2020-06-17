#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<stack>
using namespace std;
__int64 m[300000];
main()
{
    int i,j,l,flag;
    int k;

    __int64 n;
    while(~scanf("%I64d %d",&n,&k))
    {
        for(i=0; i<k; i++)
            scanf("%I64d",&m[i]);
        sort(m,m+k);
        flag=1;
        if(m[0]==1||m[k-1]==n)
        {
            printf("NO\n");
            continue;
        }
        for(i=0; i<k-2; i++)
        {

            if(m[i+2]-m[i]==2)
            {
                flag=0;
                break;
            }
        }
        if(flag==0)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
