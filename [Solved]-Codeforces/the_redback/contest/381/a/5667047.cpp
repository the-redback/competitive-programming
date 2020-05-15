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
#define mod 1000000007


main()
{
    vector<int>v;
    int n,k,l,r,i,s;
    int tc,t=1;
    while(~scanf("%d",&n))
    {
        while(n--)
        {
            scanf("%d",&k);
            v.push_back(k);
        }
        r=0;
        s=0;
        int flag=0;
        while(v.size()!=0)
        {
            if(v[0]>v[v.size()-1])
            {
                if(flag==0)
                {
                    s+=v[0];
                    flag=1;
                }
                else
                {
                    r+=v[0];
                    flag=0;
                }
                v.erase(v.begin());
            }
            else
            {
                if(flag==0)
                {
                    s+=v[v.size()-1];
                    flag=1;
                }
                else
                {
                    r+=v[v.size()-1];
                    flag=0;
                }
                v.erase(v.begin()+v.size()-1);
            }
        }
        printf("%d %d\n",s,r);
    }
    return 0;
}
