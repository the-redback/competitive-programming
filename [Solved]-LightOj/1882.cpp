/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @Codeforces : the_redback
 *    @UVA        : Redback
 *    @link       : http://www.fb.com/maruf.2hin
 */
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
using namespace std;
#define inf HUGE_VAL
#define mem(a,b) memset(a,b,sizeof(a))
#define mod 1000
int big(int n,int k)
{
    if(k==1)
        return n%mod;
    if(k%2)
        return ((n%mod)*big(n,k-1))%mod;
    else
    {
        int pp=big(n,k/2);
        return (pp*pp)%mod;
    }
}

main()
{
    double m;
    char s[50];
    int n,k;
    int tc,t=1;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d%d",&n,&k);
        m=(double)k*(double)log10((double)n);
        m-=floor(m);
        m=pow(10.0,m);
        m=m*1000;
        sprintf(s,"%lf",m);
        n=big(n,k);
        printf("Case %d: %c%c%c %03d\n",t++,s[0],s[1],s[2],n);
    }
    return 0;
}
