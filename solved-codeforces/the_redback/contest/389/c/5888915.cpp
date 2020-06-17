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

int dx[]={1,1,1,2};
int dy[]={-1,0,1,0};
int a[111];
vector<int>v;

int main()
{
    int tc,t=1,ret=0;
    int i,j,k,l,r,cc;
    int n,m,x,y;
    while(~scanf("%d",&n))
    {
        mem(a,0);
        r=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        r=n;
        k=0;
        ret=1;
        sort(a,a+r);
        while(1)
        {
            j=0,cc=0,k=0;
            for(i=0;i<r;i++)
            {
                if(cc<=a[i])
                {
                    cc++;
                }
                else
                {
                    a[j]=a[i];
                    j++;
                    if(k==0)
                        ret++,k=1;
                }
            }
            if(k==0)
                break;
            r=j;
            sort(a,a+r);
        }
        printf("%d\n",ret);
    }
    return 0;
}
