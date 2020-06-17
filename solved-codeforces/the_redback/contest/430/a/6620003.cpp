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
#define inf 1e9
#define eps 1e-9
#define NN 400010

struct D
{
    int x,y;
    D(int X,int Y)
    {
        x=X,y=Y;
    }
    D()
    {

    }
};

bool comp(D x,D y)
{
    return x.x<y.x;
}

D arr[111];
int pos[111];

main()
{
    ios_base::sync_with_stdio(false);
    int t,tc;
    //cin>>tc;
    int i,j,k,l,m,n;
    while(cin>>n>>m)
    {
        for(i=0;i<n;i++)
            cin>>k,arr[i]=D(k,i);
        for(i=0;i<m;i++)
            cin>>k>>j;
        sort(arr,arr+n,comp);
        for(i=0;i<n;i++)
        {
            pos[arr[i].y]=i%2;
        }
        for(i=0;i<n;i++)
        {
            cout<<pos[i]<<" ";
        }
    }
    return 0;
}
