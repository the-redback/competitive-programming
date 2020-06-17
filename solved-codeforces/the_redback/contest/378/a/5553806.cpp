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

int main()
{
    int tc,t=1;
    int i,j,k,n,w,d,l;
    while(~scanf("%d%d",&n,&k))
    {
        w=0;
        l=0;
        d=0;
        for(int x=1;x<7;x++)
        {
            if(abs(x-n)<abs(x-k))
                w++;
            else if(abs(x-n)>abs(x-k))
                l++;
            else if(abs(x-n)==abs(x-k))
                d++;
        }

        printf("%d %d %d\n",w,d,l);
    }
    return 0;
}
