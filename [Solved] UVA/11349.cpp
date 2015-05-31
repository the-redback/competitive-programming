#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
main()
{
    int sum,x,y,n,t=1,tc,i,j,k,l;
    long long a[200][200];
    char c[12];
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%s = %d",&c,&n);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%lld",&a[i][j]);
        k=n/2;
        int flag=0;
        for(i=0;i<=k;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[i][j]!=a[n-1-i][n-1-j] ||a[n-1-i][n-1-j]<0 || a[i][j]<0 )
                {
                    flag=1;
                    break;
                }
            }
            if(flag)
                break;
        }
        if(flag)
        {
            printf("Test #%d: Non-symmetric.\n",t++);
        }
        else
            printf("Test #%d: Symmetric.\n",t++);
    }
    return 0;
}
