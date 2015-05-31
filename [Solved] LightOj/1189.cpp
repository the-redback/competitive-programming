/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : the_redback
 *    @link       : http://www.fb.com/maruf.2hin
 */

#include <bits/stdc++.h>
using namespace std;

//==================[ START ]=====================

typedef unsigned __int64 LLU;
typedef __int64 LL;

#define ft first
#define sd second
#define mp make_pair
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define mem(a,b) memset(a,b,sizeof(a))
#define meminf(a) memset(a,126,sizeof(a))

#define space printf(" ")
#define newline puts("");

#define inf 1e9
#define eps 1e-9
#define pi acos(-1)
#define mod 1000000007
#define NN 1010
//==================[ END ]=====================

int flag[22];
LLU a[22];
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    cin>>tc;
    LLU i,k,l,n,m;
    int j;
    a[0]=1;
    for(i=1;i<=19;i++)
        a[i]=a[i-1]*i;
    while(tc--)
    {
        cin>>n;
        mem(flag,0);
        LLU res=0;
        res=n;
        for(j=19;j>=0;j--)
        {
            if(a[j]<=res)
            {
                res-=a[j];
                flag[j]=1;
            }
        }

        printf("Case %d: ",t++);

        if(res>0)
            printf("impossible\n");
        else
        {
            for(i=0,j=0;i<=19;i++)
                if(flag[i])
                {
                    if(j!=0)
                        printf("+");
                    printf("%d!",i);
                    j++;
                }
            printf("\n");
        }
    }
    return 0;
}
