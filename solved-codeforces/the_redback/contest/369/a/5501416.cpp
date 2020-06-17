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
    int n,d,p;
    while(~scanf("%d%d%d",&n,&d,&p))
    {
        int i,j,k,l;
        int ret=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&k);
            if(k==1)
            {
                if(d>0)
                    d--;
                else
                    ret++;
            }
            else if(k==2)
            {
                if(p>0)
                    p--;
                else if(d>0)
                    d--;
                else
                    ret++;
            }
        }
        printf("%d\n",ret);
    }

}
















