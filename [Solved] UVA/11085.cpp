#include <stdio.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <ctype.h>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x));
int a[15];
int b[15];
int SUM;
bool check(int x,int y)
{
    int i;
    for(i=1;i<x;i++)
    {
        if(a[i]==y)
            return false;
        if(abs(a[i]-y)==abs(x-i))
            return false;
    }
    return true;
}

void call(int k)
{
    int i;
    if(k==9)
    {
        int sum=0;
        for(i=1;i<=8;i++)
            if(a[i]!=b[i])
                sum++;
        if(sum<SUM)
            SUM=sum;
        return;
    }
    for(i=1;i<=8;i++)
    {
        if(check(k,i))
        {
            a[k]=i;
            call(k+1);
        }
    }
    return;
}

main()
{
    int t=1,i;
    while(scanf("%d",&b[1])==1)
    {
        for(i=2;i<=8;i++)
            scanf("%d",&b[i]);
        SUM=10;
        call(1);
        printf("Case %d: %d\n",t++,SUM);
    }
    return 0;
}
