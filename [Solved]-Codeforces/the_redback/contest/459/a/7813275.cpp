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

typedef long long          ll;
typedef unsigned long long llu;

#define ft        first
#define sd        second
#define mp        make_pair
#define pb(x)     push_back(x)
#define all(x)    x.begin(),x.end()
#define allr(x)   x.rbegin(),x.rend()
#define mem(a,b)  memset(a,b,sizeof(a))
#define meminf(a) memset(a,126,sizeof(a))
#define inf       1e11
#define eps       1e-9
#define mod       1000000007
#define NN        30100

//cout << setfill('0') << setw(3) << a << endl;
//cout << fixed << setprecision(20) << a << endl;

main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    //cin>>tc;
    ll x1,x2,y1,y2;
    ll i,j,k,l,m,n;
    ll x3,x4,y3,y4;
    while(cin>>x1>>y1>>x2>>y2)
    {
        if(y1>y2 ||y1==y2 && x1>x2)
        {
            swap(x1,x2);
            swap(y1,y2);
        }

        if(abs(x1-x2)==abs(y1-y2))
        {

            x3=x2;
            y3=y1;
            x4=x1;
            y4=y2;

            cout<<x3<<" "<<y3<<" "<<x4<<" "<<y4<<"\n";
        }
        else if(x1==x2)
        {
            ll temp=abs(y1-y2);
            x3=x1+temp;
            y3=y1;
            x4=x3;
            y4=y2;
            cout<<x3<<" "<<y3<<" "<<x4<<" "<<y4<<"\n";
        }
        else if(y1==y2)
        {
            ll temp=abs(x1-x2);
            x3=x1;
            y3=y1+temp;
            x4=x2;
            y4=y3;
            cout<<x3<<" "<<y3<<" "<<x4<<" "<<y4<<"\n";
        }
        else
            cout<<"-1\n";

    }
    return 0;
}
