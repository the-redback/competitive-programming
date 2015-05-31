#include <bits/stdc++.h>
using namespace std;
char a[200][200];
int N;
int dirx[]={-1,-1,-1,0,0,1,1,1};
int diry[]={-1,0,1,-1,1,-1,0,1};
void call(int i,int j)
{
    if(i<0 || j<0 || i>=N|| j>=N)
        return;
    if(a[i][j]!='1')
        return;

    a[i][j]='0';
    for(int k=0;k<8;k++)
    {
        call(i+dirx[k],j+diry[k]);
    }
    return;
}

main()
{
    int total=1;
    while(scanf("%d",&N)==1)
    {
        getchar();
        for(int k=0;k<N;k++)
        {
            scanf("%s",&a[k]);
        }
        int sum=0;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(a[i][j]=='1')
                {
                    sum++;
                    call(i,j);
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n",total++,sum);
    }
    return 0;
}
