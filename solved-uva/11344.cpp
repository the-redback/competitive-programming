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
char a[100100];
int mod(int d)
{
    int rem,i;
    rem=0;
    for(i=0;a[i];i++)
    {
        rem=rem*10+a[i]-48;
        rem=rem%d;
    }
    return rem;
}

main()
{
    int tc,t=1;
    int res,ret,i,j,k,n;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%s",&a);
        scanf("%d",&n);
        res=0;
        while(n--)
        {
            scanf("%d",&k);
            if(!res)
                res=mod(k);
        }
        if(res)
            printf("%s - Simple.\n",a);
        else
            printf("%s - Wonderful.\n",a);
    }
    return 0;
}

