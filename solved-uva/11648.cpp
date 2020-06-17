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
#define eps 10e-9
#define NN 1000000


main()
{
    ios_base::sync_with_stdio(false);
    int t=1,tc;
    double x,y,z,u,w,xx,yy,zz,d;
    double ab,cd,ad,bc;
    cin>>tc;
    while(tc--)
    {
        cin>>ab>>cd>>ad>>bc;
        d=ab-cd;
        x=((ad*ad)-(bc*bc)+(d*d))/(2*d);
        y=d-x;

        double h=sqrt((ad*ad)-(x*x));
        double theta1=acos(x/ad);
        double theta2=acos(y/bc);
        double area=(cd+ab)*h*0.5;
        double low=0,high=h,mid;

        while(high-low>eps)
        {
            mid=(high+low)/2.0;
            xx=mid/(tan(theta1));
            yy=mid/(tan(theta2));
            double miniArea=(cd+cd+xx+yy)*mid*0.5;
            if(miniArea<area/2.0)
                low=mid;
            else
                high=mid;
        }
        xx=mid/(sin(theta1));
        yy=mid/(sin(theta2));
        x=ad-xx;
        y=bc-yy;
        printf("Land #%d: %.6lf %.6lf\n",t++,x,y);
    }
}
