/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : the_redback
 *    @link       : http://www.fb.com/maruf.2hin
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long llu;

#define ft        first
#define sd        second
#define mp        make_pair
#define pb(x)     push_back(x)
#define all(x)    x.begin(),x.end()
#define allr(x)   x.rbegin(),x.rend()
#define mem(a,b)  memset(a,b,sizeof(a))
#define meminf(a) memset(a,126,sizeof(a))
#define inf       1e11
#define eps       1e-9
#define mod       1000000007
#define NN        30100

//cout << setfill('0') << setw(3) << a << endl;
//cout << fixed << setprecision(20) << a << endl;

int viw[50][50];
char hor[50];
char ver[50];

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int n,m;

void dfs(int i,int j)
{
    viw[i][j]=1;
    for(int it=0;it<4;it++)
    {
        int x=i+dx[it];
        int y=j+dy[it];
        if(x<1 || y<1 || x>n || y>m)
            continue;
        if(hor[i-1]=='>' && y<j || hor[i-1]=='<' && y>j || ver[j-1]=='v' && x<i ||ver[j-1]=='^' && x>i  )
            continue;
        if(!viw[x][y])
            dfs(x,y);
    }
    return;
}

bool check(void)
{
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(!viw[i][j])
                return 1;
        }
    return 0;
}

main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;
    //cin>>tc;
    int i,j,k,l;
    while(cin>>n>>m)
    {
        scanf("%s",&hor);
        scanf("%s",&ver);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                mem(viw,0);
                dfs(i,j);
                if(check())
                {
                    puts("NO");
                    return 0;
                }
            }
        }
        puts("YES");
    }
    return 0;
}
