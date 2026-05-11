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
    char a[100];
    char b[100];
    int tc,t=1;
    scanf("%d",&tc);
    getchar();
    while(tc--)
    {
        gets(a);
        gets(b);
        s.assign(a);
        ss.assign(b);
        mp[s]=ss;
    }
    scanf("%d",&tc);
    getchar();
    while(tc--)
    {
        gets(a);
        s.assign(a);
        printf("%s\n",mp[s].c_str());
    }
    return 0;
}
