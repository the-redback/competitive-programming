#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[10],n=8,I=1,X,Y;

int check(int k,int y)
{
    if(y==Y)
        return 0;
    if(abs(X-k)==abs(Y-y))
        return 0;
    int i;
    for(i=1;i<k;i++)
    {
        if(a[i]==y)
            return 0;
        if(abs(a[i]-y)==abs(k-i))
            return 0;
    }
    return 1;

}

int call(int k)
{
    int i;
    if(k>=n+1)
    {
        printf("%2d     ",I);
        I++;
        for(i=1;i<=n;i++)
            printf(" %d",a[i]);
        printf("\n");
    }
    for(i=1;i<=n;i++)
    {
        if(i!=Y)
            if(check(k,i))
            {
                a[k]=i;
                if(X!=k+1)
                    call(k+1);
                else
                    call(k+2);
            }
    }
}


main()
{
    int i=0,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&Y,&X);
        a[X]=Y;
        I=1;
        if(i!=0)
            printf("\n");
        printf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n");
        if(X!=1)
            call(1);
        else
            call(2);
            i++;
    }
    return 0;
}
