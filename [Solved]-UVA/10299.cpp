
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
int phi(int n)
{
    int res=n;
    int i;
    for(i=2;i*i<=n;i++)
    {
        if(!(n%i))
            res-=res/i;
        while(!(n%i))
        {
            n/=i;
        }
        if(n==1)
            break;
    }
    if(n>1)
        res-=res/n;
    return res;
}

main()
{
    int tc,t=1;
    int i,j,k,l,x;
    //scanf("%d",&tc);
    while(~scanf("%d",&k))
    {
       // l=k;
        if(k==0)
            return 0;
        l=phi(k);
        if(k==1)
            l=0;
        printf("%d\n",l);
    }
    return 0;
}
