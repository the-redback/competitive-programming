#include <string.h>
#include <stdio.h>

main()
{
    char c;
    char a[100];
    int n,i,j,k;
    scanf("%d %d",&n,&k);
    getchar();
    for(i=0;i<n;i++)
    {
        scanf("%c",&c);
        if(c=='B')
        a[i]='B';
        else
        a[i]='G';
    }
    while(k--)
    {
        for(i=0;i<n-1;i++)
        {
            if(a[i]=='B' && a[i+1]=='G')
            {
            a[i]='G';
            a[i+1]='B';
            i++;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%c",a[i]);
    }
    printf("\n");
    return 0;
}
