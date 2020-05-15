/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @Topcoder   : the_redback
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

#define ppb pop_back
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 1000000000
#define eps 1e-9
#define NN 200010

int a[NN][12];
int total[12];
int arr[NN][12];
int row[NN];

main()
{
    ios_base::sync_with_stdio(false);
    int t,tc;
    //cin>>tc;
    int n,m,q,r,i,j,k,l;
    while(cin>>n>>m>>q)
    {
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        mem(arr,0);
        mem(row,0);
        mem(total,0);
        for(i=0;i<q;i++)
        {
            cin>>k>>l;
            arr[k-1][l-1]++;
            total[l-1]++;
        }
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            {
                if(a[i][j]==1)
                {
                    row[i]+=total[j]-arr[i][j];
                }
            }
        for(i=0;i<n;i++)
        {
            if(i)
                printf(" ");
            printf("%d",row[i]);
        }
        puts("");
    }
    return 0;
}
