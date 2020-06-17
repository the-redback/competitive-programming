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

main()
{
    map<string,string>mp;
    char s[100010],ss[100010];
    char a[100010];
    int tc,t=1,i,j,k,l;
    while(gets(a))
    {
        l=strlen(a);
        if(l==0)
            break;
        i=0,k=0;
        for(i=0;i<l;i++)
        {
            if(a[i]==' ')
                break;
            s[k++]=a[i];
        }
        s[k]=0;
        k=0;
        i++;
        for(;i<l;i++)
        {
            ss[k++]=a[i];
        }
        ss[k]=0;
        mp[ss]=s;
    }
    while(gets(s))
    {
        if(mp.find(s)==mp.end())
            printf("eh\n");
        else
            printf("%s\n",mp[s].c_str());
    }
    return 0;
}

