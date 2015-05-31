#include <stdio.h>
#include <algorithm>
using namespace std;

struct test
{
    char nam[50];
    int sum;
};

bool comp(test a, test b)
{
    return b.sum>a.sum;
}

main()
{
    test a[102];
    int i,j,k,t,n,b,c,d;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%s %d %d %d",&a[j].nam,&b,&c,&d);
            a[j].sum=b*c*d;
        }
        sort(a,a+n,comp);
        if(a[n-1].sum!=a[0].sum)
        {
            printf("Case %d: %s took chocolate from %s\n",i,a[n-1].nam,a[0].nam);
        }
        else
        {
            printf("Case %d: no thief\n",i);
        }
    }
    return 0;
}
