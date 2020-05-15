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

int gcd(int a,int b)
{
    while(b>0)
    {
        a=a%b;
        swap(a,b);
    }
    return a;
}

vector<int>v;

int main()
{
    int tc,t=1,ret=0;
    int i,j,k,l,r;
    int n,m;
    int a[111];
    while(~scanf("%d",&n))
    {
        scanf("%d",&ret);
        for(i=1;i<n;i++)
        {
            scanf("%d",&k);
            ret=gcd(ret,k);
        }
        ret*=n;
        printf("%d\n",ret);
    }
    return 0;
}
