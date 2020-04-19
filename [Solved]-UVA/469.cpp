#include <bits/stdc++.h>
using namespace std;
char a[200][200];
char c[200][200];
int N,M;
int dirx[]= {-1,0,0,1,-1,-1,1,1};
int diry[]= {0,-1,1,0,-1,1,-1,1};

int call(int i,int j)
{
    if(i<0 || j<0 || i>=N|| j>=M)
        return 0;
    if(c[i][j]!='W')
        return 0;
    c[i][j]='L';
    int sum=1;
    for(int k=0; k<8; k++)
    {
        sum+=call(i+dirx[k],j+diry[k]);
    }
    return sum;
}

void copy(void)
{
    int i,j;
    for(i=0; i<N; i++)
    {
        strcpy(c[i],a[i]);
    }
}

main()
{
    int tc,flag=0;
    cin>>tc;
    getchar();
    getchar();
    while(tc--)
    {
        if (flag!=0)
            puts("");
        flag=1;
        int i=0,j;
        while(gets(a[i]))
        {
            if(a[i][0]!='L' && a[i][0]!='W')
                break;
            i++;
        }
        N=i;
        M=strlen(a[0]);
        sscanf(a[i],"%d %d",&i,&j);
        int sum=0;
        if(i-1<N && j-1<M)
        {
            copy();
            sum=call(i-1,j-1);
        }
        printf("%d\n",sum);
        char b[20];
        while(gets(b))
        {
            if(strlen(b)==0)
                break;
            sscanf(b,"%d %d",&i,&j);
            sum=0;
            if(i-1<N && j-1<M)
            {
                copy();
                sum=call(i-1,j-1);
            }
            printf("%d\n",sum);
        }
    }
    return 0;
}
