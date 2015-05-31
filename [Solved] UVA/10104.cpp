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

int sii,si,tii,ti;
int egcd(int a,int b)
{
    int r,q,s,t;
    sii=1,si=0;
    tii=0,ti=1;
    while(b>0)
    {
        r=a%b;
        q=a/b;
        s=sii-(q*si);
        t=tii-(q*ti);
        sii=si,si=s;
        tii=ti,ti=t;
        a=b,b=r;
    }
    return a;
}

main()
{
    int tc,t=1;
    int i,j,k,l,x;
    //scanf("%d",&tc);
    while(~scanf("%d%d",&x,&k))
    {
        //printf("Case %d:\n",t++);
        l=egcd(x,k);
        printf("%d %d %d\n",sii,tii,l);
    }
    return 0;
}
