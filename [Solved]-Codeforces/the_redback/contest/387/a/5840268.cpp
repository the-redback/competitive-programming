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
#define NN 1000000

vector<int>v;

int main()
{
    int i,j,k,l;
    int tc,t;
    int n,m,x,y;
    while(~scanf("%d:%d",&n,&m))
    {
        scanf("%d:%d",&x,&y);
        int flag=0;
        l=(m-y);
        if(l<0)
        {
            flag=1;
            l=60+l;
        }
        k=(n-x-flag);
        if(k<0)
            k=24+k;
        printf("%02d:%02d\n",k,l);

    }
    return 0;

}
