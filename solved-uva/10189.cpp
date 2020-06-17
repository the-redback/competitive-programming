#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int b[105][105];
void check(int i,int j)
{
    i++;
    j++;
    b[i-1][j-1]++;
    b[i-1][j]++;
    b[i-1][j+1]++;
    b[i][j-1]++;
    b[i][j+1]++;
    b[i+1][j-1]++;
    b[i+1][j]++;
    b[i+1][j+1]++;

}
main()
{
    char a[101][101];
    char ch;
    int i,j,n,k=0,m,l;
    while(scanf("%d %d",&n,&m))
    {
        getchar();
        if(n==0 && m==0)
            return 0;
        memset(b,0,sizeof(b));
        k++;
        for(i=0;i<n;i++)
        {
            gets(a[i]);
            for(j=0;j<m;j++)
            {
                if(a[i][j]=='*')
                {
                    check(i,j);
                }
            }
        }
        if(k!=1)
            printf("\n");
        printf("Field #%d:\n",k);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(a[i][j]!='*')
                    printf("%d",b[i+1][j+1]);
                else
                    printf("*");
            }
            printf("\n");
        }
    }
    return 0;
}
