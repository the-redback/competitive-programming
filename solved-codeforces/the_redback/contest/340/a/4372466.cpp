#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))

long gcd(long a, long b)
{
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

long lcm(long a, long b)
{
    long temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

main()
{
    long x,y,a,b;
    scanf("%ld %ld %ld %ld",&x,&y,&a,&b);
    long sm=lcm(x,y);
    long sum=0;
    sum=(b/sm);
    sum-=ceil((double)a/sm);
    sum++;
    printf("%ld\n",sum);
}
