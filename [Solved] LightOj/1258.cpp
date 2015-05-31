/**
 *    @author     : Maruf Tuhin
 *    @College    : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : the_redback
 *    @link       : http://www.fb.com/maruf.2hin
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long llu;

#define ft        first
#define sd        second
#define mp        make_pair
#define pb(x)     push_back(x)
#define all(x)    x.begin(),x.end()
#define allr(x)   x.rbegin(),x.rend()
#define mem(a,b)  memset(a,b,sizeof(a))
#define inf       1e9
#define eps       1e-9
#define mod       1000000007
#define NN        1000010

#define read(a)   scanf("%lld",&a)

ll fail[NN];
char s[NN];
char p[NN];

void failure(void)
{
    ll i,m;
    m=strlen(p);

    fail[0]=0;
    ll q=0;

    for(i=1;i<m;i++)
    {
        while(q>0 && p[i]!=p[q])
            q=fail[q-1];
        if(p[i]==p[q])
            q++;
        fail[i]=q;
    }
    return;
}

ll KMP(void)
{
    ll i,j,k,l,m,n;
    failure();
    m=strlen(p);
    n=strlen(s);

    ll q=0;

    for(i=0;i<n;i++)
    {
        while(q>0 && p[q]!=s[i])
            q=fail[q-1];
        if(p[q]==s[i])
            q++;
    }
    return q;
}



main()
{
    #ifdef redback
        freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    #endif

    ll t=1,tc;
    read(tc);
    ll i,j,k,l,m,n;
    while(tc--)
    {
        scanf("%s",&s);
        strcpy(p,s);
        n= strlen(p);
        reverse(p,p+n);
        ll ans=n;
        ans+=n-KMP();
        printf("Case %lld: %lld\n",t++,ans);

    }
    return 0;
}

