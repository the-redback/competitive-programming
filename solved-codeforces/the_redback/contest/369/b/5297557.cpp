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
    int n,k,l,r,sall,sk;
   // int a[2000];
    while(~scanf("%d%d%d%d%d%d",&n,&k,&l,&r,&sall,&sk))
    {
        vector<int>v(n,l);
        int i,j,m,sum;
        sum=sk-(l*k);
        for(i=k-1;i>=0;i--)
        {
            j=sum/(i+1);
            v[i]+=j;
            sum-=j;
        }
        sum=sall-sk-(l*(n-k));
        for(i=n-1;i>=k;i--)
        {
            j=sum/(i+1-k);
            v[i]+=j;
            sum-=j;
        }
        for(i=0;i<n;i++)
        {
            if(i!=0)
                printf(" ");
            printf("%d",v[i]);
        }
        printf("\n");
    }
    return 0;
}
