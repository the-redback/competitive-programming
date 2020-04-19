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
#define eps 10e-5
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
struct point
{
    double x,y,xx,yy;
    point()
    {
        x=0,y=0,xx=0,yy=0;
    }
    point(double X,double Y,double XX,double YY)
    {
        x=X,y=Y,xx=XX,yy=YY;
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

P pvt(0,0);

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

main()
{
    ios_base::sync_with_stdio(false);
    int t=1,tc;
    int i,j,k,l,m,n;
    double x,y,xx,yy,z;
    vector<point>v;
    int a[1010];
    cin>>tc;
    while(tc--)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>x>>y>>xx>>yy;
            v.pb(point(x,y,xx,yy));
        }
        int res=0;
        mem(a,0);
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                double one=CP(MV(P(v[i].x,v[i].y),P(v[i].xx,v[i].yy)),MV(P(v[i].x,v[i].y),P(v[j].x,v[j].y)));
                double two=CP(MV(P(v[i].x,v[i].y),P(v[i].xx,v[i].yy)),MV(P(v[i].x,v[i].y),P(v[j].xx,v[j].yy)));
                double three=CP(MV(P(v[j].x,v[j].y),P(v[j].xx,v[j].yy)),MV(P(v[j].x,v[j].y),P(v[i].x,v[i].y)));
                double four=CP(MV(P(v[j].x,v[j].y),P(v[j].xx,v[j].yy)),MV(P(v[j].x,v[j].y),P(v[i].xx,v[i].yy)));
                if((one*two)<0 && three*four<0)
                    a[i]=1,a[j]=1;
                if(one==0)
                {
                    if(v[j].x>=min(v[i].x,v[i].xx) && v[j].x<=max(v[i].x,v[i].xx) && v[j].y>=min(v[i].y,v[i].yy) && v[j].y<=max(v[i].y,v[i].yy))
                       a[i]=1,a[j]=1;
                }
                if(two==0)
                {
                    if(v[j].xx>=min(v[i].x,v[i].xx) && v[j].xx<=max(v[i].x,v[i].xx) && v[j].yy>=min(v[i].y,v[i].yy) && v[j].yy<=max(v[i].y,v[i].yy))
                       a[i]=1,a[j]=1;
                }
                if(three==0)
                {
                    if(v[i].x>=min(v[j].x,v[j].xx) && v[i].x<=max(v[j].x,v[j].xx) && v[i].y>=min(v[j].y,v[j].yy) && v[i].y<=max(v[j].y,v[j].yy))
                       a[i]=1,a[j]=1;
                }
                if(four==0)
                {
                    if(v[i].xx>=min(v[j].x,v[j].xx) && v[i].xx<=max(v[j].x,v[j].xx) && v[i].yy>=min(v[j].y,v[j].yy) && v[i].yy<=max(v[j].y,v[j].yy))
                       a[i]=1,a[j]=1;
                }
            }
            if(a[i]==0)
                res++;
        }
        v.clear();
        cout<<res<<"\n";
    }
    return 0;
}
