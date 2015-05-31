#include<stdio.h>
#include<math.h>

int main()
{
    int m,n,k,i,count;
    while(scanf("%d",&n)==1)
    {
        count=1;
        m=1;
        while(m%n!=0)
        {
            m=m*10+1;
            m=m%n;
            count++;
        }
        printf("%d\n",count);
    }
    return 0;
}
