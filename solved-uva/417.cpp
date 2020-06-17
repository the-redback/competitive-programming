/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @Codeforces : the_redback
 *    @UVA        : Redback
 *    @link       : http://www.fb.com/maruf.2hin
 */
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
#define nn 26
map<string,int>mp;
string s="";
void go(void)
{
    int i,j,k,p,q,r=1;
    for(i=0; i<nn; i++)
    {
        s="";
        s.push_back(i+'a');
        mp[s]=r++;
    }

    for(i=0; i<nn-1; i++)
        for(j=i+1; j<nn; j++)
        {
            s="";
            s.push_back(i+'a');
            s.push_back(j+'a');
            mp[s]=r++;
        }
    for(i=0; i<nn-2; i++)
        for(j=i+1; j<nn-1; j++)
            for(k=j+1; k<nn; k++)
            {
                s="";
                s.push_back(i+'a');
                s.push_back(j+'a');
                s.push_back(k+'a');
                mp[s]=r++;
            }
    for(i=0; i<nn-3; i++)
        for(j=i+1; j<nn-2; j++)
            for(k=j+1; k<nn-1; k++)
                for(p=k+1; p<nn; p++)
                {
                    s="";
                    s.push_back(i+'a');
                    s.push_back(j+'a');
                    s.push_back(k+'a');
                    s.push_back(p+'a');
                    mp[s]=r++;
                }
    for(i=0; i<nn-4; i++)
        for(j=i+1; j<nn-3; j++)
            for(k=j+1; k<nn-2; k++)
                for(p=k+1; p<nn-1; p++)
                    for(q=p+1; q<nn; q++)
                    {
                        s="";
                        s.push_back(i+'a');
                        s.push_back(j+'a');
                        s.push_back(k+'a');
                        s.push_back(p+'a');
                        s.push_back(q+'a');
                        mp[s]=r++;
                    }
}


main()
{
    go();
    char a[15];
    int ret=0;
    int n,i,k,r;
    int tc,t=1;
    while(gets(a))
    {
        s.assign(a);
        if(mp.find(s)==mp.end())
            printf("0\n");
        else
            printf("%d\n",mp[s]);
        }
    return 0;
}
