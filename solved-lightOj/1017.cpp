/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : the_redback
 *    @link       : http://www.fb.com/maruf.2hin
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long LLU;

#define ft first
#define sd second
#define mp make_pair
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define mem(a,b) memset(a,b,sizeof(a))
#define meminf(a) memset(a,126,sizeof(a))
#define inf 1e11
#define eps 1e-9
#define mod 1000000007
#define NN 1010

//cout << setfill('0') << setw(3) << a << endl;
//cout << fixed << setprecision(20) << a << endl;

LL dp[111][111][111];
LL arr[111];
LL w,N;

LL rec(int prev,int pos,int cnt)
{
    if(pos==N+1)
        return 0;
    LL &tc=dp[prev][pos][cnt];

    if(tc!=-1)
        return tc;
    LL res=rec(prev,pos+1,cnt);
    if(arr[prev]+w>=arr[pos])
        res=max(res,rec(prev,pos+1,cnt)+1);
    else if(cnt-1>=0)
        res=max(res,rec(pos,pos+1,cnt-1)+1);
    return tc=res;
}

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    LL i,j,k,l,m,n,res,ret;
    cin>>tc;
    while(tc--)
    {
        cin>>N>>w>>k;
        arr[0]=-inf;
        for(i=1;i<=N;i++)
            cin>>m>>arr[i];
        sort(arr,arr+N);
        mem(dp,-1);
        LL ret=rec(0,1,k);
        cout<<"Case "<<t++<<": "<<ret<<"\n";
    }
    return 0;
}
