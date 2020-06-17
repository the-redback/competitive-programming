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

ll aa[10];

ll check(ll a,ll b,ll c,ll d)
{
    if(a<0 || b<0 || c<0 || d<0 || a>NN ||b>NN || c>NN || d>NN )
        return 0;
    ll mean=(a+b+c+d);
    if(mean%4!=0)return 0;
    mean/=4;

    ll mid=(b+c);
    if(mid%2!=0)
        return 0;
    mid/=2;
    ll range=d-a;

    if(mean==mid && mid==range)
        return 1;
    return 0;

}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll mid,ran;
    ll t=1,tc;
    ll a,b,c,d,low,high;
    //cin>>tc;
    ll i,j,k,l,m,n;
    while(cin>>n)
    {
        if(n==0)
        {
            cout<<"YES\n";
            cout<<"1\n1\n3\n3\n";
        }
        else if(n==1)
        {
            cin>>a;
            for(d=a; d<=NN; d++)
            {
                ran=d-a;
                mid=(d+a)/2.0;
                if(mid==ran)
                {
                    c=d;
                    b=a;
                    if(check(a,b,c,d))
                    {
                        cout<<"YES\n";
                        cout<<b<<"\n"<<c<<"\n"<<d<<"\n";
                        return 0;
                    }
                }
            }
            cout<<"NO\n";
        }
        else if(n==2)
        {
            cin>>low>>high;
            if(high<low)
                swap(high,low);
            a=low,b=high;

            for(c=b; c<=NN; c++)
            {
                mid=(b+c)/2.0;
                d=a+mid;
                if(check(a,b,c,d))
                {
                    cout<<"YES\n";
                    cout<<c<<"\n"<<d<<"\n";
                    return 0;
                }
            }
            a=low;
            c=high;
            for(b=a; b<=c; b++)
            {
                mid=(b+c)/2.0;
                d=a+mid;
                if(check(a,b,c,d))
                {
                    cout<<"YES\n";
                    cout<<b<<"\n"<<d<<"\n";
                    return 0;
                }
            }
            a=low;
            d=high;
            ran=d-a;
            mid=(d+a)/2.0;
            if(mid==ran)
            {
                c=d;
                b=a;
                if(check(a,b,c,d))
                {
                    cout<<"YES\n";
                    cout<<b<<"\n"<<c<<"\n";
                    return 0;
                }
            }
            b=low;
            c=high;
            mid=(b+c)/2.0;
            for(a=1; a<=b; a++)
            {

                d=a+mid;
                if(check(a,b,c,d))
                {
                    cout<<"YES\n";
                    cout<<a<<"\n"<<d<<"\n";
                    return 0;
                }
            }
            b=low;
            d=high;
            for(c=b; c<=d; c++)
            {
                mid=(b+c)/2.0;
                a=d-mid;
                if(check(a,b,c,d))
                {
                    cout<<"YES\n";
                    cout<<a<<"\n"<<c<<"\n";
                    return 0;
                }

            }
            c=low;
            d=high;
            for(b=1; b<=c; b++)
            {
                mid=(b+c)/2.0;
                a=d-mid;
                if(check(a,b,c,d))
                {
                    cout<<"YES\n";
                    cout<<a<<"\n"<<b<<"\n";
                    return 0;
                }
            }

            cout<<"NO\n";
        }
        else if(n==3)
        {
            cin>>aa[0]>>aa[1]>>aa[2];
            sort(aa,aa+3);
            a=aa[0];
            b=aa[1];
            c=aa[2];
            for(d=c; d<=NN; d++)
            {
                if(check(a,b,c,d))
                {
                    cout<<"YES\n";
                    cout<<d<<"\n";
                    return 0;
                }
            }

            b=aa[0];
            c=aa[1];
            d=aa[2];
            for(a=1; a<=b; a++)
            {
                if(check(a,b,c,d))
                {
                    cout<<"YES\n";
                    cout<<a<<"\n";
                    return 0;
                }
            }

            a=aa[0];
            c=aa[1];
            d=aa[2];
            for(b=a; b<=c; b++)
            {
                if(check(a,b,c,d))
                {
                    cout<<"YES\n";
                    cout<<b<<"\n";
                    return 0;
                }

            }
            a=aa[0];
            b=aa[1];
            d=aa[2];
            for(c=b; c<=d; c++)
            {
                if(check(a,b,c,d))
                {
                    cout<<"YES\n";
                    cout<<c<<"\n";
                    return 0;
                }

            }



            cout<<"NO\n";
        }
        else
        {
            cin>>aa[0]>>aa[1]>>aa[2]>>aa[3];
            sort(aa,aa+4);
            a=aa[0];
            b=aa[1];
            c=aa[2];
            d=aa[3];
            if(check(a,b,c,d))
            {
                cout<<"YES\n";
                return 0;
            }
            cout<<"NO\n";

        }
        return 0;


    }
    return 0;
}

