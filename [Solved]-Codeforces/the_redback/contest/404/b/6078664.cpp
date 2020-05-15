/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : the_redback
 *    @link       : maruf.2hin@gmail.com
 */
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<stack>
using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pp pop_back
#define inf 10000000
#define NN 100010
int main()
{
    double a,d,xxx,yyy;
    int n,i,roun;
    scanf("%lf %lf %d",&a,&d,&n);
    double len=d*1;
    for(i=1;i<=n;i++)
    {

         roun=len/(a*4);

        len=len-(roun*4*a);
       // cout<<len<<endl;
       // cout<<len;
        if(len>=0.0&&len<=a)
        {
            xxx=len;
            yyy=0.0;
        }
        else if(len>a&&len<=(2*a))
        {
            yyy=len-(a*1.0);
            xxx=a;

        }
        else if(len>(2*a)&&len<=(3*a))
        {
            xxx=len-(a*2.0);
            xxx=a-xxx;
            yyy=a;

        }
        else
        {
            xxx=0.0;
            yyy=len-(a*3.0);
            yyy=a-yyy;

        }

            printf("%.11lf %.11lf\n",xxx,yyy);
            len+=d;
    }
    return 0;
}
