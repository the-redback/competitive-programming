/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @TOPCODER   : the_redback
 *    @CodeForces : maruf.2hin
 *    @UVA        : Redback
 *    @link       : http://www.fb.com/maruf.2hin
 *
 */
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

#define inf HUGE_VAL


main()
{
    char a[1000010];
    long long n,m,k;
    int i,j,l,x;
    while(gets(a))
    {
        k=0;
        n=0;
        m=0;
        l=strlen(a);
        for(i=0;i<l;i++)
        {
            if(a[i]=='^')
            {
                x=i;
                break;
            }
        }
        for(i=x-1,j=1;i>=0;i--,j++)
        {
            if(a[i]>='0'&& a[i]<='9')
            {
                n+=(a[i]-'0')*j;
            }
        }
        for(i=x+1,j=1;i<l;i++,j++)
        {
            if(a[i]>='0'&& a[i]<='9')
            {
                m+=(a[i]-'0')*j;
            }
        }
        if(n==m)
            puts("balance");
        else if(n>m)
            puts("left");
        else
            puts("right");
    }
    return 0;
}
















