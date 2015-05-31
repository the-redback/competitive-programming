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


int go(int n,int r)
{
    int sum=0,i=1;
    while(1)
    {
        long long k=pow(r,i);
        if(k>n)
            break;
        sum+=n/k;
        i++;
    }
    return sum;
}

int pq(int n,int r)
{
    int count=0;
    while(n%r==0)
    {
        count++;
        n/=r;
    }
    return count;
}

main()
{
    int n,k,l;
    int a,b,c,d;
    int tc,t=1;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        k=go(a,2);
        l=go(a,5);
        k+=pq(c,2)*d;
        l+=pq(c,5)*d;
        k-=go(b,2);
        l-=go(b,5);
        k-=go(a-b,2);
        l-=go(a-b,5);
        k=min(k,l);
        if(k<0)
            k=0;
        printf("Case %d: %d\n",t++,k);
    }
    return 0;
}
