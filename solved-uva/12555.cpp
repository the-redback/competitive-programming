#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x));
main()
{
    char a[10];
    int i,j=0,flag,k,m,l,n,t;
    double sum;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        flag=0;
        j++;
        gets(a);
        l=strlen(a);
        l--;
        n=0;m=0;
        i=0;
        while(a[i]!=0)
        {
            if(a[i]>='0' && a[i]<='9')
            {
                if(flag==0)
                {
                    m=m*10+a[i]-'0';
                }
                else
                {
                    n=n*10+a[i]-'0';
                }
            }
            else
                flag=1;
            i++;
        }
        sum=0.5*(double)m+0.05*(double)n;
        printf("Case %d: %g\n",j,sum);
    }
    return 0;
}
