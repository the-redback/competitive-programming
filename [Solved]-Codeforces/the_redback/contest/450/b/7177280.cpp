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

#define mp make_pair
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 1e9
#define eps 1e-9
#define NN 1050
#define mod 1000000007

int a[10];

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    //scanf("%d",&tc);
    int i,j,k,l,m,n,x,y;
    while(cin>>x>>y)
    {
        cin>>n;
        n=(n-1)%6;
        a[0]=x;
        a[1]=y;
        for(i=2;i<8;i++)
            a[i]=a[i-1]-a[i-2];
        k=((a[n]%mod)+mod)%mod;
        printf("%d\n",k);

    }

    return 0;
}
