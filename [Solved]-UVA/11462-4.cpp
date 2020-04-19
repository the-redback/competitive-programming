/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @Codeforces : the_redback
 *    @UVA        : Redback
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
#define inf HUGE_VAL
#define mem(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
int a[2000001];
main()
{
    ios_base::sync_with_stdio(false);
    int i,j,n,size;
    while(cin>>n)
    {
        if(n==0)
        {
            break;
        }
        j=0;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        for (int i = 0; i < n; i++)
        {
            if(j!=0)
            {
                cout<<" ";
            }
            cout<<a[i];
            j=1;
        }
        cout<<"\n";
    }
}
