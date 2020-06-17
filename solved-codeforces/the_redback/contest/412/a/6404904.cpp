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

#define ppb pop_back
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 1000000000
#define eps 1e-9
#define NN 400010

string s;

main()
{
    //ios_base::sync_with_stdio(false);
    int t,tc;
    int i,j,k,l,m,n;
    //cin>>tc;
    while(cin>>n>>k)
    {
        cin>>s;
        if(n-k<k)
        {
            for(i=0;i<n-k;i++)
                puts("RIGHT");
            for(i=s.size()-1;i>=0;i--)
            {
                printf("PRINT %c\n",s[i]);
                if(i!=0)
                    puts("LEFT");
            }
        }
        else
        {
            for(i=k;i>1;i--)
                puts("LEFT");
            for(i=0;i<s.size();i++)
            {
                printf("PRINT %c\n",s[i]);
                if(i!=s.size()-1)
                        puts("RIGHT");
            }
        }

    }
    return 0;
}
