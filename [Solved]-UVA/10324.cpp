#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
    char a[1000005];
    int b[1000005];
main()
{
    int i,j,k,n,t,l,T=1;
    while(gets(a))
    {
        l=strlen(a);
        b[0]=0;
        b[1]=a[0]-'0';
        for(i=1;i<l;i++)
        {
            b[i+1]=b[i]+a[i]-'0';
        }
        scanf("%d",&n);
        getchar();
        printf("Case %d:\n",T++);
        while(n--)
        {
            scanf("%d %d",&k,&t);
            getchar();
            i=min(k,t);
            j=max(k,t);
            if(b[j+1]-b[i]==0)
            {
                puts("Yes");
            }
            else
            {
                if((b[j+1]-b[i])==(j-i+1))
                {
                    puts("Yes");
                }
                else
                    puts("No");
            }
        }
    }
    return 0;
}
