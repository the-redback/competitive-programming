#include <bits/stdc++.h>
using namespace std;
main()
{
    int mx,i,j,k,l,m,n;
    char a[111][111];
    i=0;
    mx=0;
    while(gets(a[i]))
    {
        l=strlen(a[i]);
        mx=max(l,mx);
        i++;
    }
    n=i;
    for(i=0; i<n; i++)
    {
        for(l=strlen(a[i]); l<mx; l++)
            a[i][l]=' ';
        a[i][l]=0;
    }
    for(j=0; j<mx; j++)
    {
        for(i=n-1; i>=0; i--)
            printf("%c",a[i][j]);
        printf("\n");
    }
    return 0;
}
