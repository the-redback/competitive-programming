
#include <string.h>
#include <stdio.h>

main()
{
    char a[100];
    int n,i,j,k;
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
    {
        scanf("%c",&a[i]);
    }
    j=0;
    for(i=0;i<n-1;i++)
    {
        if(a[i]==a[i+1])
        j++;
    }
    printf("%d\n",j);
    return 0;
}
