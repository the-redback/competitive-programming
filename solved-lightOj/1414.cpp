#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int t,tc;
    long long x,y,n;
    int m,i;
    char a[50];
    scanf("%d",&tc);
    for(t=1;t<=tc;t++)
    {
        x=0;
        scanf("%s %d, %lld",&a,&m,&n);
        if(strcmp(a,"January")==0 || strcmp(a,"February")==0 )
            x=n;
        else
            x=n+1;
        scanf("%s %d, %lld",&a,&m,&n);
        if(strcmp(a,"January")==0 || ( strcmp(a,"February")==0 && m!=29))
            y=n-1;
        else
            y=n;
        n=(y/4)-((x-1)/4);
        n-=(y/100)-((x-1)/100);
        n+=(y/400)-((x-1)/400);
        if(n<0)
            n=0;
        printf("Case %d: %lld\n",t,n);
    }
    return 0;
}
