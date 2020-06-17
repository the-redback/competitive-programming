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
map<string,int>mp;
string s;
string ss;
vector<string>v;
main()
{
    char a[50];
    int ret=0;
    int n,i;
    double k,r;
    int tc,t=1;
    scanf("%d",&tc);
    getchar();
    getchar();
    while(tc--)
    {
        i=0;
        while(gets(a))
        {
            if(strlen(a)==0)
                break;
            i++;
            s.assign(a);
            if(mp.find(s)==mp.end())
            {
                mp[s]=1;
                v.push_back(s);
            }
            else
                mp[s]++;
        }
        r=i;
        sort(v.begin(),v.end());
        if(t!=1)
            puts("");
        for(i=0;i<v.size();i++)
        {
            printf("%s ",v[i].c_str());
            k=mp[v[i]];
            double sum=(k/r)*100.0;
            printf("%.4lf\n",sum);
        }
        v.clear();
        mp.clear();
        t++;
    }
    return 0;
}
