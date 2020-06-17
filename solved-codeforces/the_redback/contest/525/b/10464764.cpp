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

char a[NN];
ll b[NN];
char ans[NN];

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
        mem(b,0);
        read(n);
        for(i=0;i<n;i++)
        {
            read(k);
            k--;

            b[k]++;
            b[k]=b[k]%2;
        }

        strcpy(ans,a);

        l=strlen(a);

        ll flag=0; //if 0, left, else right.

        for(i=0,j=l-1;i<=j;i++,j--)
        {
            if(b[i]==0) //no change
            {
                if(flag==1)
                {
                    swap(ans[i],ans[j]);
                }
            }
            else
            {
                if(flag==0)
                {
                    flag=1;
                }
                else
                    flag=0;

                if(flag==1)
                {
                    swap(ans[i],ans[j]);
                }
            }
        }
        puts(ans);

    }
    return 0;
}
