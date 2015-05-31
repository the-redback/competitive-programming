#include <stdio.h>
#include <string.h>

main()
{
    int t,a,n;
    long long sum=0;
    char ch[10];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",ch);
        if(strcmp(ch,"donate")==0)
           {
               scanf("%d",&n);
               sum=sum+n;
           }
        else if(strcmp(ch,"report")==0)
        {
            printf("%lld\n",sum);
        }
    }
    return 0;
}
