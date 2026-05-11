/**
 *                                   ____
 *       ____ ___  ____ ________  __/ __/
 *      / __ `__ \/ __ `/ ___/ / / / /_
 *     / / / / / / /_/ / /  / /_/ / __/
 *    /_/ /_/ /_/\__,_/_/   \__,_/_/
 *
 *    @link : https://the-redback.com
 */
#include <bits/stdc++.h>
using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pp pop_back
#define inf 10000000
#define NN 2000100
int mrf[4005];

int main()
{
    int q,r,ii,jj,i,tc,kk,maxx,minn;

    while(cin>>q>>r)
    {
        mem(mrf,0);
        maxx=minn=0;

        if(r==0)
        {
            cout<<ceil(q/2)<<" "<<q-1<<endl;
            continue;
        }

        for(i=0; i<r; i++)
        {
            cin>>ii;
            if(ii==1)
            {
                cin>>jj>>kk;
                mrf[jj]=2;
                mrf[kk]=1;
            }
            else
            {
                cin>>jj;
                mrf[jj]=2;
            }
        }

        for(int i=1; i<q; i++)
        {
            if(mrf[i]==0)
                maxx++;
        }

        int tc=0;

        for(i=1; i<q; i++)
        {
            if(mrf[i]==0)
            {
               if(tc==0) minn++,mrf[i]=2,tc=1;
               else mrf[i]=1,tc=0;
            }
            else if(mrf[i]==2) tc=0;
            else tc=0;
        }
        cout<<minn<<" "<<maxx<<endl;
    }
    return 0;
}
