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
#define NN        30100

#define read(a)   scanf("%lld",&a)

char a[400];
char b[400];

main()
{
//    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    //cin>>tc;
    ll i,j,k,l,m,n;
    while(~scanf("%s",&a))
    {
        i=0,j=0;
        ll fl=0;

        for(i=0;i<strlen(a);i++)
        {
            if(a[i]=='d' && i!=0 && i+3<strlen(a))
            {
                if(a[i+1]=='o' && a[i+2]=='t')
                {
                    b[j++]='.';
                    i++;
                    i++;
                }
                else
                {
                    b[j++]=a[i];
                }
            }
            else if(a[i]=='a' && i!=0 && i+2<strlen(a) && fl!=1  )
            {
                //fl=1;
                if(a[i+1]=='t')
                {
                    b[j++]='@';
                    i++;
                    fl=1;
                }
                else
                {
                    b[j++]=a[i];
                }
            }
            else
                b[j++]=a[i];
        }
        b[j]=0;
        puts(b);
    }
    return 0;
}
