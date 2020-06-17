/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : the_redback
 *    @link       : maruf.2hin@gmail.com
 */
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<stack>
using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pp pop_back
#define inf 10000000
#define NN 100010


using namespace std;


int main()
{
    int np;
    string a[310];
    while(cin>>np)
    {
        for(int i=0; i<np; i++) cin>>a[i];
        char chr=a[0][0],chr2=a[0][1];
        if(chr==chr2)
        {
            cout<<"NO"<<endl;
            goto point;
        }
        for(int i=0; i<np; i++)
        {
            for(int j=0; j<np; j++)
            {
                if(j==i || j==np-i-1)
                {
                    if(a[i][j]!=chr)
                    {
                        cout<<"NO"<<endl;
                        goto point;
                    }
                }
                else
                {
                    if(a[i][j]!=chr2)
                    {
                        cout<<"NO"<<endl;
                        goto point;
                    }
                }
            }
        }
        cout<<"YES"<<endl;
point:
        continue;

    }
    return 0;
}
