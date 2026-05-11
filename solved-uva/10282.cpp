/**
 *                                   ____
 *       ____ ___  ____ ________  __/ __/
 *      / __ `__ \/ __ `/ ___/ / / / /_
 *     / / / / / / /_/ / /  / /_/ / __/
 *    /_/ /_/ /_/\__,_/_/   \__,_/_/
 *
 *    @link : https://the-redback.com
 */
#include <bits/stdc++.h>
using namespace std;
#define inf HUGE_VAL
#define mem(a,b) memset(a,b,sizeof(a))

main()
{
    map<string,string>mp;
    string s,ss;
    char a[100010];
    int tc,t=1,i,j,k,l;
    while(gets(a))
    {
        l=strlen(a);
        if(l==0)
            break;
        i=0,k=0;
        s="";
        ss="";
        for(i=0;i<l;i++)
        {
            if(a[i]==' ')
                break;
            s.push_back(a[i]);
        }
        i++;
        for(;i<l;i++)
        {
            ss.push_back(a[i]);
        }
        mp[ss]=s;
    }
    while(gets(a))
    {
        s.assign(a);
        if(mp.find(s)==mp.end())
            printf("eh\n");
        else
            printf("%s\n",mp[s].c_str());
    }
    return 0;
}

