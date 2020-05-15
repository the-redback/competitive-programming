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

char s1[200];
char s2[200];

ll l1,l2;
ll cnt,total,init;

ll rec(ll pos,ll id)
{
    if(id==l2)
    {
        total++;
        if(pos==init)
            cnt++;
        return 0;
    }
    if(s2[id]=='+')
        return rec(pos+1,id+1);
    else if(s2[id]=='-')
        return rec(pos-1,id+1);
    else
    {
        rec(pos+1,id+1);
        rec(pos-1,id+1);
        return 0;
    }
}


int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    //cin>>tc;
    ll i,j,k,l,m,n;
    while(~scanf("%s",&s1))
    {
        scanf("%s",&s2);
        l1=strlen(s1);
        l2=strlen(s2);

        init=0;
        total=0;cnt=0;
        for(i=0;i<l1;i++)
        {
            if(s1[i]=='+')
                init++;
            else if(s1[i]=='-')
                init--;
        }
        rec(0,0);
        double sum=cnt/(double)total;
        printf("%0.12lf\n",sum);

    }
    return 0;
}
