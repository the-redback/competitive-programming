#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

main()
{
    int k,y,m,n,t=1,j,i,tc;
    long long sum,carry;
    int a[2000];
    while(~scanf("%d",&n))
    {
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        int mx=-1000009;
        int mn=1000009;
        int mx1=-1000009;
        int mn1=1000009;
        for (i=0;i<n-1;i++)
        {
            for (j=i+1;j<n-1;j++)
            {
                mn=min(a[i],a[i+1]);
                mx=max(a[i],a[i+1]);
                mn1=min(a[j],a[j+1]);
                mx1=max(a[j],a[j+1]);
                if (mn < mn1 && mn1 < mx && mx < mx1 || mn1 <mn && mn < mx1 && mx1 < mx)
                {
                    printf("yes\n");
                    return 0;
                }
            }
        }
        printf("no\n");
    }
    return 0;
}
