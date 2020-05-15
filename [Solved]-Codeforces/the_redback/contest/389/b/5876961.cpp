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
char a[111][111];
vector<int>v;

int main()
{
    int tc,t=1,ret=0;
    int i,j,k,l,r;
    int n,m,x,y;
    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        {
            scanf("%s",&a[i]);
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[i][j]=='#')
                {
                    for(k=0;k<4;k++)
                    {
                        x=i+dx[k];
                        y=j+dy[k];
                        if(x<0||y<0||x>=n||y>=n)
                        {
                            printf("NO\n");
                            return 0;
                        }
                        else if(a[x][y]!='#')
                        {
                            printf("NO\n");
                            return 0;
                        }
                        a[x][y]='.';
                    }

                }

            }
        }
        printf("YES\n");
    }
    return 0;
}
