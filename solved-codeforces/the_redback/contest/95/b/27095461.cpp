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
#define NN        1000000

#define read(a)   scanf("%lld",&a)

char c[NN];
int a[NN],b[NN];

main()
{
//    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    //cin>>tc;
    int i,j,k,l,m,n;
    while(~scanf("%s",&c))
    {
        i=0,j=0;
        int pos=0,neg=0;
        int fl=0;
        l=strlen(c);
        for(i=0; i<l; i++)
        {
            a[i]=c[i]-'0';
        }
        int fl4=0,fl7=0;
        int four=0,sev=0;

        if(l%2)
        {
            four=l+1;
            l++;
            sev=0;
            neg=1;
        }

        for(i=0; i<l && !neg; i++)
        {
            if(a[i]<=4 || pos)
            {
                b[i]=4;
                four++;
                if(a[i]<4)
                    pos=1;
            }
            else if(a[i]<=7)
            {
                b[i]=7;
                sev++;
                if(a[i]<7)
                    pos=1;
            }
            else
            {
                for(k=i; k>=0; k--)
                {
                    if(b[k]==4)
                    {
                        b[k]=7;
                        sev++;
                        four--;
                        pos=1;
                        break;
                    }
                }
                if(!pos)
                {
                    neg=1;
                    four=l+1;
                    l++;
                    sev=0;
                    break;
                }
                else
                    b[i]=4,four++;
            }
        }

        if(!neg)
        {
            if(sev<four)
            {
                for(i=l-1; i>=0 && sev<four; i--)
                {
                    if(b[i]==4)
                    {
                        b[i]=7;
                        sev++;
                        four--;
                    }
                }
                if((sev+four)%2  )
                {
                    four++;
                    neg=1;
                    l++;
                }
            }
            else if(four<sev)
            {
                ll flnew=0;

                ll cnt=0;
                for(i=l-1; i>=0 && four<sev; i--)
                {
                    if(b[i]==4 && four-1+cnt>=sev+1-cnt)
                    {
                        b[i]=7;
                        sev++;
                        four--;
                        flnew=1;
                        i++;
                        break;
                    }
                    else if(b[i]==7)
                    {
                        cnt++;
                    }
                }
                if(flnew==1)
                {
                    flnew=0;
                    for(; i<l && four<sev; i++)
                    {
                        if(b[i]==7)
                        {
                            b[i]=4;
                            sev--;
                            four++;

                        }
                    }
                }
                if((four<sev))
                {
                    neg=1;
                    four++;
                    l++;
                }
            }
        }
            if(neg==1)
            {
                if((four+sev)%2)
                    four++,l++;
                sev=(four+sev)/2.0;
                four=sev;
                for(i=0; i<l; i++)
                {
                    if(four>0)
                        b[i]=4,four--;
                    else
                        b[i]=7,sev--;
                }
            }

            for(i=0; i<l; i++)
                printf("%d",b[i]);
            puts("");
    }
    return 0;
}