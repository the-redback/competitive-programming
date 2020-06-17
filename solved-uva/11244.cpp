/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @TOPCODER   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : the_redback
 *    @link       : http://www.fb.com/maruf.2hin
 */
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};

main()
{
    char a[200][200];
    int n,m;
    while(scanf("%d %d",&n,&m)==2)
    {
        if(n==0 && m==0)
            return 0;
        getchar();
        for(int i=0;i<n;i++)
            gets(a[i]);
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]=='*')
                {
                    int flag=0;
                    for(int k=0;k<8;k++)
                    {
                        int x=i+dx[k];
                        int y=j+dy[k];
                        if(x>=0 && y>=0 && x<n && y<m && a[x][y]=='*')
                            flag=1;
                    }
                    if(flag==0)
                        count++;
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
