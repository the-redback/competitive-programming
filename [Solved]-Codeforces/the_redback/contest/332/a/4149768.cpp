#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
main()
{
    char a[2010];
    int sum,i,j,k,l,m,n;
    scanf("%d",&n);
    getchar();
    gets(a);
    l=strlen(a);
    sum=0;
    for(i=n;i<l;i+=n)
    {
        for(j=i-2;j<i;j++)
        {
            if(a[j-1]!=a[j])
                break;
        }
        if(i==j)
            sum++;
    }
    printf("%d\n",sum);
    return 0;
}
