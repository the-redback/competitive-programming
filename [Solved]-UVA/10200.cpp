#include <bits/stdc++.h>
using namespace std;

bool prime(long n)
{
    long i;
    if (n==2)
        return 0;
    else if(n%2==0)
        return 1;
    for(i=3;i*i<=n;i++)
        if(n%i==0)
            return 1;

    return 0;
}


main()
{
    long long k,i;
    int b,c;
    double avg;
    int a[10002];
    a[0]=0;
    a[1]=1;
    for(i=1;i<=10000;i++)
    {
        k=(i*i)+i+41;
        if(!prime(k))
            a[i+1]=a[i]+1;
        else
            a[i+1]=a[i];
    }
    while(scanf("%d %d",&b,&c)==2)
    {
        k=a[c+1]-a[b];
        i=c-b+1;
        avg=((k/(double)i)*100.0)+.0000000001;
        printf("%.2lf\n",avg);
    }
    return 0;
}
