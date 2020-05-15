#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
    char c[4][4];
    void swap(int i,int j)
    {
        if(c[i][j]=='o')
        {
            c[i][j]='f';
        }
        else
            c[i][j]='o';
    }

main()
{
    int i,j,k,l,m,n;
    int a[4][4];
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
        c[i][j]='o';

    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
        {
            scanf("%d",&a[i][j]);
        }
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
        {
            if(a[i][j]!=0)
            {
                if(a[i][j]%2!=0)
                {
                     swap(i,j);
                     swap(i,j-1);
                     swap(i,j+1);
                     swap(i-1,j);
                     swap(i+1,j);
                }
            }
        }

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(c[i][j]=='f')
            {
                printf("0");
            }
            else
                printf("1");
        }
        printf("\n");
    }
    return 0;
}
