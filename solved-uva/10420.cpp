#include <cstdio>
#include <cstring>

main()
{
    char a[50],c[200];
    int t,i=0,j=0,k,l=0,b[202];
    for(i=0;i<200;i++)
    {
        b[i]=0;
    }
    scanf("%d",&t);
    char d[t][50];
    getchar();
    for(j=0;j<t;j++)
    {
        scanf("%s",a);
        getchar();
        gets(c);
        for(i=0;i<j;i++)
        {
            if(strcmp(a,d[i])==0)
            {
                b[i]++;
                break;
            }
        }
        if(i==j)
        {
            strcpy(d[l],a);
            b[l]++;
            l++;
        }
    }
    for(i=0;i<l-1;i++)
    {
        for(j=0;j<l-1-i;j++)
        {
            if(strcmp(d[j],d[j+1])>0)
            {
                strcpy(c,d[j]);
                strcpy(d[j],d[j+1]);
                strcpy(d[j+1],c);
                k=b[j];
                b[j]=b[j+1];
                b[j+1]=k;
            }
        }
    }
    for(i=0;i<l;i++)
    {
        printf("%s %d\n",d[i],b[i]);
    }
    return 0;
}
