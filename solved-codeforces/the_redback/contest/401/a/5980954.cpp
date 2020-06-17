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

#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pp pop_back
#define inf 10000000
#define NN 2000100

using namespace std;


int main()
{
    int r,z,q,result;

    while(cin>>r>>z)
    {
        result=0;
        for(int i=0; i<r; i++)
        {
            cin>>q;
            result+=q;
        }
        if(result==0) cout<<0<<endl;
        else if(abs(result)<=z) cout<<1<<endl;
        else
        {
            q=abs(result);
            int countt=q/z;
            if(q%z) countt++;
            cout<<countt<<endl;
        }
    }
    return 0;
}
