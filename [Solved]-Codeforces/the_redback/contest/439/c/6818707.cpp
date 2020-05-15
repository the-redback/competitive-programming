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
#define NN 400010

vector<int>evn,odd;

main()
{
    ios_base::sync_with_stdio(false);
    int t,tc;
    //cin>>tc;
    int i,j,k,l,n,m,p,x;

    while(cin>>n>>k>>p)
    {
        int ev,od;
        ev=od=0;
        for(i=0; i<n; i++)
        {
            cin>>x;
            if(x%2)
            {
                od++;
                odd.pb(x);
            }
            else
            {
                ev++;
                evn.pb(x);
            }
        }
        int aa,bb;
        bb=k-p;
        if(ev>p)
            aa=0;
        else
            aa=(p-ev)*2;
        if(od<(aa+bb) || (od-aa-bb)%2==1 )
        {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        j=l=0;
        for(i=0; i<p-1; i++)
        {
            if(j<evn.size())
                printf("1 %d\n",evn[j++]);
            else
                printf("2 %d %d\n",odd[l++],odd[l++]);
        }
        for(i=0; i<bb-1; i++)
        {
            printf("1 %d\n",odd[l++]);
        }
        if(bb==0||p==0)
        {
            int cc=evn.size()-j+odd.size()-l;
            printf("%d ",cc);
            while(j<evn.size())
            {
                printf("%d ",evn[j++]);
            }
            while(l<odd.size())
            {
                printf("%d ",odd[l++]);
            }
            printf("\n");
        }
        else
        {
            int cc=evn.size()-j;
            if(cc)
            {
                printf("%d ",cc);
                while(j<evn.size())
                {
                    printf("%d ",evn[j++]);
                }
            }
            else
            {
                printf("2 %d %d\n",odd[l++],odd[l++]);
            }

            printf("\n");
            cc=odd.size()-l;
            printf("%d ",cc);
            while(l<odd.size())
            {
                printf("%d ",odd[l++]);
            }
            printf("\n");
        }
    }
    return 0;
}
