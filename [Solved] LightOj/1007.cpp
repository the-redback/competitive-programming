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

#define NN 5000001
unsigned long long a[NN+7];
void sieve(void)
{
    int i,j,k,n=2237;
    for(i=2;i<NN;i++)
        a[i]=i;
    for(i=2;i<NN;i+=2)
    {
        a[i]*=(2-1);
        a[i]/=2;
    }
    for(i=3;i<NN;i+=2)
        if(a[i]==i)
        {
            for(j=i;j<NN;j+=i)
            {
                a[j]*=(i-1);
                a[j]/=i;
            }
        }
}

main()
{
    sieve();
    int tc,t=1;
    int i,j,k,l,x;
    for(i=2;i<NN;i++)
    {
        a[i]*=a[i];
        a[i]+=a[i-1];
    }
    printf("%llu");
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d%d",&k,&l);
        printf("Case %d: %llu\n",t++,a[l]-a[k-1]);
    }
    return 0;
}
