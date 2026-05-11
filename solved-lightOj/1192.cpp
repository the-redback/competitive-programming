/**
 *                                   ____
 *       ____ ___  ____ ________  __/ __/
 *      / __ `__ \/ __ `/ ___/ / / / /_
 *     / / / / / / /_/ / /  / /_/ / __/
 *    /_/ /_/ /_/\__,_/_/   \__,_/_/
 *
 *    @link : https://the-redback.com
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

#define mp make_pair
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 1e9
#define eps 1e-9
#define NN 1050

main()
{
    ios_base::sync_with_stdio(false);
    int t=1,tc;
    int k,l,n;
    cin>>tc;
    while(tc--)
    {
        cin>>n;
        int res=0;
        while(n--)
        {
            cin>>k>>l;
            k=l-k-1;
            res^=k;
        }
        if(res)
            printf("Case %d: Alice\n",t++);
        else
            printf("Case %d: Bob\n",t++);
    }
    return 0;
}
