/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @TOPCODER   : the_redback
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

#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pp pop_back
#define inf 10e9 //10^9
#define meminf 100
#define eps 10e-9
#define NN 1000000
struct P
{
    double x,y;
    P()
    {
        x=0,y=0;
    }
    P(double X,double Y)
    {
        x=X,y=Y;
    }
};

vector<P>v;

P MV(P a,P b)
{
    return P(b.x-a.x,b.y-a.y);
}

double DP(P a, P b)
{
    return a.x*b.x+a.y*b.y;
}

double CP(P a,P b)
{
    return a.x*b.y-a.y*b.x;
}

double A(P a)
{
    return sqrt(a.x*a.x+a.y*a.y);
}

P ADD(P a,P b)
{
    return P(a.x+b.x,a.y+b.y);
}

P LV(P a,double l)
{
    return P(a.x*l/A(a),a.y*l/A(a));
}

P pvt;

bool comp(P a,P b) //False hoile sort korbe
{
    long long c=CP(MV(pvt,a),MV(pvt,b));
    if(c)
        return c>0;
    return A(MV(pvt,a))<A(MV(pvt,b));
}

void checkPvt(void)
{
    pvt.x=inf;
    pvt.y=inf;
    for(int i=0; i<v.size(); i++)
    {
        if(pvt.x>v[i].x)
            pvt=v[i];
        else if(pvt.x==v[i].x && pvt.y>v[i].y)
            pvt=v[i];
    }
}

vector<P>q;

int go(void)
{
    q.clear();
    int i,j,k;
    q.pb(v[0]);
    q.pb(v[1]);
    q.pb(v[2]);

    for(i=3; i<v.size(); i++)
    {
        while(q.size()>=3)
        {
            int n=q.size();
            if(CP(MV(q[n-2],q[n-1]),MV(q[n-2],v[i]))<0)
                q.pp();
            else
            {
                break;
            }
        }
        q.pb(v[i]);
    }
    v=q;
    return 0;
}

double area(void)
{
    double sum=0;
    for(int i=0;i<v.size();i++)
    {
        int j=i+1;
        if(j==v.size())
            j=0;
        sum+=CP(v[i],v[j]);
    }
    return sum/2.0;
}



main()
{
    ios_base::sync_with_stdio(false);
    int t=1,tc;
    int i,j,k,l,m,n;
    //cin>>tc;
    while(cin>>n)
    {
        if(n==0)
            return 0;
        v.clear();
        for(i=0; i<n; i++)
        {
            cin>>k>>l;
            v.pb(P(k,l));
        }
        double area1=abs(area());
        checkPvt();
        sort(v.begin(),v.end(),comp);
        go();
        double area2=abs(area());
        double res=((area2-area1)/area2)*100.0;
        printf("Tile #%d\nWasted Space = %.2lf %%\n\n",t++,res);
    }
    return 0;
}
