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
int a[111][111];
int precalc(int n)
{
    int res,i,j,k,count;
    for(i=2;i<=n;i++)
    {
        res=i;
        for(j=2;j<=n;j++)
        {
            a[i][j]=a[i-1][j];
        }
        for(j=2;j*j<=res;j++)
        {
            if(res%j==0)
            {
                count=0;
                while(res%j==0)
                {
                    res/=j;
                    count++;
                }
                a[i][j]=a[i-1][j]+count;
            }
            if(res==1)
                break;
        }
        if(res>1)
            a[i][res]=a[i-1][res]+1;
    }
}

main()
{
    int tc,t=1;
    int i,j,k,l,x,n;
    precalc(100);
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        printf("Case %d: %d =",t++,n);
        x=0;
        for(i=2;i<=n;i++)
        {
            if(a[n][i]!=0)
            {
                if(x!=0)
                    printf(" *");
                printf(" %d (%d)",i,a[n][i]);
                x=1;
            }
        }
        printf("\n");
    }
    return 0;
}
