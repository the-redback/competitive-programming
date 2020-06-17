#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
main()
{
    int n,m,x,y,i,j,k,l;
    char a[100005];
    int b[100005];
    gets(a);
    l=strlen(a);
    b[0]=0;
    for(i=0;i<l-1;i++)
    {
        if(a[i]==a[i+1])
            b[i+1]=b[i]+1;
        else
            b[i+1]=b[i];
    }
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %d",&j,&k);
        m=0;
        printf("%d\n",b[k-1]-b[j-1]);
    }
    return 0;
}
