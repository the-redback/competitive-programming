#include <bits/stdc++.h>
using namespace std;
char a[200][200];
int M,N;
int dirx[]={-1,-1,-1,0,0,1,1,1};
int diry[]={-1,0,1,-1,1,-1,0,1};
void call(int i,int j)
{
    if(i<0 || j<0 || i>=M|| j>=N)
        return;
    if(a[i][j]!='@')
        return;

    a[i][j]='*';
    for(int k=0;k<8;k++)
    {
        call(i+dirx[k],j+diry[k]);
    }
    return;
}

main()
{
    while(scanf("%d%d",&M,&N)==2)
    {
        getchar();
        if(M==0)
            return 0;
        for(int k=0;k<M;k++)
        {
            scanf("%s",&a[k]);
        }
        int sum=0;
        for(int i=0;i<M;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(a[i][j]=='@')
                {
                    sum++;
                    call(i,j);
                }
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
