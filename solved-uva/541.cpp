#include<stdio.h>
#include<string.h>
#include <algorithm>
using namespace std;

main()
{
    int i,j,r,count,flag,c,n;
    int a[101][101];
    while(scanf("%d",&n))
    {
        r=-1;
        c=-1;
        flag=0;
        if(n==0)
            return 0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for(i=0;i<n;i++)
        {
            count=0;
            for(j=0;j<n;j++)
            {
                count+=a[i][j];
            }
            if(count%2!=0)
            {
                if(r==-1)
                    r=i+1;
                else
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1)
        {
            printf("Corrupt\n");
            continue;
        }
        for(i=0;i<n;i++)
        {
            count=0;
            for(j=0;j<n;j++)
            {
                count+=a[j][i];
            }
            if(count%2!=0)
            {
                if(c==-1)
                    c=i+1;
                else
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1)
        {
            printf("Corrupt\n");
            continue;
        }
        if(c==-1 && r==-1)
        {
            printf("OK\n");
        }
        else
        {
            printf("Change bit (%d,%d)\n",r,c);
        }
    }
    return 0;
}
