#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
using namespace std;

main()
{
    char s[10][10];
    int a[4];
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        getchar();
        int i,j,k,l,n;
        k=0;
        for(i=0;i<8;i++)
        {
            gets(s[i]);
            for(j=0;j<8;j++)
            {
                if(s[i][j]=='K')
                {
                    a[k++]=i;
                    a[k++]=j;
                }
            }
        }
        k=abs(a[0]-a[2]);
        l=abs(a[1]-a[3]);
        if(k%4==0 && l%4==0)
            puts("YES");
        else
            puts("NO");
    }
}
