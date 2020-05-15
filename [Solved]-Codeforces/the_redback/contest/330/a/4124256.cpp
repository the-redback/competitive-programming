#include <stdio.h>
#include <string.h>
#include <math.h>

main()
{
    char a[15][15];
    int i,j,k,l,sum=0,s;
    scanf("%d %d",&k,&l);
    for(i=0;i<k;i++)
        scanf("%s",&a[i]);
    int flag;
    for(i=0;i<k;i++)
    {
        s=0;
        flag=0;
        for(j=0;j<l;j++)
        {
            if(a[i][j]=='S')
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
            continue;
        for(j=0;j<l;j++)
        {
            if(a[i][j]!='*')
            {
                s++;
                a[i][j]='*';
            }
        }
            sum+=s;
    }
    for(j=0;j<l;j++)
    {
        s=0;
        flag=0;
        for(i=0;i<k;i++)
        {
            if(a[i][j]=='S')
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
            continue;
        for(i=0;i<k;i++)
        {
            if(a[i][j]!='*')
            {
                s++;
                a[i][j]='*';
            }
        }
            sum+=s;
    }
    printf("%d\n",sum);
    return 0;
}
