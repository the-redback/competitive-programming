/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : the_redback
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

#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pp pop_back
#define inf 10000000
#define NN 20
char a[NN];
vector<int>v;

main()
{
    int t,tc;
    int i,j,k,l;
    int res,u,w,p,n;
    cin>>tc;
    while(tc--)
    {
        scanf("%s",&a);
        res=0;
        int flag=0,fl=0;
        for(i=1; i<=12; i++)
        {
            flag=1;
            fl=1;
            k=12/i;
            if(i*k==12)
            {
                fl=1;
                for(u=0; u<i && fl; u++)
                {
                    flag=1;
                    for(j=u; j<12 && flag; j+=i)
                    {
                        if(a[j]!='X')
                        {
                            flag=0;
                            break;
                        }
                    }
                    if(flag)
                        fl=0;
                }
                if(fl==0)
                    v.push_back(i);
            }

        }
        printf("%d",v.size());
        for(i=v.size()-1; i>=0; i--)
        {
            k=12/v[i];
            printf(" %dx%d",k,v[i]);
        }
        printf("\n");
        v.clear();
    }
    return 0;
}
