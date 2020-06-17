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
#define MM 1001

main()
{
    int n,k,i,m,c;
    int tc,t=1;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&n,&c);
        if(c%n!=0)
            printf("NO SOLUTION\n");
        else
        {
            k=c/n;
            for(i=k;i<=c;i+=k)
                if((i/__gcd(i,n))*n==c)
                    break;
            printf("%d\n",i);
        }
    }
    return 0;
}

