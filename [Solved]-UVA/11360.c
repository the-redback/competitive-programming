#include <stdio.h>
#include <string.h>
int inc(int a[10][10],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            a[i][j]++;
            if(a[i][j]>9)
            {
                a[i][j]=a[i][j]-10;
            }
        }
    }
}

int trans(int a[10][10],int n)
{
    int b[10][10];
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            b[j][i]=a[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            a[i][j]=b[i][j];
        }
    }
}

int dec(int a[10][10],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            a[i][j]--;
            if(a[i][j]<0)
            {
                a[i][j]=a[i][j]+10;
            }
        }
    }
}

int row(int a[10][10],int n, int s1,int s2)
{
    s1--;
    s2--;
    int i,j,k,temp;
    i=s1;
    k=s2;
        for(j=0;j<n;j++)
        {
            temp=a[i][j];
            a[i][j]=a[k][j];
            a[k][j]=temp;
        }
}

int col(int a[10][10],int n, int s1,int s2)
{
    s1--;
    s2--;
    int i,j,k,temp;
    i=s1;
    k=s2;
        for(j=0;j<n;j++)
        {
            temp=a[j][i];
            a[j][i]=a[j][k];
            a[j][k]=temp;
        }
}
main()
{
    int i,j,k,n,b,m,t,test,p,s1,s2;
    int a[10][10];
    char c[11],d[10];
    scanf("%d",&test);
    for(t=1;t<=test;t++)
    {
        scanf("%d",&n);
        getchar();
        for(i=0;i<n;i++)
        {
            gets(c);
            for(j=0;j<n;j++)
            {
                a[i][j]=c[j]-48;
            }
        }
        scanf("%d",&m);
        getchar();
        while(m--)
        {
            scanf("%s",&d);
            if(strcmp(d,"row")==0)
            {
                scanf("%d %d",&s1,&s2);
                row(a,n,s1,s2);
            }
            else if(strcmp(d,"col")==0)
            {
                scanf("%d %d",&s1,&s2);
                col(a,n,s1,s2);
            }
            else if(strcmp(d,"inc")==0)
            {
                inc(a,n);
            }
            else if(strcmp(d,"dec")==0)
            {
                dec(a,n);
            }
            else if(strcmp(d,"transpose")==0)
            {
               trans(a,n);
            }
        }
        printf("Case #%d\n",t);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                printf("%d",a[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
