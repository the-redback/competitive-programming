#include <stdio.h>
long long dp[10001];
int a, b, c, d, e, f;
long long fn( int n )
{
    if(dp[n]!=-1)
    return dp[n];
    if( n == 0 )
        dp[n]=a% 10000007;
    else if( n == 1 )
        dp[n]=b% 10000007;
    else if( n == 2 )
        dp[n]=c% 10000007;
    else if( n == 3 )
        dp[n]=d% 10000007;
    else if( n == 4 )
        dp[n]=e% 10000007;
    else if( n == 5 )
        dp[n]= f% 10000007;
    else
    dp[n]=( (fn(n-1)% 10000007) + (fn(n-2)% 10000007) + (fn(n-3)% 10000007) +( fn(n-4)% 10000007) +( fn(n-5)% 10000007 )+ (fn(n-6)% 10000007) );
    return dp[n];
}
int main() {
    int n,i, caseno = 0, cases;
    long long m;
    scanf("%d", &cases);
    while( cases-- )
    {
        for(i=0;i<=10000;i++)
        dp[i]=-1;
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        m=fn(n)% 10000007 ;
        printf("Case %d: %lld\n", ++caseno, m);
    }
    return 0;
}
