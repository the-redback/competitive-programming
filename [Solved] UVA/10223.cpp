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
#define inf 1000000000
#define NN 30

long long a[25];


int main()
{
    int i,j,k,l;
    int tc,t;
    int n,m;
    long long x,y,z;
    a[0]=0;
    a[1]=1;
    for(i=2;i<=20;i++)
    {
        x=a[i-1]*2*(2*i-1);
        a[i]=x/(i+1);
    }
    while(~scanf("%lld",&x))
    {
        for(i=0;i<20;i++)
        {
            if(a[i]<x && x<=a[i+1])
            {
                printf("%d\n",i+1);
                break;
            }
        }
    }
    return 0;
}
