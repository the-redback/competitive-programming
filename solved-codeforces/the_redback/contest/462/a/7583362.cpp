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
#define NN        301

//cout << setfill('0') << setw(3) << a << endl;
//cout << fixed << setprecision(20) << a << endl;

char a[NN][NN];
int b[NN][NN];

int dx[]= {-1,0,1,0};
int dy[]= {0,-1,0,1};

main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1,tc;

    ll i,j,k,l,m,n,ii,jj;
    cin>>n;
    for(i=0; i<n; i++)
        scanf("%s",&a[i]);
    mem(b,0);
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            for(ii=0; ii<4; ii++ )
            {
                int x=i+dx[ii];
                int y=j+dy[ii];
                if(x<0||y<0||x>=n||y>=n)
                    continue;
                if(a[x][y]=='o')
                    b[i][j]++;
            }
        }
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(b[i][j]%2!=0)
            {
                puts("NO");
                return 0;
            }
        }

    }
    puts("YES");

    return 0;
}
