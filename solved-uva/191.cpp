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
    point pq,qq;
    cin>>tc;
    while(tc--)
    {
        cin>>x>>y>>xx>>yy;
        pq=point(x,y,xx,yy);
        cin>>x>>y>>xx>>yy;
        qq=point(x,y,xx,yy);
        v.pb(point(x,y,x,yy));
        v.pb(point(x,y,xx,y));
        v.pb(point(x,yy,xx,yy));
        v.pb(point(xx,y,xx,yy));
        int res=0;
        int fl=1;
        for(i=0;i<4 && fl;i++)
        {
                double one=CP(MV(P(v[i].x,v[i].y),P(v[i].xx,v[i].yy)),MV(P(v[i].x,v[i].y),P(pq.x,pq.y)));
                double two=CP(MV(P(v[i].x,v[i].y),P(v[i].xx,v[i].yy)),MV(P(v[i].x,v[i].y),P(pq.xx,pq.yy)));
                double three=CP(MV(P(pq.x,pq.y),P(pq.xx,pq.yy)),MV(P(pq.x,pq.y),P(v[i].x,v[i].y)));
                double four=CP(MV(P(pq.x,pq.y),P(pq.xx,pq.yy)),MV(P(pq.x,pq.y),P(v[i].xx,v[i].yy)));
                if((one*two)<0 && three*four<0)
                    fl=0;
                if(one==0)
                {
                    if(pq.x>=min(v[i].x,v[i].xx) && pq.x<=max(v[i].x,v[i].xx) && pq.y>=min(v[i].y,v[i].yy) && pq.y<=max(v[i].y,v[i].yy))
                       fl=0;
                }
                else if(two==0)
                {
                    if(pq.xx>=min(v[i].x,v[i].xx) && pq.xx<=max(v[i].x,v[i].xx) && pq.yy>=min(v[i].y,v[i].yy) && pq.yy<=max(v[i].y,v[i].yy))
                       fl=0;
                }
                else if(three==0)
                {
                    if(v[i].x>=min(pq.x,pq.xx) && v[i].x<=max(pq.x,pq.xx) && v[i].y>=min(pq.y,pq.yy) && v[i].y<=max(pq.y,pq.yy))
                       fl=0;
                }
                else if(four==0)
                {
                    if(v[i].xx>=min(pq.x,pq.xx) && v[i].xx<=max(pq.x,pq.xx) && v[i].yy>=min(pq.y,pq.yy) && v[i].yy<=max(pq.y,pq.yy))
                       fl=0;
                }
            }
            if(fl)
            {
                if(pq.xx>=min(qq.x,qq.xx) && pq.xx<=max(qq.x,qq.xx) && pq.yy>=min(qq.y,qq.yy) && pq.yy<=max(qq.y,qq.yy))
                    fl=0;
                if(pq.x>=min(qq.x,qq.xx) && pq.x<=max(qq.x,qq.xx) && pq.y>=min(qq.y,qq.yy) && pq.y<=max(qq.y,qq.yy))
                    fl=0;
            }
            if(fl)
                puts("F");
            else
                puts("T");
        v.clear();
    }
    return 0;
}
