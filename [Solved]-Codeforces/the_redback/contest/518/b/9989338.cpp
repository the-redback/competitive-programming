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
#define NN        200010

#define read(a)   scanf("%lld",&a)

char a[NN],b[NN], ans[NN];
int an[300],bn[300];

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef redback
        freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
    #endif

    ll t=1,tc;
    //read(tc);
    ll i,j,k,l,m,n;
    while(~scanf("%s",&a))
    {
        scanf("%s",&b);

        mem(an,0);
        mem(bn,0);

        ll al=strlen(a);
        ll bl=strlen(b);

        for(i=0;i<al;i++)
        {
            an[a[i]]++;
        }
        for(i=0;i<bl;i++)
        {
            bn[b[i]]++;
        }

        ll yay=0,nay=0;

        for(i='A';i<='z';i++)
        {
                k=min(an[i],bn[i]);
                yay+=k;
                an[i]-=k;
                bn[i]-=k;
        }
        ll tmp;

        for(i='A';i<='z';i++)
        {
            if(an[i]>0)
            {
               if(islower(i))
                    tmp=i-'a'+'A';
               else
                    tmp=i-'A'+'a';

                k=min(an[i],bn[tmp]);
                nay+=k;
                an[i]-=k;
                bn[tmp]-=k;
            }
        }

        printf("%lld %lld\n",yay,nay);



    }
    return 0;
}

