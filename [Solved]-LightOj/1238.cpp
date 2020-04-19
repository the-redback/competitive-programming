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
#define NN 20

char a[NN+7][NN+7];
int view[NN+7][NN+7];
queue<int>x,y;
int N,M;
int dx[]={0,-1,0,1};
int dy[]={-1,0,1,0};

int call(int i,int j)
{
    x=queue<int>();
    y=queue<int>();
    int k,r;
    view[i][j]=0;
    x.push(i);
    y.push(j);
    while(x.size())
    {
        i=x.front();
        j=y.front();
        x.pop(),y.pop();
        for(k=0;k<4;k++)
        {
            int xx=i+dx[k];
            int yy=j+dy[k];
            if(xx<0||yy<0||xx>=N||yy>=M||a[xx][yy]=='#'||a[xx][yy]=='m'||view[xx][yy]!=-1)
                continue;
            view[xx][yy]=view[i][j]+1;
            x.push(xx);
            y.push(yy);
            if(a[xx][yy]=='h')
                return view[xx][yy];
        }
    }
    return 0;
}

int main()
{
    int tc,t=1,res=0;
    int i,cc,n,k,r,j;
    int u,v,w;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d%d",&N,&M);
        for(i=0;i<N;i++)
            scanf("%s",&a[i]);
        res=-inf;
        k=0;
        for(i=0;i<N && k<3 ;i++)
            for(j=0;j<M && k<3;j++)
            {
                if(a[i][j]=='a'||a[i][j]=='b'||a[i][j]=='c')
                {
                    mem(view,-1);
                    k++;
                    res=max(res,call(i,j));
                }
            }
        printf("Case %d: %d\n",t++,res);
    }
    return 0;
}
