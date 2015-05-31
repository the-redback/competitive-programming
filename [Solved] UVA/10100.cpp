#include<stdio.h>
#include<string.h>
#include <algorithm>
using namespace std;
char a[1001];
char b[1001];
char d[1000][21];
char c[1000][21];
int dp[1000][1000];
int n,m;
void dpwork(int m,int n)
{
    int i,j;
    for(i=0;i<=m;i++)
        for(j=0;j<=n;j++)
            dp[i][j]=-1;
}

int test(int i, int j)
{
    int x,y;
    if(i<0 || j<0)
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];
    if(strcmp(c[i],d[j])==0)
    {
        return test(i-1,j-1)+1;
    }
    else
    {
        x=test(i,j-1);
        y=test(i-1,j);
        if(x>y)
            dp[i][j]=x;
        else
            dp[i][j]=y;
    }
    return dp[i][j];
}

main()
{
    char e[21];
    int i,j,k,l,p,r,t=0;
    while(gets(a))
    {
        t++;
        gets(b);
        printf("%2d. ",t);
        if(a[0]=='\0' || b[0]=='\0')
        {
            printf("Blank!\n");

        }
        else
        {
            l=strlen(a);
            p=0;
            r=0;
            for(i=0;i<=l;i++)
            {
                if((a[i]>='a' && a[i]<='z' )||( a[i]>='A' && a[i]<='Z')||(a[i]>='0' && a[i]<='9'))
                {
                    c[p][r]=a[i];
                    r++;
                }
                else if((a[i-1]>='a' && a[i-1]<='z') || (a[i-1]>='A' && a[i-1]<='Z') ||(a[i-1]>='0' && a[i-1]<='9'))
                {
                    c[p][r]='\0';
                    p++;
                    r=0;
                }
            }
            m=p-1;
            l=strlen(b);
            p=0;
            r=0;
            for(i=0;i<=l;i++)
            {
                if((b[i]>='a' && b[i]<='z' )|| (b[i]>='A' && b[i]<='Z') ||(b[i]>='0' && b[i]<='9'))
                {
                    d[p][r]=b[i];
                    r++;
                }
                else if((b[i-1]>='a' && b[i-1]<='z') ||(b[i-1]>='A' && b[i-1]<='Z')||(b[i-1]>='0' && b[i-1]<='9'))
                {
                    d[p][r]='\0';
                    p++;
                    r=0;
                }
            }
            n=p-1;

            dpwork(m,n);
            p=test(m,n);
            printf("Length of longest match: %d\n",p);
        }
    }
    return 0;
}
